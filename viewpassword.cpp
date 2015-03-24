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

    QSqlQuery qry;

    QString Name = qry.value("name").toString();
    ui->lineEdit->setText(Name);

    /*item->setText(0, qry.value("name").toString());
    item->setText(1, qry.value("usernameID").toString());
    item->setText(2, qry.value("password").toString());
    item->setText(3, qry.value("dateadded").toString());
    item->setText(4, qry.value("description").toString());*/

}

viewPassword::~viewPassword()
{
    delete ui;
}
