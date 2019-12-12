#ifndef CLASS_RDV_H
#define CLASS_RDV_H
#include <QSqlQuery>
#include <QSqlQueryModel>

class class_rdv
{
    int id_patient;
    QString date_rdv;
    int etat_rdv;
    int num_rdv;
public:
    class_rdv();
    class_rdv(int,QString,int,int);
    int get_id_patient();
    QString get_date_rdv();
    int get_etat_rdv();
    int get_num();
    bool ajouter();
    QSqlQueryModel * afficher();
bool modifier(int,QString,int,int);
       QSqlQueryModel * trier();
              QSqlQueryModel * rechercher(int);

    bool supprimer(int);
};

#endif // CLASS_RDV_H
