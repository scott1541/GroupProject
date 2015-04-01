#include "viewpassword.h"
#include "ui_viewpassword.h"
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
    ui->lineEdit->setText(Name);
}

void viewPassword::setUsername(QString Username)
{
    ui->lineEdit_2->setText(Username);
}

void viewPassword::setPassword(QString Password)
{
    ui->lineEdit_3->setText(Password);
}

void viewPassword::setDescription(QString Description)
{
    ui->textEdit->setText(Description);
}
