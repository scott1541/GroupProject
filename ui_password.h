/********************************************************************************
** Form generated from reading UI file 'password.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORD_H
#define UI_PASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_password
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;

    void setupUi(QDialog *password)
    {
        if (password->objectName().isEmpty())
            password->setObjectName(QStringLiteral("password"));
        password->resize(400, 453);
        buttonBox = new QDialogButtonBox(password);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(40, 410, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        pushButton = new QPushButton(password);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(250, 300, 115, 32));
        lineEdit = new QLineEdit(password);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(90, 160, 221, 21));
        lineEdit_2 = new QLineEdit(password);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(90, 200, 221, 21));

        retranslateUi(password);
        QObject::connect(buttonBox, SIGNAL(accepted()), password, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), password, SLOT(reject()));

        QMetaObject::connectSlotsByName(password);
    } // setupUi

    void retranslateUi(QDialog *password)
    {
        password->setWindowTitle(QApplication::translate("password", "Dialog", 0));
        pushButton->setText(QApplication::translate("password", "Generate", 0));
    } // retranslateUi

};

namespace Ui {
    class password: public Ui_password {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORD_H
