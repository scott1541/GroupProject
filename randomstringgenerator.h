#ifndef RANDOMSTRINGGENERATOR_H
#define RANDOMSTRINGGENERATOR_H

#include <QDialog>

namespace Ui {
class RandomStringGenerator;
}

class RandomStringGenerator : public QDialog
{
    Q_OBJECT

public:
    explicit RandomStringGenerator(QWidget *parent = 0);
    ~RandomStringGenerator();
    char genRandom();



private slots:
    void on_pushButton_clicked();

private:
    Ui::RandomStringGenerator *ui;
};

#endif // RANDOMSTRINGGENERATOR_H
