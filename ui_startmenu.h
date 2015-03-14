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
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *pushButton;
    QLabel *label_5;
    QLabel *label_7;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit_3;
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
        label_2->setGeometry(QRect(70, 190, 111, 111));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/Images/SecureShieldQT.png")));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(210, 240, 341, 33));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        horizontalLayout->addWidget(label_4);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setEnabled(true);
        lineEdit_2->setMaximumSize(QSize(267, 16777215));

        horizontalLayout->addWidget(lineEdit_2);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(210, 200, 341, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);

        lineEdit = new QLineEdit(layoutWidget1);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(250, 160, 315, 29));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(layoutWidget2);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        QFont font3;
        font3.setFamily(QStringLiteral("Corbel"));
        radioButton->setFont(font3);
        radioButton->setChecked(true);

        horizontalLayout_3->addWidget(radioButton);

        radioButton_2 = new QRadioButton(layoutWidget2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setFont(font3);

        horizontalLayout_3->addWidget(radioButton_2);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(380, 320, 77, 32));
        pushButton->setFont(font3);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setEnabled(true);
        label_5->setGeometry(QRect(290, 110, 311, 20));
        label_5->setFont(font3);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setEnabled(true);
        label_7->setGeometry(QRect(560, 210, 151, 16));
        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(170, 280, 381, 31));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        horizontalLayout_5->addWidget(label_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        lineEdit_3 = new QLineEdit(layoutWidget3);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        horizontalLayout_4->addWidget(lineEdit_3);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        startmenu->setCentralWidget(centralWidget);
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
        label_4->setText(QApplication::translate("startmenu", "Password", 0));
        label_3->setText(QApplication::translate("startmenu", "Username", 0));
        radioButton->setText(QApplication::translate("startmenu", "Existing User", 0));
        radioButton_2->setText(QApplication::translate("startmenu", "Create New Account", 0));
        pushButton->setText(QApplication::translate("startmenu", "Login", 0));
        label_5->setText(QApplication::translate("startmenu", "Connected To Database [+]", 0));
        label_7->setText(QString());
        label_6->setText(QApplication::translate("startmenu", "Verify Password", 0));
    } // retranslateUi

};

namespace Ui {
    class startmenu: public Ui_startmenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTMENU_H
