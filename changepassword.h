#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H
#include <QtSql>
#include <QDialog>

namespace Ui {
class ChangePassword;
}

class ChangePassword : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePassword(QWidget *parent = 0);
    ~ChangePassword();

private:
    Ui::ChangePassword *ui;

    QSqlDatabase myDB;
};

#endif // CHANGEPASSWORD_H
