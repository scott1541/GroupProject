#-------------------------------------------------
#
# Project created by QtCreator 2015-02-28T13:32:52
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SecureShield
TEMPLATE = app


SOURCES += main.cpp\
        startmenu.cpp \
    mainwindow.cpp \
    password.cpp \
    addpassword.cpp \
    qgrostlhash.cpp \
    grostlimpl.cpp

HEADERS  += startmenu.h \
    mainwindow.h \
    password.h \
    addpassword.h \
    qgrostlhash.h

FORMS    += startmenu.ui \
    mainwindow.ui \
    password.ui \
    addpassword.ui

RESOURCES += \
    rescources.qrc
