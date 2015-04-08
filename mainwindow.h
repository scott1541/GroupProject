#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QDialog>
#include "startmenu.h"
#include <QMessageBox>
#include <QTreeWidget>
#include <QTreeWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    void showPasswords();

    void searchPasswords(QString Word);

    ~MainWindow();

private slots:

    void on_actionAbout_SecureShield_triggered();

    void on_actionShow_Toolbar_triggered(bool isTriggered);

    void on_actionSecurity_2_triggered();

    void on_actionQuit_SecureShield_triggered();

    void on_actionCopy_triggered();

    void on_actionFormat_triggered();

    void on_action_Cut_triggered();

    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void on_action_Redo_triggered();

    void on_action_Undo_triggered();

    void on_actionAddEntry_triggered();

    void on_actionEditEntry_triggered();

    void on_actionChange_Password_triggered();

    void on_textEdit_textChanged();

    void on_actionDeleteEntry_triggered();

    void on_actionRemove_All_Data_triggered();

    void on_actionDelete_Account_triggered();

private:

    Ui::MainWindow *ui;

    QSqlDatabase myDB;
};

#endif // MAINWINDOW_H
