#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include "startmenu.h"
#include "qgrostlhash.h"
#include "passwordTools.h"
#include "addpassword.h"
#include "viewpassword.h"
#include "changepassword.h"
#include "sqlite3.h"
#include <exception>
#include <iostream>
#include "botanwrapper.h"

#define Path_to_DB "passwords.db"
#define Path_to_Login "login.db"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    showPasswords();

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionAbout_SecureShield_triggered()
{
    QMessageBox::information(this, "About Secure Shield", "Secure Shield\
                                        Created and Developed by Lewis Yates, Scott Pollard and Carl Mansfield.\
                                        Open-Source Password Management Software aiding the good practice of cyber security. March 2015.");
}

void MainWindow::on_actionShow_Toolbar_triggered(bool isTriggered)
{
    if (isTriggered)
    {
        ui->toolBar->show();
    }
    else
    {
        ui->toolBar->hide();
    }
}



void MainWindow::on_actionSecurity_2_triggered()
{

}

void MainWindow::on_actionQuit_SecureShield_triggered()
{
    close();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionFormat_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_action_Cut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    viewPassword *view = new viewPassword();
    QString Name = item->text(0);
    QString Username = item->text(1);
    //QString Password = item->text(2);
    QString Description = item->text(4);
    view->setName(Name);
    view->setUsername(Username);
    view->passwordName = Name;
    view->setPassword(Name);
    view->setDescription(Description);
    view->setWindowTitle("Secure Shield: " + Name);
    view->mainWin = this;
    view->show();
}

void MainWindow::on_action_Redo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_action_Undo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::showPasswords()
{
    ui->treeWidget->clear();
    myDB = QSqlDatabase::addDatabase("QSQLITE");
    myDB.setDatabaseName(Path_to_DB);
    QFileInfo checkFile(Path_to_DB);

    if (checkFile.isFile())
    {
        if(myDB.open())
        {
            qDebug() << "[+] Connected To Database!";
        }

    }else{
            qDebug() << "[!] Database File Not Found.";
            sqlite3 *newDB;
            sqlite3_open("passwords.db", &newDB);

            std::string createTable = "CREATE TABLE passwords(username VARCHAR(20), name VARCHAR(20), usernameID VARCHAR(30), "
                                      "password VARCHAR(64), dateadded DATETIME DEFAULT current_timestamp, description TEXT,"
                                      "key VARCHAR(32), url VARCHAR(64), length INTEGER, strength CHAR(1))";
            sqlite3_stmt *createStmt;
            qDebug() << "Creating Table Statement";
            sqlite3_prepare(newDB, createTable.c_str(), createTable.size(), &createStmt, NULL);
            if (sqlite3_step(createStmt) != SQLITE_DONE) qDebug() << "Didn't Create Table!";
    }

    QSqlQuery qry;
    passwordTools *pt = new passwordTools();

    if (qry.exec("SELECT * FROM passwords WHERE username = '" + Username + "'"))
    {
        while (qry.next())
        {
            QString qStrength = qry.value("strength").toString();
            int length = qry.value("length").toInt();


            QTreeWidgetItem *item = new QTreeWidgetItem();
            item->setText(0, qry.value("name").toString());
            item->setText(1, qry.value("usernameID").toString());
            //item->setText(2, Password);
            item->setText(3, qry.value("dateadded").toString());
            item->setText(4, qry.value("description").toString());
            //int Strength = pt->passwordEntropy(Password);

            if (qStrength == "w")
            {
                item->setText(5, "");
                item->setIcon(5, QIcon("red.gif"));
            }
            else if (qStrength == "x")
            {
                item->setText(5, " ");
                item->setIcon(5, QIcon("orange.png"));
            }
            else if (qStrength == "y")
            {
                item->setText(5, "  ");
                item->setIcon(5, QIcon("green.png"));
            }
            QString censored;
            //qDebug() << "The length of the password stored was: " << length;
            for (int i = 0; i < length; i++)
            {
                //qDebug() << "We need " << i + 1 << "asterisks to display";
                censored = censored + "*";
            }
            //qDebug() << censored << " is what will be displayed in the application";
            item->setText(2, censored);
            ui->treeWidget->addTopLevelItem(item);
        }
    }


    ui->treeWidget->setSortingEnabled(true);

}

void MainWindow::on_actionAddEntry_triggered()
{
    addPassword *ap = new addPassword();
    ap->mainWin = this;
    ap->show();
}


void MainWindow::on_actionChange_Password_triggered()
{
    ChangePassword *chPass = new ChangePassword;
    chPass->show();
}

void MainWindow::searchPasswords(QString Word)
{
    ui->treeWidget->clear();
    myDB = QSqlDatabase::addDatabase("QSQLITE");
    myDB.setDatabaseName(Path_to_DB);
    QFileInfo checkFile(Path_to_DB);

    if (checkFile.isFile())
    {
        if(myDB.open())
        {
            qDebug() << "[+] Connected To Database!";
        }

    }else{
            qDebug() << "[!] Database File Not Found.";
    }

    QSqlQuery qry;
    passwordTools *pt = new passwordTools();

    if (qry.exec("SELECT * FROM passwords WHERE username = '" + Username + "'AND name LIKE '" + Word + "'"))
    {
        while (qry.next())
        {
            QString qStrength = qry.value("strength").toString();
            int length = qry.value("length").toInt();


            QTreeWidgetItem *item = new QTreeWidgetItem();
            item->setText(0, qry.value("name").toString());
            item->setText(1, qry.value("usernameID").toString());
            //item->setText(2, Password);
            item->setText(3, qry.value("dateadded").toString());
            item->setText(4, qry.value("description").toString());
            //int Strength = pt->passwordEntropy(Password);

            if (qStrength == "w")
            {
                item->setText(5, "");
                item->setIcon(5, QIcon("red.gif"));
            }
            else if (qStrength == "x")
            {
                item->setText(5, " ");
                item->setIcon(5, QIcon("orange.png"));
            }
            else if (qStrength == "y")
            {
                item->setText(5, "  ");
                item->setIcon(5, QIcon("green.png"));
            }
            QString censored;
            for (int i = 0; i < length; i++)
            {
                censored = censored + "*";
            }
            item->setText(2, censored);
            ui->treeWidget->addTopLevelItem(item);
        }
    }
}


void MainWindow::on_textEdit_textChanged()
{
    QString Word;
    Word = ui->textEdit->toPlainText();
    Word = '%' + Word + '%';

    searchPasswords(Word);
}



void MainWindow::on_actionDeleteEntry_triggered()
{

    bool empty = ui->treeWidget->isItemSelected(ui->treeWidget->currentItem());
    //qDebug() << empty;

    if (empty)
    {

            QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("Confirmation");
            msgBox->setText("Are You Sure You Want To Remove This Entry?");

            QPushButton *yesButton = msgBox->addButton(tr("Yes"), QMessageBox::ActionRole);
            msgBox->addButton(tr("No"), QMessageBox::ActionRole);
            msgBox->exec();



            if ((QPushButton*)msgBox->clickedButton() == yesButton)
            {
                QString Name = ui->treeWidget->currentItem()->text(0);
                QSqlQuery qry;
                qry.exec("DELETE FROM passwords WHERE username ='" + Username + "'AND name ='" + Name + "'");
                showPasswords();
            }
    } else {
        QMessageBox::warning(this, "Error!", "You have not selected a password!");
    }
}

void MainWindow::on_actionRemove_All_Data_triggered()
{
    QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("Confirmation");
            msgBox->setText("Are You Sure You Want To Remove All Data?");

            QPushButton *yesButton = msgBox->addButton(tr("Yes"), QMessageBox::ActionRole);
            msgBox->addButton(tr("No"), QMessageBox::ActionRole);
            msgBox->exec();

            if ((QPushButton*)msgBox->clickedButton() == yesButton)
            {
                QSqlQuery qry;
                qry.exec("DELETE FROM passwords WHERE username='" + Username
                         + "'");
                showPasswords();
            }
}

void MainWindow::on_actionDelete_Account_triggered()
{

    QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("Confirmation");
            msgBox->setText("Are You Sure You Want To Close This Account?");

            QPushButton *yesButton = msgBox->addButton(tr("Yes"), QMessageBox::ActionRole);
            msgBox->addButton(tr("No"), QMessageBox::ActionRole);
            msgBox->exec();

            if ((QPushButton*)msgBox->clickedButton() == yesButton)
            {
                myDB = QSqlDatabase::addDatabase("QSQLITE");
                myDB.setDatabaseName(Path_to_Login);
                QFileInfo checkFile(Path_to_Login);

                if (checkFile.isFile())
                {
                    if(myDB.open())
                    {
                        //qDebug() << "[+] Connected To Database!";
                    }

                }else{
                        //qDebug() << "[!] Database File Not Found.";
                    }
                QSqlQuery qry;
                qry.exec("DELETE FROM user WHERE username='" + Username + "'");
                myDB.close();
                myDB.setDatabaseName(Path_to_DB);
                QFileInfo checkLoginFile(Path_to_DB);

                if (checkLoginFile.isFile())
                {
                    if(myDB.open())
                    {
                        //qDebug() << "[+] Connected To Database!";
                    }

                }else{
                        //qDebug() << "[!] Database File Not Found.";
                }

                qry.exec("DELETE FROM passwords WHERE username='" + Username + "'");
                myDB.close();
                this->close();
                startmenu *sm = new startmenu;
                sm->show();
            }


}

void MainWindow::on_actionLog_Out_2_triggered()
{
    QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("Confirmation");
            msgBox->setText("Are You Sure You Want To Log Out?");

            QPushButton *yesButton = msgBox->addButton(tr("Yes"), QMessageBox::ActionRole);
            msgBox->addButton(tr("No"), QMessageBox::ActionRole);
            msgBox->exec();

            if ((QPushButton*)msgBox->clickedButton() == yesButton)
            {
                this->close();
                startmenu *logOut = new startmenu;
                logOut->show();
            }
}

void MainWindow::on_actionEditEntry_triggered()
{
    QTreeWidgetItem *item = ui->treeWidget->currentItem();
    bool empty = ui->treeWidget->isItemSelected(ui->treeWidget->currentItem());

    if (empty)
    {
        viewPassword *view = new viewPassword();
        QString Name = item->text(0);
        QString Username = item->text(1);
        QString Password = item->text(2);
        QString Description = item->text(4);
        view->setName(Name);
        view->setUsername(Username);
        //view->setPassword(Password);
        view->setDescription(Description);
        view->setWindowTitle("Secure Shield: " + Name);
        view->mainWin = this;
        view->show();
    } else {
        QMessageBox::warning(this, "Error", "You have not selected a password to view.");
    }

}
