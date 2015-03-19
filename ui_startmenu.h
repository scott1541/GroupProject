/********************************************************************************
** Form generated from reading UI file 'startmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTMENU_H
#define UI_STARTMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_startmenu
{
public:
    QWidget *centralWidget;
    QLabel *menuTitle;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QLabel *label_5;
    QLabel *label_7;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLabel *label_6;
    QLineEdit *lineEdit_3;
    QLabel *label_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLineEdit *lineEdit;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QProgressBar *progressBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *startmenu)
    {
        if (startmenu->objectName().isEmpty())
            startmenu->setObjectName(QStringLiteral("startmenu"));
        startmenu->resize(736, 465);
        QFont font;
        font.setFamily(QStringLiteral("Corbel"));
        font.setPointSize(14);
        startmenu->setFont(font);
        centralWidget = new QWidget(startmenu);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        menuTitle = new QLabel(centralWidget);
        menuTitle->setObjectName(QStringLiteral("menuTitle"));
        menuTitle->setGeometry(QRect(100, 30, 581, 51));
        QFont font1;
        font1.setFamily(QStringLiteral("Corbel"));
        font1.setPointSize(36);
        menuTitle->setFont(font1);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 410, 241, 16));
        QFont font2;
        font2.setFamily(QStringLiteral("Corbel"));
        font2.setPointSize(9);
        label->setFont(font2);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 180, 111, 111));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/Images/SecureShieldQT.png")));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(320, 360, 77, 32));
        QFont font3;
        font3.setFamily(QStringLiteral("Corbel"));
        pushButton->setFont(font3);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setEnabled(true);
        label_5->setGeometry(QRect(510, 390, 311, 20));
        label_5->setFont(font3);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setEnabled(true);
        label_7->setGeometry(QRect(530, 190, 201, 16));
        label_7->setFont(font3);
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setEnabled(true);
        lineEdit_2->setGeometry(QRect(250, 260, 221, 21));
        lineEdit_2->setMaximumSize(QSize(267, 16777215));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(250, 230, 121, 17));
        label_4->setFont(font);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(250, 300, 108, 17));
        label_6->setFont(font);
        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(250, 330, 221, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(250, 160, 121, 17));
        label_3->setFont(font);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(220, 120, 272, 20));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(layoutWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setFont(font3);
        radioButton->setChecked(true);

        horizontalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(layoutWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setFont(font3);

        horizontalLayout->addWidget(radioButton_2);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(250, 190, 221, 21));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(490, 180, 41, 41));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/Images/tick.png")));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(490, 180, 41, 41));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/Images/error-32-32x32.png")));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(490, 260, 191, 16));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(500, 290, 121, 16));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(490, 260, 131, 23));
        progressBar->setValue(24);
        startmenu->setCentralWidget(centralWidget);
        lineEdit_2->raise();
        label_4->raise();
        label_6->raise();
        lineEdit_3->raise();
        lineEdit->raise();
        menuTitle->raise();
        label->raise();
        label_2->raise();
        pushButton->raise();
        label_5->raise();
        label_7->raise();
        layoutWidget->raise();
        label_3->raise();
        label_8->raise();
        label_9->raise();
        label_10->raise();
        label_11->raise();
        progressBar->raise();
        mainToolBar = new QToolBar(startmenu);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        startmenu->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(startmenu);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        startmenu->setStatusBar(statusBar);
        QWidget::setTabOrder(lineEdit, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, lineEdit_3);
        QWidget::setTabOrder(lineEdit_3, pushButton);

        retranslateUi(startmenu);

        QMetaObject::connectSlotsByName(startmenu);
    } // setupUi

    void retranslateUi(QMainWindow *startmenu)
    {
        startmenu->setWindowTitle(QApplication::translate("startmenu", "Secure Shield", 0));
        menuTitle->setText(QApplication::translate("startmenu", "Secure Shield Password Manager", 0));
        label->setText(QApplication::translate("startmenu", "2015. All Rights Reserved. SecureShield", 0));
        label_2->setText(QString());
        pushButton->setText(QApplication::translate("startmenu", "Login", 0));
        label_5->setText(QApplication::translate("startmenu", "Connected To Database [+]", 0));
        label_7->setText(QString());
        label_4->setText(QApplication::translate("startmenu", "Enter Password", 0));
        label_6->setText(QApplication::translate("startmenu", "Verify Password", 0));
        label_3->setText(QApplication::translate("startmenu", "Enter Username", 0));
        radioButton->setText(QApplication::translate("startmenu", "Existing User", 0));
        radioButton_2->setText(QApplication::translate("startmenu", "Create New Account", 0));
        label_8->setText(QString());
        label_9->setText(QString());
        label_10->setText(QString());
        label_11->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class startmenu: public Ui_startmenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTMENU_H
