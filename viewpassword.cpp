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

    QString Name = ui->label_9->text();

    QSqlQuery qry;
    QByteArray keyB;

    if (qry.exec("SELECT key FROM passwords WHERE username = '" + Username + "' AND name = '" + Name + "'"))
    {
        while (qry.next())
        {
            keyB = qry.value("key").toByteArray();
        }
    }
    //qDebug() << keyB;

    char* theKey = keyB.data();
    qDebug() << theKey;
    QByteArray ba = Password.toUtf8();
    //qDebug() << ba;
    char *cPassword = ba.data();

    TwofishKey *myKey = (reinterpret_cast<TwofishKey*>(theKey));
    Password = pt->decryptPassword(cPassword, myKey);

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
     getPasswordStrength();

}
