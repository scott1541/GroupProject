#ifndef RANDOMSTRINGGEN_H
#define RANDOMSTRINGGEN_H

#include <QDialog>

namespace Ui {
class RandomStringGen;
}

class RandomStringGen : public QDialog
{
    Q_OBJECT

public:
    explicit RandomStringGen(QWidget *parent = 0);
    ~RandomStringGen();

private slots:
    void on_pushButton_clicked();

private:
    Ui::RandomStringGen *ui;
};

#endif // RANDOMSTRINGGEN_H
