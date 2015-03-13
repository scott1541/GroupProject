#include "startmenu.h"
#include "ui_startmenu.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qgrostlhash.h"

#define Path_to_DB "login.db"
bool Login = true;
bool Creation = false;

startmenu::startmenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::startmenu)
{
    ui->setupUi(this);
    ui->lineEdit_3->hide();
    ui->label_6->hide();
    ui->label_7->hide();

    myDB = QSqlDatabase::addDatabase("QSQLITE");
    myDB.setDatabaseName(Path_to_DB);
    QFileInfo checkFile(Path_to_DB);

    if (checkFile.isFile())
    {
        if(myDB.open())
        {
            ui->label_5->setText("[+] Connected to database!");
        }

    }else{
        ui->label_5->setText("[!] Database file not found.");
    }

}

startmenu::~startmenu()
{
    delete ui;
}

void startmenu::on_radioButton_clicked()
{
    ui->lineEdit->show();
    ui->lineEdit_2->show();
    ui->label_3->setText("Username");
    ui->label_4->setText("Password");
    Creation = false;
    ui->lineEdit_3->hide();
    ui->label_6->hide();
    ui->label_7->hide();
    Login = true;
}

void startmenu::on_radioButton_2_clicked()
{
    ui->label_3->setText("Create Username");
    ui->label_4->setText("Create Password");
    ui->label_6->show();
    ui->lineEdit_3->show();
    ui->label_7->show();
    Login = false;
    Creation = true;
}


void startmenu::on_pushButton_clicked()
{
    QString Username, Password, UsernameS;
    Username = ui->lineEdit->text();
    Password = QGrostlHash(ui->lineEdit_2->text()).toHexString();
    UsernameS = Username;
    UsernameS.resize(4);
    Password = UsernameS + Password;

    if (!myDB.isOpen()){
        qDebug() << "Lost connection to db.";
        return;
    }

    QSqlQuery qry;

    if (Login)
    {

        if (qry.exec("SELECT username, password FROM user WHERE username=\'" + Username
                 + "\' AND password=\'" + Password + "\'"))
        {
            if (qry.next())
            {
                ui->label_5->setText("[+] Correct Username and Password");
                QString msg = "username = " + qry.value(0).toString() + " \n" +
                                "password = " + qry.value(1).toString() + " \n";

                QMessageBox::warning(this, "Login was successful", msg);
                MainWindow *mainWin = new MainWindow;
                mainWin->show();
                hide();
            } else {
                ui->label_5->setText("[-] Incorrect Username or Password");
            }
        }
    }

    if (Creation)
    {
        QString PasswordV;
        PasswordV = QGrostlHash(ui->lineEdit_3->text()).toHexString();
        UsernameS = Username;
        UsernameS.resize(4);
        PasswordV = UsernameS + PasswordV;

        if (!CheckUsername(Username))
        {
            if (Password == PasswordV)
            {
                CreateAccount(Username, Password);
                QMessageBox::warning(this, "Success!", "Your account has been created!");
            } else {
                QMessageBox::warning(this, "ERROR", "The passwords do not match");
            }
        } else {
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
        if (qry.next())
        {
            return true;
        } else {
            return false;
        }
    }
}

void startmenu::on_lineEdit_textChanged(const QString &arg1)
{
    qDebug() << "Username has been changed";
    QString Username;
    Username = ui->lineEdit->text();

    if (CheckUsername(Username))
    {
        ui->label_7->setText("Username in use");
    } else {
        ui->label_7->setText(("Username is available"));
    }
}

void startmenu::on_label_7_linkActivated(const QString &link)
{
    ui->label_7->hide();
}



void startmenu::on_lineEdit_3_textEdited(const QString &arg1)
{
    ui->lineEdit_3->setEchoMode(QLineEdit::Password);
}

void startmenu::on_lineEdit_2_textEdited(const QString &arg1)
{
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}
