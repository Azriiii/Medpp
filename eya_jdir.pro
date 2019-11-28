QT       += core gui
QT       += core sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
QT       += core gui sql serialport
QT       +=widgets multimedia
QT       +=printsupport

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
    class_patient.cpp \
    class_rdv.cpp \
    mail.cpp \
    main.cpp \
    mainwindow.cpp \
    patient.cpp \
    patient_agent.cpp \
    qcustomplot.cpp \
    rdv_agent.cpp \
    redv.cpp \
    statis.cpp

HEADERS += \
    class_patient.h \
    class_rdv.h \
    mail.h \
    mainwindow.h \
    patient.h \
    patient_agent.h \
    qcustomplot.h \
    rdv_agent.h \
    redv.h \
    statis.h

FORMS += \
    mainwindow.ui \
    patient.ui \
    patient_agent.ui \
    rdv_agent.ui \
    redv.ui \
    statis.ui
    RC_ICONS=icon.ico
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    eya.qrc
