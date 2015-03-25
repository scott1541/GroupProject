#include "startmenu.h"
#include "ui_startmenu.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qgrostlhash.h"
#include <QLabel>
#include "password.h"
#define Path_to_DB "login.db"
bool Login = true;
bool Creation = false;
bool PasswordIsNotEmpty = false;
QString Username = "";

startmenu::startmenu(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::startmenu)
{
        ui->setupUi(this);
        ui->pushButton->setGeometry(320, 290, 77, 32);
        ui->lineEdit_3->hide();
        ui->label_6->hide();
        ui->label_7->hide();
        ui->label_8->hide();
        ui->label_9->hide();
        ui->progressBar->hide();
        ui->label_11->hide();
        myDB = QSqlDatabase::addDatabase("QSQLITE");
        myDB.setDatabaseName(Path_to_DB);
        QFileInfo checkFile(Path_to_DB);
        if (checkFile.isFile())
        {
                if (myDB.open())
                {
                        ui->label_5->setText("[+] Connected To Database!");
                }
        }
        else{
                ui->label_5->setText("[!] Database File Not Found.");
        }
}
startmenu::~startmenu()
{
        delete ui;
}
void startmenu::on_radioButton_clicked() //Existing user login
{
        ui->pushButton->setGeometry(320, 290, 77, 32);
        ui->lineEdit->show();
        ui->lineEdit_2->show();
        ui->label_3->setText("Enter Username");
        ui->label_4->setText("Enter Password");
        Creation = false;
        ui->lineEdit_3->hide();
        ui->label_6->hide();
        ui->label_7->hide();
        ui->label_8->hide();
        ui->label_9->hide();
        ui->progressBar->hide();
        ui->label_11->hide();
        Login = true;
}
void startmenu::on_radioButton_2_clicked() //New user creation
{
        ui->pushButton->setGeometry(320, 370, 77, 32);
        ui->label_3->setText("Create Username");
        ui->label_4->setText("Create Password");
        ui->label_6->show();
        ui->label_11->show();
        ui->progressBar->show();
        ui->progressBar->setValue(0);
        ui->lineEdit_3->show();
        ui->label_7->show();
        ui->label_8->hide();
        ui->label_9->hide();
        Login = false;
        Creation = true;
        Username = ui->lineEdit->text();
        CheckUsername(Username);
        getPasswordStrength();
}
void startmenu::on_pushButton_clicked() //Login/account creation button
{
        QString Password, UsernameS;
        Username = ui->lineEdit->text();
        UsernameS = Username;
        UsernameS.resize(4);
        Password = ui->lineEdit_2->text();
        Password = UsernameS + Password;
        Password = QGrostlHash(Password).toHexString();
        if (!myDB.isOpen()){
                qDebug() << "Lost connection to db.";
                return;
        }
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
        if (Creation && PasswordIsNotEmpty)
        {
        QString PasswordV;
        UsernameS = Username;
        UsernameS.resize(4);
        PasswordV = ui->lineEdit_3->text();
        PasswordV = UsernameS + PasswordV;
        PasswordV = QGrostlHash(PasswordV).toHexString();

        if (!CheckUsername(Username) && Username != "")
                  {
            if (Password == PasswordV && Password != "")
                        {
                CreateAccount(Username, Password);
                QMessageBox::warning(this, "Success!", "Your account has been created!");
                MainWindow *mainWin = new MainWindow;
                mainWin->show();
                hide();
                        }
        else {
                QMessageBox::warning(this, "ERROR", "The passwords do not match");
             }
                  }
        else {
                QMessageBox::warning(this, "ERROR", "This username is already in use");
             }
        }
}
void startmenu::CreateAccount(const QString Username, const QString Password)
{
        QString queryString = "INSERT INTO user (username, password) VALUES (?,?)";
        QSqlQuery qry(queryString);
        qry.addBindValue(Username);
        qry.addBindValue(Password);
        qry.exec();
}
bool startmenu::CheckUsername(const QString Username)
{
        QSqlQuery qry;
        if (qry.exec("SELECT username FROM user WHERE username=\'" + Username + "\'"))
        {
                if (Username.isEmpty())
                {
                        ui->label_7->hide();
                        ui->label_9->hide();
                        ui->label_8->hide();
                }
                else
                {
                        ui->label_7->show();
                        ui->label_9->show();
                        ui->label_8->show();
                }
                if (qry.next())
                {
                        ui->label_8->hide();
                        ui->label_7->setText("Username is already taken");
                        return true;
                }
                else {
                        ui->label_9->hide();
                        ui->label_8->show();
                        ui->label_7->setText("Username is available");
                        return false;
                }
        }
}
void startmenu::on_lineEdit_textChanged(const QString &arg1) //Username input line
{
        qDebug() << "Username has been changed";
        Username = ui->lineEdit->text();
        if (Creation)
        {
                CheckUsername(Username);
        }
}
void startmenu::on_label_7_linkActivated(const QString &link)
{
        ui->label_7->hide();
}
void startmenu::on_lineEdit_3_textEdited(const QString &arg1) //1st password field
{
        ui->lineEdit_3->setEchoMode(QLineEdit::Password);
}
void startmenu::on_lineEdit_2_textEdited(const QString &arg1) //2nd password field (verify)
{
        ui->lineEdit_2->setEchoMode(QLineEdit::Password);

        QString Password = ui->lineEdit_2->text();

        if (Password.isEmpty() || Password.isNull())
        {
            PasswordIsNotEmpty = false;
        } else {
            PasswordIsNotEmpty = true;
        }

        if (Creation)
        {
                getPasswordStrength();
        }

}

void startmenu::getPasswordStrength()
{
        QString paswd = ui->lineEdit_2->text();
        password *ps = new password();
        int passBits = ps->passWord(paswd);
        ui->progressBar->setValue(passBits);
        QString output = QString::number(passBits);
        //ui->label_11->setText(getDesc(passBits));
        QString passDesc = "";
        if (passBits > 0)
                ui->label_11->show();
        if (passBits < 20)
                passDesc = "Very weak";
        if (passBits > 19 && passBits < 30)
                passDesc = "Relatively weak";
        if (passBits > 29 && passBits < 50)
                passDesc = "Moderately strong";
        if (passBits > 49 && passBits < 70)
                passDesc = "Strong";
        if (passBits > 69)
                passDesc = "Very Strong";
        if (passBits <= 0){
                ui->progressBar->setValue(0),
                        ui->label_11->hide();
        }
        ui->label_11->setText(passDesc);
}

void startmenu::on_label_8_linkActivated(const QString &link)
{
        ui->label_8->hide();
}
void startmenu::on_label_9_linkActivated(const QString &link)
{
        ui->label_9->hide();
}


//
//static QString getDesc(int passStr)
//{
//startmenu::Desc = "Hello";
//return startmenu::Desc;
//}
