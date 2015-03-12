#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QDialog>
#include "startmenu.h"
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_actionAbout_SecureShield_triggered();

    void on_actionShow_Toolbar_triggered(bool isTriggered);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
