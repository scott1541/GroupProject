#include "changepassword.h"
#include "ui_changepassword.h"
#define Path_to_DB "login.db"

ChangePassword::ChangePassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangePassword)
{
    ui->setupUi(this);
    /*
    QString queryString = "INSERT INTO user (username, password) VALUES (?,?)";
    QSqlQuery qry(queryString);
    qry.addBindValue(Username);
    qry.addBindValue(Password);
    qry.exec();
    */
    /*
    QSqlQuery qry;
    if (Login && PasswordIsNotEmpty)
    {
            if (qry.exec("SELECT username, password FROM user WHERE username=\'" + Username
                    + "\' AND password=\'" + Password + "\'"))
            {
                    if (qry.next())
                    {
                            MainWindow *mainWin = new MainWindow;
                            mainWin->show();
                            hide();
                    }
                    else {
                            ui->label_5->setText("[-] Incorrect Username or Password");
                    }
            }
    }
}
*/
ChangePassword::~ChangePassword()
{
    delete ui;
}
