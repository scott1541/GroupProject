/********************************************************************************
** Form generated from reading UI file 'application.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLICATION_H
#define UI_APPLICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_application
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *application)
    {
        if (application->objectName().isEmpty())
            application->setObjectName(QStringLiteral("application"));
        application->resize(800, 600);
        centralwidget = new QWidget(application);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(190, 160, 115, 32));
        application->setCentralWidget(centralwidget);
        menubar = new QMenuBar(application);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        application->setMenuBar(menubar);
        statusbar = new QStatusBar(application);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        application->setStatusBar(statusbar);

        retranslateUi(application);

        QMetaObject::connectSlotsByName(application);
    } // setupUi

    void retranslateUi(QMainWindow *application)
    {
        application->setWindowTitle(QApplication::translate("application", "MainWindow", 0));
        pushButton->setText(QApplication::translate("application", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class application: public Ui_application {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLICATION_H
