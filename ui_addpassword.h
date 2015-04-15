/********************************************************************************
** Form generated from reading UI file 'addpassword.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPASSWORD_H
#define UI_ADDPASSWORD_H

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

class Ui_addPassword
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
    QPushButton *pushButton_2;
    QCheckBox *checkBox;
    QPushButton *pushButton_3;
    QLabel *label_9;

    void setupUi(QDialog *addPassword)
    {
        if (addPassword->objectName().isEmpty())
            addPassword->setObjectName(QStringLiteral("addPassword"));
        addPassword->setWindowModality(Qt::WindowModal);
        addPassword->resize(458, 514);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addPassword->sizePolicy().hasHeightForWidth());
        addPassword->setSizePolicy(sizePolicy);
        addPassword->setMinimumSize(QSize(458, 514));
        addPassword->setMaximumSize(QSize(458, 514));
        label = new QLabel(addPassword);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 20, 171, 41));
        QFont font;
        font.setFamily(QStringLiteral("Lucida Grande"));
        font.setPointSize(24);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label_2 = new QLabel(addPassword);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(300, 20, 61, 61));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/Images/addKey.png")));
        label_2->setScaledContents(true);
        label_3 = new QLabel(addPassword);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 80, 151, 16));
        QFont font1;
        font1.setFamily(QStringLiteral("Lucida Grande"));
        font1.setPointSize(14);
        label_3->setFont(font1);
        label_4 = new QLabel(addPassword);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(120, 140, 121, 16));
        label_4->setFont(font1);
        label_5 = new QLabel(addPassword);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(120, 200, 71, 16));
        label_5->setFont(font1);
        label_7 = new QLabel(addPassword);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(120, 350, 81, 16));
        label_7->setFont(font1);
        lineEdit = new QLineEdit(addPassword);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(120, 100, 181, 21));
        lineEdit_2 = new QLineEdit(addPassword);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(120, 160, 181, 21));
        lineEdit_3 = new QLineEdit(addPassword);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(120, 220, 181, 21));
        lineEdit_3->setEchoMode(QLineEdit::Password);
        pushButton = new QPushButton(addPassword);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 460, 71, 31));
        pushButton->setFont(font1);
        lineEdit_5 = new QLineEdit(addPassword);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(120, 310, 181, 21));
        lineEdit_5->setEchoMode(QLineEdit::Password);
        label_6 = new QLabel(addPassword);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(120, 290, 121, 16));
        label_6->setFont(font1);
        textEdit = new QTextEdit(addPassword);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(120, 370, 181, 79));
        progressBar = new QProgressBar(addPassword);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(320, 220, 118, 23));
        progressBar->setValue(0);
        label_8 = new QLabel(addPassword);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(318, 250, 151, 20));
        pushButton_2 = new QPushButton(addPassword);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 215, 91, 32));
        checkBox = new QCheckBox(addPassword);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(180, 250, 121, 20));
        pushButton_3 = new QPushButton(addPassword);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(210, 460, 71, 31));
        pushButton_3->setFont(font1);
        label_9 = new QLabel(addPassword);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(310, 250, 141, 201));
        QFont font2;
        font2.setPointSize(10);
        label_9->setFont(font2);
        label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        QWidget::setTabOrder(lineEdit, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, lineEdit_3);
        QWidget::setTabOrder(lineEdit_3, lineEdit_5);
        QWidget::setTabOrder(lineEdit_5, textEdit);
        QWidget::setTabOrder(textEdit, pushButton);

        retranslateUi(addPassword);

        QMetaObject::connectSlotsByName(addPassword);
    } // setupUi

    void retranslateUi(QDialog *addPassword)
    {
        addPassword->setWindowTitle(QApplication::translate("addPassword", "Add Password", 0));
        label->setText(QApplication::translate("addPassword", "Add Password", 0));
        label_2->setText(QString());
        label_3->setText(QApplication::translate("addPassword", "Name (e.g. Facebook)", 0));
        label_4->setText(QApplication::translate("addPassword", "Username/Email", 0));
        label_5->setText(QApplication::translate("addPassword", "Password", 0));
        label_7->setText(QApplication::translate("addPassword", "Description", 0));
        pushButton->setText(QApplication::translate("addPassword", "Add ", 0));
        label_6->setText(QApplication::translate("addPassword", "Verify Password", 0));
        label_8->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("addPassword", "Click to generate a password", 0));
#endif // QT_NO_TOOLTIP
        pushButton_2->setText(QApplication::translate("addPassword", "Generate", 0));
        checkBox->setText(QApplication::translate("addPassword", "Show password", 0));
        pushButton_3->setText(QApplication::translate("addPassword", "Exit", 0));
        label_9->setText(QApplication::translate("addPassword", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class addPassword: public Ui_addPassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPASSWORD_H
