#-------------------------------------------------
#
# Project created by QtCreator 2015-02-28T02:43:15
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTtest
TEMPLATE = app


SOURCES += main.cpp\
    application.cpp \
    grostlimpl.cpp \
    qgrostlhash.cpp \
    login.cpp \
    startmenu.cpp \
    mainwindow.cpp

HEADERS  += \
    application.h \
    qgrostlhash.h \
    login.h \
    startmenu.h \
    mainwindow.h

FORMS    += \
    application.ui \
    login.ui \
    mainwindow.ui

DISTFILES += \
    login.db
