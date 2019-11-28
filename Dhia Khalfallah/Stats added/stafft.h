#ifndef STAFFT_H
#define STAFFT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class stafft
{
public:
    stafft();
    stafft(QString,QString,QString,QString,QDate,QString,int,int,int,int,int,QString);
    QString get_occupation();
    QString get_role();
    QString get_nom();
    QString get_prenom();
    QDate get_date();
    QString get_sexe();
    QString get_mail();

    int get_cin();
    int get_tel();
    int get_salaire();
    int get_contrat();
    int get_horaire();
    bool ajouter();
    bool modifier(QString,QString,QString,QString,QString,QDate,QString,QString,QString,QString,QString,QString,QString);
    int stcalM() ;
    int stcalF() ;
    QSqlQueryModel * afficher();
    bool supprimer(int);
 private:
     QString occupation,role,nom,prenom,sexe,mail ;
     QDate date ;
     int CIN,tel,salaire,contrat,horaire ;
};

#endif // STAFFT_H
