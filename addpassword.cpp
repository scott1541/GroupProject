#include "addpassword.h"
#include "ui_addpassword.h"
#include "startmenu.h"
#include "mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QLabel>
#include "password.h"
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
            qDebug() << "[+] Connected To Database!";
        }

    }else{
            qDebug() << "[!] Database File Not Found.";
    }

}

addPassword::~addPassword()
{
    delete ui;
}

void addPassword::on_lineEdit_3_textEdited(const QString &arg1)
{

    getPasswordStrength();

    //ui->lineEdit_3->setEchoMode(QLineEdit::Password);

//    if (Creation)
//    {
//            getPasswordStrength();
//    }


//    void addPassword::getPasswordStrength()
//    {
//            QString paswd = ui->lineEdit_3->text();
//            password *ps = new password();
//            int passBits = ps->passWord(paswd);
//            ui->progressBar->setValue(passBits);
//            QString output = QString::number(passBits);
//            //ui->label_11->setText(getDesc(passBits));
//            QString passDesc = "";
//            if (passBits > 0)
//                    ui->label_11->show();
//            if (passBits < 20)
//                    passDesc = "Very weak";
//            if (passBits > 19 && passBits < 30)
//                    passDesc = "Relatively weak";
//            if (passBits > 29 && passBits < 50)
//                    passDesc = "Moderately strong";
//            if (passBits > 49 && passBits < 70)
//                    passDesc = "Strong";
//            if (passBits > 69)
//                    passDesc = "Very Strong";
//            if (passBits <= 0){
//                    ui->progressBar->setValue(0),
//                            ui->label_8->hide();
//            }
//            ui->label_8->setText(passDesc);
//    }
}

void addPassword::on_lineEdit_5_textEdited(const QString &arg1)
{
   // ui->lineEdit_5->setEchoMode(QLineEdit::Password);
}

void addPassword::addNewPassword()
{
    QString Password = ui->lineEdit_3->text();
    QString UsernameID = ui->lineEdit_2->text();
    QString Name = ui->lineEdit->text();
    QString Description = ui->textEdit->toPlainText();

    QString queryString = "INSERT INTO passwords (username, name, usernameID, password, description) VALUES (?,?,?,?,?)";
    QSqlQuery qry(queryString);
    qry.addBindValue(Username);
    qry.addBindValue(Name);
    qry.addBindValue(UsernameID);
    qry.addBindValue(Password);
    qry.addBindValue(Description);
    qry.exec();
}

void addPassword::on_pushButton_clicked(bool checked)
{

    QString Password = ui->lineEdit_3->text();
    QString PasswordV = ui->lineEdit_5->text();
    QString UsernameID = ui->lineEdit_2->text();
    QString Name = ui->lineEdit->text();

    if (Name.isEmpty() || UsernameID.isEmpty() || Password.isEmpty())
    {
        QMessageBox::warning(this, "Error!", "You have missed a field.");
    }
    else if (Password!= PasswordV)
    {
        QMessageBox::warning(this, "Error!", "Passwords do not match");
    } else {
        addNewPassword();
        MainWindow *m = new MainWindow;
        m->showPasswords();
        this->close();
    }

}

void addPassword::getPasswordStrength()
{
        QString paswd = ui->lineEdit_3->text();
        password *ps = new password();
        int passBits = ps->passWord(paswd);
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
