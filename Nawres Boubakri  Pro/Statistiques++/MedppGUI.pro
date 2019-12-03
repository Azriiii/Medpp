QT       += core gui sql printsupport multimedia charts

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
    admin.cpp \
    connection.cpp \
    consultation.cpp \
    consultations.cpp \
    donutbreakdownchart.cpp \
    login.cpp \
    loginmed.cpp \
    loginsec.cpp \
    main.cpp \
    mainslice.cpp \
    mainwindow.cpp \
    medecin.cpp \
    ordonances.cpp \
    ordonnance.cpp \
    personelsm.cpp \
    personelsmed.cpp \
    secretaire.cpp \
    qcustomplot.cpp \
    statistique.cpp \
    statistiques.cpp \
    stats.cpp

HEADERS += \
    admin.h \
    connection.h \
    consultation.h \
    consultations.h \
    donutbreakdownchart.h \
    login.h \
    loginmed.h \
    loginsec.h \
    mainslice.h \
    mainwindow.h \
    medecin.h \
    ordonances.h \
    ordonnance.h \
    personelsm.h \
    personelsmed.h \
    secretaire.h \
    qcustomplot.h \
    statistique.h \
    statistiques.h \
    stats.h

FORMS += \
    admin.ui \
    consultations.ui \
    login.ui \
    loginmed.ui \
    loginsec.ui \
    mainwindow.ui \
    medecin.ui \
    ordonances.ui \
    personelsmed.ui \
    secretaire.ui \
    statistiques.ui \
    stats.ui
RC_ICONS= icon1.ico
QMAKE_CXXFLAGS+= -std=gnu++14

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    reosurces.qrc

DISTFILES +=
