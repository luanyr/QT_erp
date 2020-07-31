QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_new.cpp \
    add_proinfo.cpp \
    database.cpp \
    log_dia.cpp \
    login.cpp \
    main.cpp \
    modify_proinfo.cpp \
    pro_format.cpp \
    user_format.cpp \
    widget.cpp

HEADERS += \
    add_new.h \
    add_proinfo.h \
    database.h \
    log_dia.h \
    login.h \
    modify_proinfo.h \
    pro_format.h \
    user_format.h \
    widget.h

FORMS += \
    add_new.ui \
    add_proinfo.ui \
    log_dia.ui \
    login.ui \
    modify_proinfo.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
