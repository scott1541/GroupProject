#include "randomstringgen.h"
#include "ui_randomstringgen.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

RandomStringGen::RandomStringGen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RandomStringGen)
{
    ui->setupUi(this);
}

static const char alphanum[] =
"0123456789"
"!@#$%^&*"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof(alphanum) - 1;

char genRandom()  // Random string generator function.
{

    return alphanum[rand() % stringLength];
}

int main()
{
    srand(time(0));
    for(int z=0; z < 21; z++)
    {
        cout << genRandom();

    }
    return 0;

}

void RandomStringGen::on_pushButton_clicked()
{
    ui->lineEdit->setText();
}


RandomStringGen::~RandomStringGen()
{
    delete ui;
}

