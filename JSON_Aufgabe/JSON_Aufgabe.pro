QT += core
QT -= gui

TARGET = JSON_Aufgabe
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    parser_json.cpp

HEADERS += \
    parser_json.h

