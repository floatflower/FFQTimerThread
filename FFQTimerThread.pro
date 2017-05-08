#-------------------------------------------------
#
# Project created by QtCreator 2017-05-08T10:10:46
#
#-------------------------------------------------

QT       -= gui

TARGET = ffqtimerthread
TEMPLATE = lib

DEFINES += FFQTIMERTHREAD_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += qtimerthread.cpp

HEADERS += qtimerthread.h\
        ffqtimerthread_global.h

isEmpty(PREFIX):PREFIX = /usr
isEmpty(LIBDIR):LIBDIR = $${PREFIX}/lib
isEmpty(INCLUDEDIR):INCLUDEDIR = $${PREFIX}/include

PUBLIC_HEADERS += qtimerthread.h ffqtimerthread_global.h

unix {
    target.path = $$LIBDIR
    headers.path = $${INCLUDEDIR}/ff
    headers.files = $$PUBLIC_HEADERS
    INSTALLS += target headers
}

DISTFILES += \
    README.md
