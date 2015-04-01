#include "changepassword.h"
#include "ui_changepassword.h"
#include "startmenu.h"
#include "qgrostlhash.h"
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
}

void ChangePassword::on_pushButton_clicked() //OK button
{
    if (nPassword.isEmpty() || nPassword.isNull())
    {
        PasswordIsNtEmpty = false;
        //Error message
    }
    else
        PasswordIsNtEmpty = true;


    if (PasswordIsNtEmpty == true) //If password isn't empty
    {
        if (nPassword == vPassword) //If new and verify passwords match
        {
            QSqlQuery qry1;

            if (qry1.exec("SELECT username, password FROM user WHERE username=\'" + Username
                    + "\' AND password=\'" + oPassword + "\'"))
            {
                    if (qry1.next())
                    {
                        QString UsernameS = Username;
                        UsernameS.resize(4);
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
                            //invalid password error
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
