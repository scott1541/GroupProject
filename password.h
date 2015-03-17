#ifndef PASSWORD_H
#define PASSWORD_H

#include <QDialog>

namespace Ui {
class password;
}

class password : public QDialog
{
    Q_OBJECT

public:

    int PassEntropy(const QString password);

    explicit password(QWidget *parent = 0);
    ~password();

private slots:

    //int PassEntropy(const QString password);

private:
    Ui::password *ui;
};

#endif // PASSWORD_H
