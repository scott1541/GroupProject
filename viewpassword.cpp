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
    passwordTools *pt = new passwordTools();
    QSqlQuery qry;

    if (qry.exec("SELECT password FROM passwords WHERE username = '" + Username + "' AND name = '" + Password + "'"))
    {
        while (qry.next())
        {
            Password = qry.value("password").toString();
        }
    }

    QString Name = ui->label_9->text();

    QString Key;

    if (qry.exec("SELECT key FROM passwords WHERE username = '" + Username + "' AND name = '" + Name + "'"))
    {
        while (qry.next())
        {
            Key = qry.value("key").toString();
        }
    }

    Password = pt->decryptPassword(Password, Key);

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
    passwordTools *pt = new passwordTools();
    int Strength = pt->passwordEntropy(newPassword);
    QString qStrength;
    if (Strength <= 25)
    {
        qStrength = "w";
    }
    else if (Strength > 25 && Strength <= 75)
    {
        qStrength = "x";
    }
    else if (Strength > 75)
    {
        qStrength = "y";
    }

    QString Description = ui->textEdit->toPlainText();
    QString UsernameID = ui->lineEdit_2->text();

    QString Key = pt->passwordGenerator();
    qDebug() << Key;
    int length = newPassword.length();
    QString qLength = QString::number(length);

    //newPassword = pt->encryptPassword(newPassword, Key);
    QString Password = pt->encryptPassword(newPassword, Key);
    //qDebug() << newPassword;
    qry.exec("UPDATE passwords SET password ='" + Password + "', usernameID ='" + UsernameID + "', description ='" + Description + "', key ='" + Key + "', length =" + qLength + ", strength ='" + qStrength + "' WHERE username ='" + Username + "'AND name ='" + Name + "'");
    mainWin->showPasswords();
    this->close();
}

void viewPassword::on_pushButton_2_clicked()
{
    this->close();
}

void viewPassword::getPasswordStrength()
{
        QString paswd = ui->lineEdit_5->text();
        passwordTools *ps = new passwordTools();
        int passBits = ps->passwordEntropy(paswd);
        ui->progressBar->setValue(passBits);
        //QString output = QString::number(passBits);
        //ui->label_11->setText(getDesc(passBits));
        /*QString passDesc = "";
        if (passBits > 0)
                ui->label_11->show();
        if (passBits < 20)
                passDesc = "Very weak";
        if (passBits > 19 && passBits < 30)
                passDesc = "Relatively weak";
        if (passBits > 29 && passBits < 50)
                passDesc = "Moderately strong";
        if (passBits > 49 && passBits < 70)
                passDesc = "Strong";
        if (passBits > 69)
                passDesc = "Very Strong";
        if (passBits <= 0){
                ui->progressBar->setValue(0),
                        ui->label_11->hide();
        }
        ui->label_11->setText(passDesc);*/
}

void viewPassword::on_pushButton_3_pressed()
{

     passwordTools *p = new passwordTools();

     QString Password = p->passwordGenerator();
     qDebug() << Password;

     ui->lineEdit_5->setText(Password);
     ui->lineEdit_6->setText(Password);
     on_lineEdit_5_textEdited(NULL);

}

void viewPassword::on_lineEdit_5_textEdited(const QString &arg1)
{
    getPasswordStrength();
    passwordTools *pt = new passwordTools();
    QString Recommend = pt->passwordRecommender(ui->lineEdit_5->text());
    ui->label_11->setText(Recommend);
}

void viewPassword::on_checkBox_2_clicked(bool checked)
{
    if (checked)
    {
        ui->lineEdit_5->setEchoMode(QLineEdit::EchoMode());
    } else {
        ui->lineEdit_5->setEchoMode(QLineEdit::Password);
    }
}
