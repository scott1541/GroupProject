#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtSql>
#include <QFileInfo>
#include <QMessageBox>
#include "mainwindow.h"
#include <mainwindow.h>

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_btnLogin_clicked();

    void on_txtUser_textChanged(const QString &arg1);

    void on_radioButton_2_toggled(bool checked);

    void on_radioButton_toggled(bool checked);

    void CreateAccount(const QString Username, const QString Password);

    bool CheckUsername(const QString Username);

private:
    Ui::Login *ui;
    QSqlDatabase myDB;
};

#endif // MAINWINDOW_H
