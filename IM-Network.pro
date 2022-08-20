#-------------------------------------------------
#
# Project created by QtCreator 2022-08-20T10:50:45
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IM-Network
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
    ApiUtils/packet.cpp \
    ApiUtils/socket_utils.cpp \
    ApiUtils/api_utils.cpp \
    ApiUtils/tools/byte_convert.cpp \
    ApiUtils/tools/logger.cpp

HEADERS  += mainwindow.h \
    ApiUtils/packet.h \
    ApiUtils/socket_utils.h \
    ApiUtils/api_utils.h \
    ApiUtils/tools/byte_convert.h \
    ApiUtils/tools/logger.h

FORMS    += mainwindow.ui

OBJECTS_DIR  = tmp
MOC_DIR      = tmp
