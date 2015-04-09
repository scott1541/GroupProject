#ifndef PASSWORD_H
#define PASSWORD_H

#include <QDialog>
#include "math.h"
#include "twofish.h"

namespace Ui {
class passwordTools;
}

class passwordTools : public QDialog
{
    Q_OBJECT

public:
    explicit passwordTools(QWidget *parent = 0);
    int passwordEntropy(QString Password);
    QString passwordGenerator();

    QString encryptPassword(char *Password, TwofishKey *key);
    QString decryptPassword(char *Password, TwofishKey *key);

    ~passwordTools();

private slots:

private:
    Ui::passwordTools *ui;
};

#endif // PASSWORD_H
