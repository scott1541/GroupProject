#ifndef VIEWPASSWORD_H
#define VIEWPASSWORD_H

#include <QDialog>
#include <QtSql>

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

private:
    Ui::viewPassword *ui;

    QSqlDatabase myDB;
};

#endif // VIEWPASSWORD_H
