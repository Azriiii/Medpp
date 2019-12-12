#ifndef PERSONELSM_H
#define PERSONELSM_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class PersonelsM
{
public:
   PersonelsM();
   PersonelsM(QString,QString,QString,QString,QDate,QString,int,int,int,int,int,QString);
   QString get_occupation();
   QString get_specialite();
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
   int medcalM() ;
   int medcalF() ;
   QSqlQueryModel * afficher();
   bool supprimer(int);
   QSqlQueryModel * trier1 () ;
   QSqlQueryModel * trier2 () ;
   QSqlQueryModel * trier3 () ;
   QSqlQueryModel * trier4 () ;
   QSqlQueryModel * trier5 () ;
   QSqlQueryModel * trier6 () ;
   QSqlQuery recherche1(QString) ;
   QSqlQuery recherche2(QString) ;
private:
    QString occupation,specialite,nom,prenom,sexe,mail ;
    QDate date ;
    int CIN,tel,salaire,contrat,horaire ;
};

#endif // PERSONELSM_H
