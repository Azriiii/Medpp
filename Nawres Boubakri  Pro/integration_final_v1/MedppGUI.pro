QT       += core gui sql printsupport widgets charts multimedia
QT       += core gui sql printsupport network charts

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
    class_patient.cpp \
    class_rdv.cpp \
    connection.cpp \
    consultation.cpp \
    consultations.cpp \
    donutbreakdownchart.cpp \
    equipement.cpp \
    equipementmed.cpp \
    fournisseurs.cpp \
    fourniture.cpp \
    fournitures.cpp \
    login.cpp \
    loginmed.cpp \
    loginsec.cpp \
    maher2.cpp \
    maher3.cpp \
    main.cpp \
    mainslice.cpp \
    mainwindow.cpp \
    medecin.cpp \
    numberformatdelegate.cpp \
    ordonances.cpp \
    ordonnance.cpp \
    patients.cpp \
    personelsm.cpp \
    personelsmed.cpp \
    rdv.cpp \
    secretaire.cpp \
    smtp.cpp \
    stafft.cpp \
    stafftechnique.cpp \
    stati.cpp \
    statpatient.cpp \
    stats.cpp

HEADERS += \
    admin.h \
    class_patient.h \
    class_rdv.h \
    connection.h \
    consultation.h \
    consultations.h \
    donutbreakdownchart.h \
    equipement.h \
    equipementmed.h \
    fournisseurs.h \
    fourniture.h \
    fournitures.h \
    login.h \
    loginmed.h \
    loginsec.h \
    maher2.h \
    maher3.h \
    mahoura.h \
    mainslice.h \
    mainwindow.h \
    medecin.h \
    numberformatdelegate.h \
    ordonances.h \
    ordonnance.h \
    patients.h \
    personelsm.h \
    personelsmed.h \
    rdv.h \
    secretaire.h \
    smtp.h \
    stafft.h \
    stafftechnique.h \
    stati.h \
    statpatient.h \
    stats.h

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
    patients.ui \
    personelsmed.ui \
    rdv.ui \
    secretaire.ui \
    stafftechnique.ui \
    stati.ui \
    statpatient.ui \
    stats.ui

QMAKE_CXXFLAGS+= -std=gnu++14

RC_ICONS= icon1.ico
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    reosurces.qrc

DISTFILES +=
