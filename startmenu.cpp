#include "startmenu.h"
#include "ui_startmenu.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

startmenu::startmenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::startmenu)
{
    ui->setupUi(this);

}

startmenu::~startmenu()
{
    delete ui;
}

void startmenu::on_radioButton_clicked()
{
    ui->lineEdit->show();
    ui->lineEdit_2->show();
}

void startmenu::on_radioButton_2_clicked()
{
    ui->pushButton->hide();
    ui->label_3->setText("Create Username");
    ui->label_4->setText("Create Password");
}


void startmenu::on_pushButton_clicked()
{
    MainWindow *mainWin = new MainWindow;
    mainWin->show();
    hide();
}
