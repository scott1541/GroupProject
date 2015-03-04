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
        mainwindow.cpp \
    application.cpp \
    grostlimpl.cpp \
    qgrostlhash.cpp

HEADERS  += mainwindow.h \
    application.h \
    qgrostlhash.h

FORMS    += mainwindow.ui \
    application.ui

DISTFILES += \
    login.db
