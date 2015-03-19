#ifndef STARTMENU_H
#define STARTMENU_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QDebug>
#include <QtSql>
#include <QDialog>


namespace Ui {
class startmenu;
}

class startmenu : public QMainWindow
{
    Q_OBJECT

public:
    //static QString Desc;
    //static QString getDesc(int passStr) { return Desc; }

    explicit startmenu(QWidget *parent = 0);
    ~startmenu();

private slots:


    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_clicked();

    void CreateAccount(const QString Username, const QString Password);

    bool CheckUsername(const QString Username);

    void on_lineEdit_textChanged(const QString &arg1);

    //void on_lineEdit_textEdited(const QString &arg1);

    void on_label_7_linkActivated(const QString &link);

    void on_lineEdit_3_textEdited(const QString &arg1);

    void on_lineEdit_2_textEdited(const QString &arg1);

    void on_label_8_linkActivated(const QString &link);

    void on_label_9_linkActivated(const QString &link);

private:
    Ui::startmenu *ui;

    QSqlDatabase myDB;
};

#endif // STARTMENU_H
