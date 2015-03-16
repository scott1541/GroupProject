#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include "startmenu.h"
#include "qgrostlhash.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionAbout_SecureShield_triggered()
{
    QMessageBox::information(this, "About Secure Shield", "Secure Shield\
                                        Created and Developed by Lewis Yates, Scott Pollard and Carl Mansfield.\
                                        Open-Source Password Management Software aiding the good practice of cyber security. March 2015.");
}

void MainWindow::on_actionShow_Toolbar_triggered(bool isTriggered)
{
    if (isTriggered)
    {
        ui->toolBar->show();
    }
    else
    {
        ui->toolBar->hide();
    }
}



void MainWindow::on_actionSecurity_2_triggered()
{

}

void MainWindow::on_actionQuit_SecureShield_triggered()
{
    close();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionFormat_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_action_Cut_triggered()
{
    ui->textEdit->cut();
}
