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

private slots:
    void on_lineEdit_textEdited(const QString &arg1);

    void on_lineEdit_2_textEdited(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_3_textEdited(const QString &arg1);

    void getPasswordStrength();

private:
    Ui::ChangePassword *ui;

    QSqlDatabase myDB;
};

#endif // CHANGEPASSWORD_H
