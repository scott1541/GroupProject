#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtSql>
#include <QFileInfo>
#include <QMessageBox>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnLogin_clicked();

    void on_txtUser_textChanged(const QString &arg1);

    void on_radioButton_2_toggled(bool checked);

    void on_radioButton_toggled(bool checked);

    void CreateAccount(const QString Username, const QString Password);

    bool CheckUsername(const QString Username);

private:
    Ui::MainWindow *ui;

    QSqlDatabase myDB;
};

#endif // MAINWINDOW_H
