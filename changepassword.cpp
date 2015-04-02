#include "changepassword.h"
#include "ui_changepassword.h"
#include "startmenu.h"
#include "qgrostlhash.h"
#include "qmessagebox.h"
#include "passwordTools.h"
#define Path_to_DB "login.db"

QString oPassword;
QString nPassword;
QString vPassword;
bool PasswordIsNtEmpty = false;

ChangePassword::ChangePassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangePassword)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);

}

ChangePassword::~ChangePassword()
{
    delete ui;
}

void ChangePassword::on_lineEdit_textEdited(const QString &arg1)
{
    oPassword = ui->lineEdit->text();
}


void ChangePassword::on_lineEdit_2_textEdited(const QString &arg1)
{
    nPassword = ui->lineEdit_2->text();

    getPasswordStrength();
}

void ChangePassword::on_pushButton_clicked() //OK button
{
    if (nPassword.isEmpty() || nPassword.isNull())
    {
        PasswordIsNtEmpty = false;
    }
    else
        PasswordIsNtEmpty = true;


    if (PasswordIsNtEmpty == true) //If password isn't empty
    {

        if (nPassword == vPassword) //If new and verify passwords match
        {
            QString UsernameS = Username;
            UsernameS.resize(4);
            oPassword = UsernameS + nPassword;
            oPassword = QGrostlHash(nPassword).toHexString();

            QSqlQuery qry1;
            if (qry1.exec("SELECT username, password FROM user WHERE username=\'" + Username
                    + "\' AND password=\'" + oPassword + "\'"))
            {
                    if (qry1.next())
                    {
                        QMessageBox::information(NULL, "Hi", "Query successful...");

                        nPassword = UsernameS + nPassword;
                        nPassword = QGrostlHash(nPassword).toHexString();

                        QString queryString = "UPDATE user SET password=\'" + nPassword + "\' WHERE username=\'" + Username + "\'";
                        //QString queryString = "INSERT INTO user (username, password) VALUES (?,?)";
                        QSqlQuery qry2(queryString);
                        //qry.addBindValue(Username);
                        //qry.addBindValue(Password);
                        qry2.exec();
                    }
                        else
                        {
                            QMessageBox::information(NULL, "Error!", "Invalid something...");
                        }

            }

        }
        else
        {

        }

    }
    else
    {

    }
}

void ChangePassword::on_pushButton_2_clicked() //Cancel button
{
    this->close();
}

void ChangePassword::on_lineEdit_3_textEdited(const QString &arg1)
{
    vPassword = ui->lineEdit_3->text();
}

void ChangePassword::getPasswordStrength()
{
        QString paswd = ui->lineEdit_2->text();
        passwordTools *ps = new passwordTools();
        int passBits = ps->passwordEntropy(paswd);
        ui->progressBar->setValue(passBits);
        QString output = QString::number(passBits);
        //ui->label_11->setText(getDesc(passBits));
        QString passDesc = "";
        if (passBits > 0)
                ui->label_4->show();
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
                        ui->label_4->hide();
        }
        ui->label_4->setText(passDesc);
}
