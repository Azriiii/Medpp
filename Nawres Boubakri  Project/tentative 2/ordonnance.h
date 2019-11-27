#ifndef ORDONNANCE_H
#define ORDONNANCE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QDate>

class ordonnance
{
public:
    ordonnance();
    ordonnance(int,QDate,int,int,QString);
    int get_reff_ord();
    QDate get_date_ord();
    int get_id_patient();
    int get_reff_const();
    QString get_traitement();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool modifier(int,QDate,int,int,QString);
    bool supprimer(int);
private :
     int reff_ord,id_patient,reff_const;
     QDate date_ord;
     QString traitement;
};

#endif // ORDONNANCE_H




