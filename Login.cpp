#include "Login.h"
#include "ui_mainwindow.h"

#define Path_to_DB "login.db"
bool LoggingIn = true;
bool Creation = false;

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_3->hide();
    ui->txtVerify->hide();

    myDB = QSqlDatabase::addDatabase("QSQLITE");
    myDB.setDatabaseName(Path_to_DB);
    QFileInfo checkFile(Path_to_DB);

    if (checkFile.isFile())
    {
        if(myDB.open())
        {
            ui->lblResult->setText("[+] Connected to database!");
        }

    }else{
        ui->lblResult->setText("[!] Database file not found.");
    }
}

Login::~Login()
{
    delete ui;
    qDebug() << "Closing connection on exit";
    myDB.close();
}

void Login::on_btnLogin_clicked()
{
    QString Username, Password;
    Username = ui->txtUser->text();
    Password = ui->txtPass->text();

    if (!myDB.isOpen()){
        qDebug() << "Lost connection to db.";
        return;
    }

    QSqlQuery qry;

    if (LoggingIn)
    {

        if (qry.exec("SELECT username, password FROM user WHERE username=\'" + Username
                 + "\' AND password=\'" + Password + "\'"))
        {
            if (qry.next())
            {
                ui->lblResult->setText("[+] Correct Username and Password");
                QString msg = "username = " + qry.value(0).toString() + " \n" +
                                "password = " + qry.value(1).toString() + " \n";

                QMessageBox::warning(this, "Login was successful", msg);
            } else {
                ui->lblResult->setText("[-] Incorrect Username or Password");
            }
        }
    }

    if (Creation)
    {
        QString PasswordV;
        PasswordV = ui->txtVerify->text();
        if (!CheckUsername(Username))
        {
            if (Password == PasswordV)
            {
                //Create hashed password
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

void Login::on_txtUser_textChanged(const QString &arg1)
{
    qDebug() << "Username has been changed";
    QString Username;
    Username = ui->txtUser->text();

    if (CheckUsername(Username))
    {
        ui->lblResult->setText("[!] Username in use");
    } else {
        ui->lblResult->setText(("[+] Username is available"));
    }

}

void Login::on_radioButton_2_toggled(bool checked)
{
    LoggingIn = false;
    ui->btnLogin->setText("Create account");
    ui->label_3->show();
    ui->txtVerify->show();
    Creation = true;
}

void Login::on_radioButton_toggled(bool checked)
{
    Creation = false;
    ui->btnLogin->setText("Login");
    ui->label_3->hide();
    ui->txtVerify->hide();
    LoggingIn = true;
}

void Login::CreateAccount(const QString Username, const QString Password)
{
    QString queryString = "INSERT INTO user (username, password) VALUES (?,?)";
    QSqlQuery qry(queryString);
    qry.addBindValue(Username);
    qry.addBindValue(Password);
    qry.exec();


}

bool Login::CheckUsername(const QString Username)
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
