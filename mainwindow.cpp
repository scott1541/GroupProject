#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include "startmenu.h"
#include "qgrostlhash.h"
#include "password.h"
#include "addpassword.h"
#include "viewpassword.h"
#include "changepassword.h"

#define Path_to_DB "passwords.db"

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
                delete ui->treeWidget->currentItem();
            }
}
