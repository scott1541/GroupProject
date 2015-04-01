/********************************************************************************
** Form generated from reading UI file 'viewpassword.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWPASSWORD_H
#define UI_VIEWPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_viewPassword
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;
    QLineEdit *lineEdit_5;
    QLabel *label_6;
    QTextEdit *textEdit;
    QProgressBar *progressBar;
    QLabel *label_8;

    void setupUi(QDialog *viewPassword)
    {
        if (viewPassword->objectName().isEmpty())
            viewPassword->setObjectName(QStringLiteral("viewPassword"));
        viewPassword->resize(458, 475);
        label = new QLabel(viewPassword);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 20, 171, 41));
        QFont font;
        font.setFamily(QStringLiteral("Lucida Grande"));
        font.setPointSize(24);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label_2 = new QLabel(viewPassword);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(300, 20, 61, 61));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/Images/editKey.png")));
        label_2->setScaledContents(true);
        label_3 = new QLabel(viewPassword);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 80, 151, 16));
        QFont font1;
        font1.setFamily(QStringLiteral("Lucida Grande"));
        font1.setPointSize(14);
        label_3->setFont(font1);
        label_4 = new QLabel(viewPassword);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(120, 140, 121, 16));
        label_4->setFont(font1);
        label_5 = new QLabel(viewPassword);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(120, 200, 71, 16));
        label_5->setFont(font1);
        label_7 = new QLabel(viewPassword);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(120, 320, 81, 16));
        label_7->setFont(font1);
        lineEdit = new QLineEdit(viewPassword);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(120, 100, 181, 21));
        lineEdit_2 = new QLineEdit(viewPassword);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(120, 160, 181, 21));
        lineEdit_3 = new QLineEdit(viewPassword);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(120, 220, 181, 21));
        lineEdit_3->setEchoMode(QLineEdit::Password);
        pushButton = new QPushButton(viewPassword);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(180, 430, 71, 31));
        pushButton->setFont(font1);
        lineEdit_5 = new QLineEdit(viewPassword);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(120, 280, 181, 21));
        lineEdit_5->setEchoMode(QLineEdit::Password);
        label_6 = new QLabel(viewPassword);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(120, 260, 121, 16));
        label_6->setFont(font1);
        textEdit = new QTextEdit(viewPassword);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(120, 340, 181, 79));
        progressBar = new QProgressBar(viewPassword);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(320, 220, 118, 23));
        progressBar->setValue(0);
        label_8 = new QLabel(viewPassword);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(318, 250, 151, 20));
        QWidget::setTabOrder(lineEdit, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, lineEdit_3);
        QWidget::setTabOrder(lineEdit_3, lineEdit_5);
        QWidget::setTabOrder(lineEdit_5, textEdit);
        QWidget::setTabOrder(textEdit, pushButton);

        retranslateUi(viewPassword);

        QMetaObject::connectSlotsByName(viewPassword);
    } // setupUi

    void retranslateUi(QDialog *viewPassword)
    {
        viewPassword->setWindowTitle(QApplication::translate("viewPassword", "Add Password", 0));
        label->setText(QApplication::translate("viewPassword", "View Password", 0));
        label_2->setText(QString());
        label_3->setText(QApplication::translate("viewPassword", "Name (e.g. Facebook)", 0));
        label_4->setText(QApplication::translate("viewPassword", "Username/Email", 0));
        label_5->setText(QApplication::translate("viewPassword", "Password", 0));
        label_7->setText(QApplication::translate("viewPassword", "Description", 0));
        pushButton->setText(QApplication::translate("viewPassword", "Add ", 0));
        label_6->setText(QApplication::translate("viewPassword", "Verify Password", 0));
        label_8->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class viewPassword: public Ui_viewPassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWPASSWORD_H
