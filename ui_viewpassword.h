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
#include <QtWidgets/QCheckBox>
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
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;
    QLineEdit *lineEdit_5;
    QLabel *label_6;
    QProgressBar *progressBar;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *lineEdit_6;
    QLabel *label_7;
    QLabel *label_10;
    QTextEdit *textEdit;
    QCheckBox *checkBox;
    QPushButton *pushButton_2;

    void setupUi(QDialog *viewPassword)
    {
        if (viewPassword->objectName().isEmpty())
            viewPassword->setObjectName(QStringLiteral("viewPassword"));
        viewPassword->resize(458, 549);
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
        label_5->setGeometry(QRect(120, 200, 131, 16));
        label_5->setFont(font1);
        lineEdit_2 = new QLineEdit(viewPassword);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(120, 160, 181, 21));
        lineEdit_3 = new QLineEdit(viewPassword);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(120, 220, 181, 21));
        lineEdit_3->setEchoMode(QLineEdit::Password);
        pushButton = new QPushButton(viewPassword);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 500, 71, 31));
        pushButton->setFont(font1);
        lineEdit_5 = new QLineEdit(viewPassword);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(120, 300, 181, 21));
        lineEdit_5->setEchoMode(QLineEdit::Password);
        label_6 = new QLabel(viewPassword);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(120, 280, 121, 16));
        label_6->setFont(font1);
        progressBar = new QProgressBar(viewPassword);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(320, 220, 118, 23));
        progressBar->setValue(0);
        label_8 = new QLabel(viewPassword);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(318, 250, 151, 20));
        label_9 = new QLabel(viewPassword);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(120, 110, 151, 16));
        QFont font2;
        font2.setFamily(QStringLiteral("Lucida Grande"));
        font2.setPointSize(12);
        label_9->setFont(font2);
        lineEdit_6 = new QLineEdit(viewPassword);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(120, 360, 181, 21));
        lineEdit_6->setEchoMode(QLineEdit::Password);
        label_7 = new QLabel(viewPassword);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(120, 340, 151, 16));
        label_7->setFont(font1);
        label_10 = new QLabel(viewPassword);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(120, 390, 151, 16));
        label_10->setFont(font1);
        textEdit = new QTextEdit(viewPassword);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(120, 410, 181, 79));
        checkBox = new QCheckBox(viewPassword);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(180, 250, 121, 20));
        pushButton_2 = new QPushButton(viewPassword);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 500, 71, 31));
        pushButton_2->setFont(font1);
        QWidget::setTabOrder(lineEdit_2, lineEdit_3);
        QWidget::setTabOrder(lineEdit_3, lineEdit_5);
        QWidget::setTabOrder(lineEdit_5, pushButton);

        retranslateUi(viewPassword);

        QMetaObject::connectSlotsByName(viewPassword);
    } // setupUi

    void retranslateUi(QDialog *viewPassword)
    {
        viewPassword->setWindowTitle(QApplication::translate("viewPassword", "Add Password", 0));
        label->setText(QApplication::translate("viewPassword", "View Password", 0));
        label_2->setText(QString());
        label_3->setText(QApplication::translate("viewPassword", "Name", 0));
        label_4->setText(QApplication::translate("viewPassword", "Username/Email", 0));
        label_5->setText(QApplication::translate("viewPassword", "Current Password", 0));
        pushButton->setText(QApplication::translate("viewPassword", "Edit", 0));
        label_6->setText(QApplication::translate("viewPassword", "New Password", 0));
        label_8->setText(QString());
        label_9->setText(QApplication::translate("viewPassword", "Name ", 0));
        label_7->setText(QApplication::translate("viewPassword", "Verify New Password", 0));
        label_10->setText(QApplication::translate("viewPassword", "Description", 0));
        checkBox->setText(QApplication::translate("viewPassword", "Show Password", 0));
        pushButton_2->setText(QApplication::translate("viewPassword", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class viewPassword: public Ui_viewPassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWPASSWORD_H
