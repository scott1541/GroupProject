#include "addpassword.h"
#include "ui_addpassword.h"
#include "startmenu.h"
#include "mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QLabel>
#include <iostream>
#define Path_to_DB "passwords.db"

addPassword::addPassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addPassword)
{
    ui->setupUi(this);

    myDB = QSqlDatabase::addDatabase("QSQLITE");
    myDB.setDatabaseName(Path_to_DB);
    QFileInfo checkFile(Path_to_DB);

    if (checkFile.isFile())
    {
        if(myDB.open())
        {
            //qDebug() << "[+] Connected To Database!";
        }

    }else{
            //qDebug() << "[!] Database File Not Found.";
    }

    on_lineEdit_3_textEdited(NULL);

}

addPassword::~addPassword()
{
    delete ui;
}

void addPassword::on_lineEdit_3_textEdited(const QString &arg1)
{

    getPasswordStrength();
    passwordTools *pt = new passwordTools();
    QString Recommend = pt->passwordRecommender(ui->lineEdit_3->text());
    //QString Recommend = (char*)recommend;
    ui->label_9->setText(Recommend);

}

void addPassword::on_lineEdit_5_textEdited(const QString &arg1)
{
   // ui->lineEdit_5->setEchoMode(QLineEdit::Password);
}

void addPassword::addNewPassword()
{
    passwordTools *pt = new passwordTools();


    QString Password = ui->lineEdit_3->text();
    //qDebug() << "You stored the password: " << Password << " which has the length of" << Password.length();
    int Strength = pt->passwordEntropy(Password);
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
    QString UsernameID = ui->lineEdit_2->text();
    QString Name = ui->lineEdit->text();
    QString Description = ui->textEdit->toPlainText();

    QString Key = pt->passwordGenerator();
    //qDebug() << "Key used: " << Key;

    QString Encrypted = pt->encryptPassword(Password, Key);
    //qDebug() << "Password after encryption: " << Encrypted;
    //qDebug() << "Password strength is: " << Strength;

    //qDebug() << passwordEncrypted;
    QString queryString = "INSERT INTO passwords (username, name, usernameID, password, description, key, length, strength) VALUES (?,?,?,?,?,?,?,?)";
    QSqlQuery qry(queryString);
    qry.addBindValue(Username);
    qry.addBindValue(Name);
    qry.addBindValue(UsernameID);
    qry.addBindValue(Encrypted);
    qry.addBindValue(Description);
    qry.addBindValue(Key);
    qry.addBindValue(Password.length());
    qry.addBindValue(qStrength);
    qry.exec();
}

void addPassword::on_pushButton_clicked(bool checked)
{

    QString Password = ui->lineEdit_3->text();
    QString PasswordV = ui->lineEdit_5->text();
    QString UsernameID = ui->lineEdit_2->text();
    QString Name = ui->lineEdit->text();

    QSqlQuery nameUse;

    bool validName;

    if (nameUse.exec("SELECT name FROM passwords WHERE name = '" + Name + "' AND username = '" + Username + "'"))
    {
        if (nameUse.next())
        {
            validName = false;
            //qDebug() << "Name " + Name + " is in use";
        } else {
            validName = true;
            //qDebug() << "Name " + Name + " is available";
        }
    }

    if (Name.isEmpty() || UsernameID.isEmpty() || Password.isEmpty())
    {
        QMessageBox::warning(this, "Error!", "You have missed a field.");
    }
    else if (Password!= PasswordV)
    {
        QMessageBox::warning(this, "Error!", "Passwords do not match");
    }
    else if (!validName)
    {
        QMessageBox::warning(this, "Error", "You are already using this name for a password");
    } else {
        addNewPassword();
        mainWin->showPasswords();
        this->close();
    }

}

void addPassword::getPasswordStrength()
{
        QString paswd = ui->lineEdit_3->text();
        passwordTools *ps = new passwordTools();
        int passBits = ps->passwordEntropy(paswd);
        ui->progressBar->setValue(passBits);
}

void addPassword::on_pushButton_2_pressed()
{
    passwordTools *p = new passwordTools();

    QString Password = p->passwordGenerator();
    qDebug() << Password;

    ui->lineEdit_3->setText(Password);
    ui->lineEdit_5->setText(Password);
    getPasswordStrength();
}

void addPassword::on_checkBox_toggled(bool checked)
{
    if (checked)
    {
        ui->lineEdit_3->setEchoMode(QLineEdit::EchoMode());
    } else {
        ui->lineEdit_3->setEchoMode(QLineEdit::Password);
    }
}

void addPassword::on_pushButton_3_clicked()
{
    this->close();
}

