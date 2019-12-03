#ifndef ORDONNANCE_H
#define ORDONNANCE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QDate>
#include<QTableView>

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
    QSqlQueryModel * tri_reff_const();
     QSqlQueryModel * tri_reff_date();
      QSqlQueryModel * tri_reff_ord();
      void recherche_ordonnance(QTableView *table , int reff_const);
      void sauvegarder();
      int fervexe();
      int doliprane();
      int aspirine();
      int panadole();
private :
     int reff_ord,id_patient,reff_const;
     QDate date_ord;
     QString traitement;
};

#endif // ORDONNANCE_H




