#ifndef PASSWORD_H
#define PASSWORD_H

#include <QDialog>
#include "math.h"

namespace Ui {
class passwordTools;
}

class passwordTools : public QDialog
{
    Q_OBJECT

public:
    explicit passwordTools(QWidget *parent = 0);
    int passwordEntropy(QString Password);
    ~passwordTools();

private slots:

private:
    Ui::passwordTools *ui;
};

#endif // PASSWORD_H
