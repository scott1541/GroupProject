#include "password.h"
#include "ui_password.h"

password::password(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::password)
{
    ui->setupUi(this);
}

password::~password()
{
    delete ui;
}

int PassEntropy(const QString pass)
{
    int Entropy = 10;  //Random value for now


    return Entropy;
}
