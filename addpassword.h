#ifndef ADDPASSWORD_H
#define ADDPASSWORD_H

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

    //void getPasswordStrength();

private:
    Ui::addPassword *ui;
};

#endif // ADDPASSWORD_H
