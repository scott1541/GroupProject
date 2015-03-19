#ifndef PASSWORD_H
#define PASSWORD_H

#include <QDialog>
#include "math.h"

namespace Ui {
class password;
}

class password : public QDialog
{
    Q_OBJECT

public:
    explicit password(QWidget *parent = 0);
    int passWord(QString passwd);
    ~password();

private slots:

private:
    Ui::password *ui;
};

#endif // PASSWORD_H
