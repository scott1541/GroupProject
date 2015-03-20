/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_File;
    QAction *action_Undo;
    QAction *action_Redo;
    QAction *action_Cut;
    QAction *actionCopy;
    QAction *actionFormat;
    QAction *action_Format;
    QAction *actionSave_Ctrl_S;
    QAction *actionSave_As_F12;
    QAction *actionNew;
    QAction *actionGet_Help_Online_2;
    QAction *actionEncryption;
    QAction *actionAdd_New_Category;
    QAction *actionHelpimage;
    QAction *actionAbout_SecureShield;
    QAction *actionSearchFunction;
    QAction *actionShow_Toolbar;
    QAction *actionAbout_SecureShield_2;
    QAction *actionHide_SecureShield;
    QAction *actionHide_SecureShield_2;
    QAction *actionQuit_SecureShield;
    QAction *actionSecurity_2;
    QAction *actionSecurity_3;
    QAction *actionAddEntry;
    QAction *actionDeleteEntry;
    QAction *actionEditEntry;
    QWidget *centralwidget;
    QTreeWidget *treeWidget;
    QPushButton *pushButton;
    QLabel *label;
    QTextEdit *textEdit;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menu_Edit;
    QMenu *menuTools;
    QMenu *menuHelp_2;
    QMenu *menuHelp;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        QFont font;
        font.setFamily(QStringLiteral("Corbel"));
        MainWindow->setFont(font);
        MainWindow->setIconSize(QSize(20, 20));
        action_File = new QAction(MainWindow);
        action_File->setObjectName(QStringLiteral("action_File"));
        action_File->setCheckable(false);
        action_File->setChecked(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_File->setIcon(icon);
        action_File->setFont(font);
        action_Undo = new QAction(MainWindow);
        action_Undo->setObjectName(QStringLiteral("action_Undo"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Images/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Undo->setIcon(icon1);
        action_Undo->setFont(font);
        action_Redo = new QAction(MainWindow);
        action_Redo->setObjectName(QStringLiteral("action_Redo"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Images/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Redo->setIcon(icon2);
        action_Redo->setFont(font);
        action_Cut = new QAction(MainWindow);
        action_Cut->setObjectName(QStringLiteral("action_Cut"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Images/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Cut->setIcon(icon3);
        action_Cut->setFont(font);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        QIcon icon4;
        icon4.addFile(QStringLiteral("copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon4);
        actionCopy->setFont(font);
        actionFormat = new QAction(MainWindow);
        actionFormat->setObjectName(QStringLiteral("actionFormat"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Images/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFormat->setIcon(icon5);
        actionFormat->setFont(font);
        action_Format = new QAction(MainWindow);
        action_Format->setObjectName(QStringLiteral("action_Format"));
        action_Format->setFont(font);
        actionSave_Ctrl_S = new QAction(MainWindow);
        actionSave_Ctrl_S->setObjectName(QStringLiteral("actionSave_Ctrl_S"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_Ctrl_S->setIcon(icon6);
        actionSave_Ctrl_S->setFont(font);
        actionSave_As_F12 = new QAction(MainWindow);
        actionSave_As_F12->setObjectName(QStringLiteral("actionSave_As_F12"));
        actionSave_As_F12->setIcon(icon6);
        actionSave_As_F12->setFont(font);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/Images/filenew.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon7);
        actionNew->setFont(font);
        actionGet_Help_Online_2 = new QAction(MainWindow);
        actionGet_Help_Online_2->setObjectName(QStringLiteral("actionGet_Help_Online_2"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/Images/defaulticon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGet_Help_Online_2->setIcon(icon8);
        actionGet_Help_Online_2->setFont(font);
        actionEncryption = new QAction(MainWindow);
        actionEncryption->setObjectName(QStringLiteral("actionEncryption"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/Images/encrypted.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEncryption->setIcon(icon9);
        actionAdd_New_Category = new QAction(MainWindow);
        actionAdd_New_Category->setObjectName(QStringLiteral("actionAdd_New_Category"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/Images/accessories-text-editor.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_New_Category->setIcon(icon10);
        actionAdd_New_Category->setFont(font);
        actionHelpimage = new QAction(MainWindow);
        actionHelpimage->setObjectName(QStringLiteral("actionHelpimage"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/Images/help-browser.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelpimage->setIcon(icon11);
        actionAbout_SecureShield = new QAction(MainWindow);
        actionAbout_SecureShield->setObjectName(QStringLiteral("actionAbout_SecureShield"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/Images/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout_SecureShield->setIcon(icon12);
        actionAbout_SecureShield->setFont(font);
        actionSearchFunction = new QAction(MainWindow);
        actionSearchFunction->setObjectName(QStringLiteral("actionSearchFunction"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/Images/find.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSearchFunction->setIcon(icon13);
        actionShow_Toolbar = new QAction(MainWindow);
        actionShow_Toolbar->setObjectName(QStringLiteral("actionShow_Toolbar"));
        actionShow_Toolbar->setCheckable(true);
        actionShow_Toolbar->setChecked(true);
        actionShow_Toolbar->setFont(font);
        actionAbout_SecureShield_2 = new QAction(MainWindow);
        actionAbout_SecureShield_2->setObjectName(QStringLiteral("actionAbout_SecureShield_2"));
        actionAbout_SecureShield_2->setCheckable(true);
        actionAbout_SecureShield_2->setChecked(false);
        QIcon icon14;
        icon14.addFile(QStringLiteral("../../../Documents/Xcode Applications/Yates Apps. /SecureShieldQT.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout_SecureShield_2->setIcon(icon14);
        actionAbout_SecureShield_2->setFont(font);
        actionHide_SecureShield = new QAction(MainWindow);
        actionHide_SecureShield->setObjectName(QStringLiteral("actionHide_SecureShield"));
        actionHide_SecureShield_2 = new QAction(MainWindow);
        actionHide_SecureShield_2->setObjectName(QStringLiteral("actionHide_SecureShield_2"));
        actionQuit_SecureShield = new QAction(MainWindow);
        actionQuit_SecureShield->setObjectName(QStringLiteral("actionQuit_SecureShield"));
        actionSecurity_2 = new QAction(MainWindow);
        actionSecurity_2->setObjectName(QStringLiteral("actionSecurity_2"));
        actionSecurity_3 = new QAction(MainWindow);
        actionSecurity_3->setObjectName(QStringLiteral("actionSecurity_3"));
        actionAddEntry = new QAction(MainWindow);
        actionAddEntry->setObjectName(QStringLiteral("actionAddEntry"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/Images/addKey.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddEntry->setIcon(icon15);
        actionDeleteEntry = new QAction(MainWindow);
        actionDeleteEntry->setObjectName(QStringLiteral("actionDeleteEntry"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/Images/deleteKey.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDeleteEntry->setIcon(icon16);
        actionEditEntry = new QAction(MainWindow);
        actionEditEntry->setObjectName(QStringLiteral("actionEditEntry"));
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/Images/editKey.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEditEntry->setIcon(icon17);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        treeWidget = new QTreeWidget(centralwidget);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(45, 60, 690, 461));
        treeWidget->setColumnCount(4);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(744, 15, 57, 32));
        QFont font1;
        font1.setFamily(QStringLiteral("Corbel"));
        font1.setPointSize(12);
        pushButton->setFont(font1);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(12, 20, 25, 16));
        label->setFont(font1);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setEnabled(true);
        textEdit->setGeometry(QRect(45, 15, 690, 31));
        textEdit->setAutoFillBackground(true);
        textEdit->setReadOnly(false);
        textEdit->setOverwriteMode(true);
        textEdit->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextEditable|Qt::TextEditorInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menu_Edit = new QMenu(menubar);
        menu_Edit->setObjectName(QStringLiteral("menu_Edit"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp_2 = new QMenu(menubar);
        menuHelp_2->setObjectName(QStringLiteral("menuHelp_2"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menubar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMovable(true);
        toolBar->setIconSize(QSize(16, 16));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menu_Edit->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuHelp_2->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionNew);
        menuFile->addAction(action_File);
        menuFile->addAction(actionSave_Ctrl_S);
        menuFile->addAction(actionSave_As_F12);
        menuFile->addSeparator();
        menu_Edit->addAction(action_Undo);
        menu_Edit->addAction(action_Redo);
        menu_Edit->addSeparator();
        menu_Edit->addAction(action_Cut);
        menu_Edit->addAction(actionCopy);
        menu_Edit->addAction(actionFormat);
        menu_Edit->addSeparator();
        menu_Edit->addAction(action_Format);
        menuTools->addAction(actionShow_Toolbar);
        menuHelp->addAction(actionGet_Help_Online_2);
        menuHelp->addAction(actionAbout_SecureShield);
        toolBar->addAction(action_File);
        toolBar->addAction(actionSave_Ctrl_S);
        toolBar->addSeparator();
        toolBar->addAction(action_Undo);
        toolBar->addAction(action_Redo);
        toolBar->addSeparator();
        toolBar->addAction(actionAddEntry);
        toolBar->addAction(actionEditEntry);
        toolBar->addAction(actionDeleteEntry);
        toolBar->addSeparator();
        toolBar->addAction(actionHelpimage);
        toolBar->addAction(actionEncryption);
        toolBar->addSeparator();
        toolBar->addAction(actionSearchFunction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Secure Shield", 0));
        action_File->setText(QApplication::translate("MainWindow", "&Open     Ctrl+O", 0));
        action_Undo->setText(QApplication::translate("MainWindow", "Undo       Ctrl+Z", 0));
        action_Redo->setText(QApplication::translate("MainWindow", "Redo       Ctrl+Y", 0));
        action_Cut->setText(QApplication::translate("MainWindow", "&Cut          Ctrl+X", 0));
        actionCopy->setText(QApplication::translate("MainWindow", "Copy       Ctrl+C", 0));
        actionFormat->setText(QApplication::translate("MainWindow", "&Paste      Ctrl+V", 0));
        action_Format->setText(QApplication::translate("MainWindow", "Show Clipboard", 0));
        actionSave_Ctrl_S->setText(QApplication::translate("MainWindow", "Save      Ctrl+S", 0));
        actionSave_As_F12->setText(QApplication::translate("MainWindow", "Save As...", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New       Ctrl+N", 0));
        actionGet_Help_Online_2->setText(QApplication::translate("MainWindow", "Get Help Online", 0));
        actionEncryption->setText(QApplication::translate("MainWindow", "Encryption", 0));
        actionAdd_New_Category->setText(QApplication::translate("MainWindow", "Add New Category", 0));
        actionHelpimage->setText(QApplication::translate("MainWindow", "Helpimage", 0));
        actionAbout_SecureShield->setText(QApplication::translate("MainWindow", "About SecureShield", 0));
        actionSearchFunction->setText(QApplication::translate("MainWindow", "searchFunction", 0));
        actionShow_Toolbar->setText(QApplication::translate("MainWindow", "Show Toolbar", 0));
        actionAbout_SecureShield_2->setText(QApplication::translate("MainWindow", "About SecureShield", 0));
        actionHide_SecureShield->setText(QApplication::translate("MainWindow", "Hide SecureShield", 0));
        actionHide_SecureShield_2->setText(QApplication::translate("MainWindow", "Hide SecureShield", 0));
        actionQuit_SecureShield->setText(QApplication::translate("MainWindow", "Quit SecureShield", 0));
        actionSecurity_2->setText(QApplication::translate("MainWindow", "General", 0));
        actionSecurity_3->setText(QApplication::translate("MainWindow", "Security", 0));
        actionAddEntry->setText(QApplication::translate("MainWindow", "addEntry", 0));
        actionDeleteEntry->setText(QApplication::translate("MainWindow", "deleteEntry", 0));
        actionEditEntry->setText(QApplication::translate("MainWindow", "editEntry", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(3, QApplication::translate("MainWindow", "Strength", 0));
        ___qtreewidgetitem->setText(2, QApplication::translate("MainWindow", "Date added", 0));
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "Password", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Name", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Go", 0));
        label->setText(QApplication::translate("MainWindow", "Find:", 0));
        textEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Corbel'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menu_Edit->setTitle(QApplication::translate("MainWindow", "&Edit", 0));
        menuTools->setTitle(QApplication::translate("MainWindow", "View", 0));
        menuHelp_2->setTitle(QApplication::translate("MainWindow", "Tools", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
        toolBar->setProperty("searchBar", QVariant(QString()));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
