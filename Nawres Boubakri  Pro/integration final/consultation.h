#ifndef CONSULTATION_H
#define CONSULTATION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QDate>
#include <QTableView>

class Consultation
{
public:
    Consultation();
    //consultation(int,int,int);
    Consultation(int,QDate,QString,QString ,QString ,QString,int);
    int get_reff_const();
    int get_id_patient();
  // int get_date_const();
   QDate get_date_const();

   QString get_symptomes();
   QString get_diagnostique();
   QString get_examens_cliniques();
   QString get_res_examens_cliniques();


     bool ajouter();
     QSqlQueryModel * afficher();
    //bool modifier(int,int,int);
   bool modifier(int,QDate,QString,QString,QString,QString,int);
     bool supprimer(int);
     void recherche_consultation(QTableView *table,int);
     QSqlQueryModel * recherche();
     bool notifier();
     QSqlQueryModel * tri_reff_const();
     QSqlQueryModel * tri_reff_date();
     QSqlQueryModel * tri_reff_id();

     void imprimer();
     //QSqlQueryModel *recherche_consultation(int);
        QSqlQueryModel * stats();
        int grippe();
        int rougeole();
        int anemie();
        int diabete();
        int recherche_id(int);
private :
     int reff_const,id_patient ;
     QDate date_const;
     QString symptomes,diagnostique,examens_cliniques,res_examens_cliniques;
};

#endif // CONSULTATION_H


