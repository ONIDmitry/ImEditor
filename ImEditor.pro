#-------------------------------------------------
#
# Project created by QtCreator 2017-05-18T12:33:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImEditor
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    typeresource.cpp \
    resource.cpp \
    patternoperation.cpp \
    operation.cpp \
    immodel.cpp \
    formcreatetyperesource.cpp \
    formcreateresource.cpp \
    formcreatepatternoperation.cpp \
    formcreateoperation.cpp \
    formedittyperesource.cpp \
    formeditresource.cpp \
    formeditpatternoperation.cpp \
    formeditoperation.cpp

HEADERS  += mainwindow.h \
    typeresource.h \
    resource.h \
    patternoperation.h \
    operation.h \
    immodel.h \
    formcreatetyperesource.h \
    formcreateresource.h \
    formcreatepatternoperation.h \
    formcreateoperation.h \
    formedittyperesource.h \
    formeditresource.h \
    formeditpatternoperation.h \
    formeditoperation.h

FORMS    += mainwindow.ui \
    formcreatetyperesource.ui \
    formcreateresource.ui \
    formcreatepatternoperation.ui \
    formcreateoperation.ui \
    formedittyperesource.ui \
    formeditresource.ui \
    formeditpatternoperation.ui \
    formeditoperation.ui

