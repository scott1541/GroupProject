/********************************************************************************
** Form generated from reading UI file 'password.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDTOOLS_H
#define UI_PASSWORDTOOLS_H

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

class Ui_passwordTools
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;

    void setupUi(QDialog *passwordTools)
    {
        if (passwordTools->objectName().isEmpty())
            passwordTools->setObjectName(QStringLiteral("password"));
        passwordTools->resize(400, 453);
        buttonBox = new QDialogButtonBox(passwordTools);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(40, 410, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        pushButton = new QPushButton(passwordTools);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(250, 300, 115, 32));
        lineEdit = new QLineEdit(passwordTools);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(90, 160, 221, 21));
        lineEdit_2 = new QLineEdit(passwordTools);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(90, 200, 221, 21));

        retranslateUi(passwordTools);
        QObject::connect(buttonBox, SIGNAL(accepted()), passwordTools, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), passwordTools, SLOT(reject()));

        QMetaObject::connectSlotsByName(passwordTools);
    } // setupUi

    void retranslateUi(QDialog *passwordTools)
    {
        passwordTools->setWindowTitle(QApplication::translate("passwordTools", "Dialog", 0));
        pushButton->setText(QApplication::translate("passwordTools", "Generate", 0));
    } // retranslateUi

};

namespace Ui {
    class passwordTools: public Ui_passwordTools {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORD_H
