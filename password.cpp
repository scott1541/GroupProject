#include "password.h"
#include "ui_password.h"

password::password(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::password)
{
    ui->setupUi(this);
}

int password::passWord(QString passwd)
{

    return 0;
}


password::~password()
{
    delete ui;
}

