#include "passwordTools.h"
#include "ui_passwordTools.h"
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

QString passwordTools::encryptPassword(QString Password, TwofishKey *key)
{
    std::string st = Password.toUtf8().constData();
    char *test = (char*)st.c_str();
    unsigned char *cPassword(reinterpret_cast<unsigned char*>(test));
    //qDebug() << cPassword;
    Twofish_Byte *passwordToEncrypt = cPassword;
    Twofish_Byte encryptedWord [16];
    Twofish *twofish = new Twofish();
    twofish->Encrypt(key, passwordToEncrypt, encryptedWord);
    char* myKey(reinterpret_cast<char *>(key));
    //qDebug() << "Encrypted with the key: " << myKey;

    std::string encrypted(reinterpret_cast<char*>(encryptedWord));
    QString encryptedPassword(encrypted.c_str());
    qDebug() << encryptedPassword;
    return encryptedPassword;
}

QString passwordTools::decryptPassword(QString Password, QString key)
{
    qDebug() << Password;
    std::string st = Password.toUtf8().constData();
    char *test = (char*)st.c_str();
    qDebug() << test;
    unsigned char *cPassword(reinterpret_cast<unsigned char*>(test));
    qDebug() << (char*)cPassword;
    //qDebug() << Password;
    //unsigned char *cPassword = reinterpret_cast<unsigned char*>(Password);
    //qDebug() << cPassword;
    Twofish_Byte *passwordToDecrypt = cPassword;
    Twofish_Byte decryptedWord [16];
    Twofish *twofish = new Twofish();
    //TwofishKey *unlock = key;
    Twofish_Byte byte [16];
    std::string gg = key.toStdString();
    char* keyToUnlock = (char *)gg.c_str();
    //qDebug() << "gaga" << gg.c_str();
    //qDebug() << "bebe" << keyToUnlock;
    TwofishKey *unlock = (reinterpret_cast<TwofishKey*>(keyToUnlock));
    twofish->Decrypt(unlock, passwordToDecrypt, decryptedWord);
    char* myKey(reinterpret_cast<char *>(unlock));
    //qDebug() << "Tried to decrypt with key: " << myKey;

    //qDebug() << (char*)decryptedWord;
    std::string myDecrypt(reinterpret_cast<char*>(decryptedWord));
    QString qDecrypt(myDecrypt.c_str());
    //qDebug() << qDecrypt;
    return qDecrypt;
}


passwordTools::~passwordTools()
{
    delete ui;
}

