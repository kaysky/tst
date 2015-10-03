#-------------------------------------------------
#
# Project created by QtCreator 2014-03-19T23:06:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cli
TEMPLATE = app

###CONFIG += -std=c++11
QMAKE_CXXFLAGS += -std=c++11

SOURCES += cform.cpp\
		cli.cpp

HEADERS  += cform.hpp

FORMS    += cli.ui
