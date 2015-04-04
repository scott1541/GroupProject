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

    myDB = QSqlDatabase::addDatabase("QSQLITE");
    myDB.setDatabaseName(Path_to_DB);
    QFileInfo checkFile(Path_to_DB);

    if(checkFile.isFile())
    {
        if (myDB.open())
        {
            qDebug() << "DB is open";
        }
    }

}

ChangePassword::~ChangePassword()
{
    delete ui;
}

void ChangePassword::on_lineEdit_textEdited(const QString &arg1)
{
    ui->lineEdit->setEchoMode(QLineEdit::Password);
    oPassword = ui->lineEdit->text();
}


void ChangePassword::on_lineEdit_2_textEdited(const QString &arg1)
{
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
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
            oPassword = UsernameS + oPassword;
            oPassword = QGrostlHash(oPassword).toHexString();

            QSqlQuery qry1;
            if (qry1.exec("SELECT username, password FROM user WHERE username=\'" + Username
                    + "\' AND password=\'" + oPassword + "\'"))  //THIS IF STATEMENT IS RETURNING FALSE
            {

                    if (qry1.next())
                    {
                        QMessageBox::information(this, "Success!", "Your password has been changed.");

                        nPassword = UsernameS + nPassword;
                        nPassword = QGrostlHash(nPassword).toHexString();

                        QString queryString = "UPDATE user SET password=\'" + nPassword + "\' WHERE username=\'" + Username + "\'";
                        //QString queryString = "INSERT INTO user (username, password) VALUES (?,?)";
                        QSqlQuery qry2(queryString);
                        //qry.addBindValue(Username);
                        //qry.addBindValue(Password);
                        qry2.exec();
<<<<<<< HEAD
                        this->close();

                    } else {
                            QMessageBox::information(this, "Oops..", "Incorrect password.");
                           }

                    }

            } else {
                    QMessageBox::information(this, "Error!", "The passwords do not match.");
                   }
    } else {
            QMessageBox::information(this, "Error!", "You missed a field.");
           }
=======
                    }
                        else
                        {
                            QMessageBox::information(NULL, "Error!", "An error occured!");
                        }

            }
            else
            {
                QMessageBox::information(NULL, "Error!", "Incorrect password, please try again.");
            }

        }
        else
        {
            QMessageBox::information(NULL, "Error!", "Please ensure that the new passwords match.");
        }

    }
    else
    {
        QMessageBox::information(NULL, "Error!", "Please enter a new password:");
    }
>>>>>>> origin/master
}

void ChangePassword::on_pushButton_2_clicked() //Cancel button
{
    this->close();
}

void ChangePassword::on_lineEdit_3_textEdited(const QString &arg1)
{
    ui->lineEdit_3->setEchoMode(QLineEdit::Password);
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
