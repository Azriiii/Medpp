#ifndef FOURNITURES_H
#define FOURNITURES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QAbstractItemModel>

class fournitures
{
public:
    fournitures();
    fournitures(int,QString,QString,int,int);
    int get_Ref_fourn();
    QString get_type_fourn();
    QString get_nom_fourn();
    int get_quant_fourn();
    int get_prix();

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
private:
    QString type_fourn,nom_fourn;
    int Ref_fourn;
     int prix;
     int quant_fourn;
};

#endif // FOURNITURES_H
