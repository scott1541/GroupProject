#include "addpassword.h"
#include "ui_addpassword.h"

addPassword::addPassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addPassword)
{
    ui->setupUi(this);
}

addPassword::~addPassword()
{
    delete ui;
}

void addPassword::on_lineEdit_3_textEdited(const QString &arg1)
{

    ui->lineEdit_3->setEchoMode(QLineEdit::Password);

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
    ui->lineEdit_5->setEchoMode(QLineEdit::Password);
}

