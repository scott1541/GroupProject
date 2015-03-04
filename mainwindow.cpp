#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qgrostlhash.h"

#define Path_to_DB "login.db"
bool Login = true;
bool Creation = false;

MainWindow::MainWindow(QWidget *parent) :
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

MainWindow::~MainWindow()
{
    delete ui;
    qDebug() << "Closing connection on exit";
    myDB.close();
}

void MainWindow::on_btnLogin_clicked()
{
    QString Username, Password, Salt;
    Username = ui->txtUser->text();
    Salt = Username;
    Salt.resize(4);  //Make salt first 4 characters of username
    Password = (Salt + (QGrostlHash(ui->txtPass->text()).toHexString())); //Set password to salted & hashed password input

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
        PasswordV = (Salt + (QGrostlHash(ui->txtVerify->text()).toHexString()));
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

void MainWindow::on_txtUser_textChanged(const QString &arg1)
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

void MainWindow::on_radioButton_2_toggled(bool checked)
{
    Login = false;
    ui->btnLogin->setText("Create account");
    ui->label_3->show();
    ui->txtVerify->show();
    Creation = true;
}

void MainWindow::on_radioButton_toggled(bool checked)
{
    Creation = false;
    ui->btnLogin->setText("Login");
    ui->label_3->hide();
    ui->txtVerify->hide();
    Login = true;
}

void MainWindow::CreateAccount(const QString Username, const QString Password)
{
    QString queryString = "INSERT INTO user (username, password) VALUES (?,?)";
    QSqlQuery qry(queryString);
    qry.addBindValue(Username);
    qry.addBindValue(Password);
    qry.exec();


}

bool MainWindow::CheckUsername(const QString Username)
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
