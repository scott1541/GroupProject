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
#include "twofish.h"

#define Path_to_DB "passwords.db"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    showPasswords();

    Twofish_Byte word [16];
    Twofish_Byte encryptedword [16];

    Twofish *twofish = new Twofish();
    TwofishKey *key = new TwofishKey();
    Twofish_Byte byte [32];

    twofish->PrepareKey(byte, 16, key);
    qDebug() << key;

    twofish->Encrypt(key, word, encryptedword);
    qDebug() << encryptedword;

    Twofish_Byte decrypted[16];

    twofish->Decrypt(key, encryptedword, decrypted);
    qDebug() << decrypted;

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
    view->show();
    QString Name = item->text(0);
    QString Username = item->text(1);
    QString Password = item->text(2);
    QString Description = item->text(4);
    view->setName(Name);
    view->setUsername(Username);
    view->setPassword(Password);
    view->setDescription(Description);
    view->setWindowTitle("Secure Shield: " + Name);
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
    }

    QSqlQuery qry;

    if (qry.exec("SELECT * FROM passwords WHERE username = '" + Username + "'"))
    {
        while (qry.next())
        {
            QTreeWidgetItem *item = new QTreeWidgetItem();
            item->setText(0, qry.value("name").toString());
            item->setText(1, qry.value("usernameID").toString());
            item->setText(2, qry.value("password").toString());
            item->setText(3, qry.value("dateadded").toString());
            item->setText(4, qry.value("description").toString());

            QString Password = qry.value("password").toString();
            passwordTools *p = new passwordTools();
            int Strength = p->passwordEntropy(Password);

            if (Strength <= 25)
            {
                item->setIcon(5, QIcon("red.gif"));
            }
            else if (Strength > 25 && Strength <= 75)
            {
                item->setIcon(5, QIcon("orange.png"));
            }
            else if (Strength > 75)
            {
                item->setIcon(5, QIcon("green.png"));
            }
            //qDebug() << qry.value("username").toString();
            ui->treeWidget->addTopLevelItem(item);
        }
    }
}

void MainWindow::on_actionAddEntry_triggered()
{
    addPassword *ap = new addPassword();
    ap->show();
}

void MainWindow::on_actionEditEntry_triggered()
{
    showPasswords();
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

    if (qry.exec("SELECT * FROM passwords WHERE username = '" + Username + "'AND name LIKE '" + Word + "'"))
    {
        while (qry.next())
        {
            QTreeWidgetItem *item = new QTreeWidgetItem();
            item->setText(0, qry.value("name").toString());
            item->setText(1, qry.value("usernameID").toString());
            item->setText(2, qry.value("password").toString());
            item->setText(3, qry.value("dateadded").toString());
            item->setText(4, qry.value("description").toString());
            //qDebug() << qry.value("username").toString();
            QString Password = qry.value("password").toString();
            passwordTools *p = new passwordTools();
            int Strength = p->passwordEntropy(Password);

            if (Strength <= 25)
            {
                item->setIcon(5, QIcon("red.gif"));
            }
            else if (Strength > 25 && Strength <= 75)
            {
                item->setIcon(5, QIcon("orange.png"));
            }
            else if (Strength > 75)
            {
                item->setIcon(5, QIcon("green.png"));
            }


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
                delete ui->treeWidget->currentItem();
            }
}
