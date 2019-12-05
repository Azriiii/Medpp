#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QAbstractItemModel>
class equipement
{
public:
     equipement();
     equipement(int,QString,int,int);
    int get_Ref_equip();
    QString get_type_equip();
    int get_quant_equip();
    int get_prix();

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
private:
    QString type_equip;
    int Ref_equip;
     int prix;
     int quant_equip;
};

#endif // EQUIPEMENT_H
