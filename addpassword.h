#ifndef ADDPASSWORD_H
#define ADDPASSWORD_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QDebug>
#include <QtSql>
#include <QDialog>

namespace Ui {
class addPassword;
}

class addPassword : public QDialog
{
    Q_OBJECT

public:
    explicit addPassword(QWidget *parent = 0);

    ~addPassword();

private slots:
    void on_lineEdit_3_textEdited(const QString &arg1);

    void on_lineEdit_5_textEdited(const QString &arg1);

    void addNewPassword();

    void on_pushButton_clicked(bool checked);

private:
    Ui::addPassword *ui;

    QSqlDatabase myDB;
};

#endif // ADDPASSWORD_H
