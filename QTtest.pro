#-------------------------------------------------
#
# Project created by QtCreator 2015-02-28T02:43:15
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTtest
TEMPLATE = app


SOURCES += main.cpp \
    Login.cpp \
    grostlimpl.cpp \
    moc_mainwindow.cpp \
    qgrostlhash.cpp \
    debug/moc_mainwindow.cpp

HEADERS  += \
    Login.h \
    qgrostlhash.h \
    ui_mainwindow.h

FORMS    += \
    login.ui

DISTFILES += \
    login.db
