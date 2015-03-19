#include "password.h"
#include "ui_password.h"

password::password(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::password)
{
    ui->setupUi(this);
}

int password::passWord(QString passWd)
{

    bool upC;  //Uppercase characters
    bool loC;  //Lowercase characters
    bool nuM;  //Number characters
    bool slC;  //Special characters (ASCII Printable)

    int charCnt = 0;  //Character count
    int charSet = 0;  //Character set count
    int passStr = 0;  //Password bit strength

    charCnt = passWd.length();   //Get length of password

    //QString passcharo = QString::number(charCnt);
    //ui->charcount->setText(passcharo);

    loC = passWd.contains(QRegExp("[a-z]"));   //Using regular expressions to detect characters in password string
    upC = passWd.contains(QRegExp("[A-Z]"));
    nuM = passWd.contains(QRegExp("[0-9]"));
    slC = passWd.contains(QRegExp("[ -~][^a-z][^A-Z][^0-9]"));

    if (loC == true)
    {
       charSet += 26;
    }
    if (upC == true)
    {
        charSet += 26;
    }
    if (nuM ==true)
    {
        charSet += 10;
    }
    if (slC == true)
    {
        charSet += 33;
    }

    passStr = charCnt * log2(charSet);  //Updated, should be working. //

    return passStr;
}


password::~password()
{
    delete ui;
}

