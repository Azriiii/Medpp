QT       += core gui sql printsupport

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
    consultations.cpp \
    equipementmed.cpp \
    fournisseurs.cpp \
    fourniture.cpp \
    login.cpp \
    loginmed.cpp \
    loginsec.cpp \
    main.cpp \
    mainwindow.cpp \
    medecin.cpp \
    numberformatdelegate.cpp \
    ordonances.cpp \
    personelsm.cpp \
    personelsmed.cpp \
    secretaire.cpp \
    stafft.cpp \
    stafftechnique.cpp

HEADERS += \
    admin.h \
    connection.h \
    consultations.h \
    equipementmed.h \
    fournisseurs.h \
    fourniture.h \
    login.h \
    loginmed.h \
    loginsec.h \
    mainwindow.h \
    medecin.h \
    numberformatdelegate.h \
    ordonances.h \
    personelsm.h \
    personelsmed.h \
    secretaire.h \
    stafft.h \
    stafftechnique.h

FORMS += \
    admin.ui \
    consultations.ui \
    equipementmed.ui \
    fournisseurs.ui \
    fourniture.ui \
    login.ui \
    loginmed.ui \
    loginsec.ui \
    mainwindow.ui \
    medecin.ui \
    ordonances.ui \
    personelsmed.ui \
    secretaire.ui \
    stafftechnique.ui

QMAKE_CXXFLAGS+= -std=gnu++14

RC_ICONS= icon1.ico
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    reosurces.qrc

DISTFILES +=
