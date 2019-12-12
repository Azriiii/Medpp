#ifndef MAHER2_H
#define MAHER2_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class maher2
{
public:
    maher2();
    maher2(QString,QString,QDate,int,int);
    QString get_ORDRE_DE();
    QString get_ETAT();
    QDate get_DATE_FACT();

    int get_ID_FACTURE();
    int get_RIB();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int ID_FACTURE ,int RIB ,QDate DATE_FACT,QString ETAT ,QString ORDRE_DE);
 private:
     QString ETAT,ORDRE_DE;
     QDate DATE_FACT ;
     int ID_FACTURE,RIB ;
};

#endif // MAHER2_H
