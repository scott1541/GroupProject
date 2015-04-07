#ifndef VIEWPASSWORD_H
#define VIEWPASSWORD_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QDebug>
#include <QtSql>
#include <QDialog>

namespace Ui {
class viewPassword;
}

class viewPassword : public QDialog
{
    Q_OBJECT

public:
    explicit viewPassword(QWidget *parent = 0);
    ~viewPassword();

    void setName(QString Name);
    void setUsername(QString Username);
    void setPassword(QString Password);
    void setDescription(QString Description);

private slots:
    void on_checkBox_toggled(bool checked);

    void on_pushButton_clicked();

    void editPassword(QString Name, QString newPassword);

    void on_pushButton_2_clicked();

private:
    Ui::viewPassword *ui;

    QSqlDatabase myDB;
};

#endif // VIEWPASSWORD_H
