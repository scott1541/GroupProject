#include "passwordTools.h"
#include "ui_passwordTools.h"
#include "qgrostlhash.h"
#include <cstdlib>
#include <QDebug>
#include <ctime>

passwordTools::passwordTools(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::passwordTools)
{
    ui->setupUi(this);
}

int passwordTools::passwordEntropy(QString Password)
{

    bool upC;  //Uppercase characters
    bool loC;  //Lowercase characters
    bool nuM;  //Number characters
    bool slC;  //Special characters (ASCII Printable)

    int charCnt = 0;  //Character count
    int charSet = 0;  //Character set count
    int passStr = 0;  //Password bit strength

    charCnt = Password.length();   //Get length of password

    //QString passcharo = QString::number(charCnt);
    //ui->charcount->setText(passcharo);

    loC = Password.contains(QRegExp("[a-z]"));   //Using regular expressions to detect characters in password string
    upC = Password.contains(QRegExp("[A-Z]"));
    nuM = Password.contains(QRegExp("[0-9]"));
    slC = Password.contains(QRegExp("[ -~][^a-z][^A-Z][^0-9]"));

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

    passStr = (passStr * 0.7);

    return passStr;
}

QString passwordTools::passwordGenerator()
{
    static const char alphanum[] = "0123456789"
    "!@#$%^&*_-"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";

    int stringLength = sizeof(alphanum) - 1;

    QString Password;

    srand(time(0));

    for (int i = 0; i < 20; ++i)
    {
        Password += alphanum[rand() % stringLength];
    }

    return Password;
}

QString passwordTools::encryptPassword(QString Password, QString Key)
{
    BotanWrapper botan;
    botan.setPassword(Key);
    botan.setSalt(QGrostlHash(Key).toHexString());
    //qDebug() << "Salt used: " << QGrostlHash(Key).toHexString();
    QString encryptedPassword = botan.Encrypt(Password);
    return encryptedPassword;
}

QString passwordTools::decryptPassword(QString Password, QString key)
{
    BotanWrapper botan;
    botan.setPassword(key);
    botan.setSalt(QGrostlHash(key).toHexString());
    QString decryptedPassword = botan.Decrypt(Password);
    return decryptedPassword;
}

QString passwordTools::passwordRecommender(QString Password)
{
    QString recommend = "Improve password by: \n";
    bool upC;  //Uppercase characters
    bool loC;  //Lowercase characters
    bool nuM;  //Number characters
    bool slC;  //Special characters (ASCII Printable)

    loC = Password.contains(QRegExp("[a-z]"));   //Using regular expressions to detect characters in password string
    upC = Password.contains(QRegExp("[A-Z]"));
    nuM = Password.contains(QRegExp("[0-9]"));
    slC = Password.contains(QRegExp("[ -~]"));

    if (!loC)
    {
        recommend += "- adding lowercase\n";
    }
    if (!upC)
    {
        recommend += "- adding uppercase\n";
    }
    if(!nuM)
    {
        recommend += "- adding numbers\n";
    }
    if (!slC)
    {
        recommend += "- adding symbols\n";
    }
    if(loC && upC && nuM && slC)
    {
        recommend += "- adding more characters\n";
    }


    return recommend;
}


passwordTools::~passwordTools()
{
    delete ui;
}

