#include "viewpassword.h"
#include "ui_viewpassword.h"
#include "mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QLabel>
#include "passwordTools.h"
#include "ui_mainwindow.h"
#define Path_to_DB "passwords.db"

viewPassword::viewPassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewPassword)
{
    ui->setupUi(this);

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
}

viewPassword::~viewPassword()
{
    delete ui;
}

void viewPassword::setName(QString Name)
{
    ui->label_9->setText(Name);
}

void viewPassword::setUsername(QString Username)
{
    ui->lineEdit_2->setText(Username);
}

void viewPassword::setPassword(QString Password)
{
    ui->lineEdit_3->setText(Password);
    ui->lineEdit_3->setReadOnly(true);
}

void viewPassword::setDescription(QString Description)
{
    ui->textEdit->setText(Description);
}

void viewPassword::on_checkBox_toggled(bool checked)
{
    if (checked)
    {
        ui->lineEdit_3->setEchoMode(QLineEdit::EchoMode());
    } else {
        ui->lineEdit_3->setEchoMode(QLineEdit::Password);
    }
}

void viewPassword::on_pushButton_clicked()
{
    QString Name = ui->label_9->text();
    QString oldPassword = ui->lineEdit_2->text();
    QString newPassword = ui->lineEdit_5->text();
    QString vNewPassword = ui->lineEdit_6->text();

    if (newPassword.isNull() || newPassword.isEmpty())
    {
        QMessageBox::warning(this, "Error!", "New password cannot be empty.");
    }
    else if (newPassword == oldPassword)
    {
        QMessageBox::warning(this, "Error!", "Your old and new passwords are the same.");
    }
    else if (newPassword != vNewPassword)
    {
        QMessageBox::warning(this, "Error!", "New password does not match with verifier.");
    } else {
        editPassword(Name, newPassword);
    }
}

void viewPassword::editPassword(QString Name, QString newPassword)
{
    QSqlQuery qry;

    qry.exec("UPDATE passwords SET password ='" + newPassword + "' WHERE username ='" + Username + "'AND name ='" + Name + "'");
    this->close();
}
