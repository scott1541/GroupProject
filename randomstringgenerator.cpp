#include "randomstringgenerator.h"
#include "ui_randomstringgenerator.h"

RandomStringGenerator::RandomStringGenerator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RandomStringGenerator)
{
    ui->setupUi(this);
}

RandomStringGenerator::~RandomStringGenerator()
{
    delete ui;
}

void RandomStringGenerator::on_pushButton_clicked()
{

}
