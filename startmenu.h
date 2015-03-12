#ifndef STARTMENU_H
#define STARTMENU_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QDialog>


namespace Ui {
class startmenu;
}

class startmenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit startmenu(QWidget *parent = 0);
    ~startmenu();

private slots:


    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::startmenu *ui;
};

#endif // STARTMENU_H
