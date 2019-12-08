#ifndef MAHER3_H
#define MAHER3_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QtCore>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QtGui>

class maher3
{
public:
    maher3();
    maher3(int,QString,QString,int);
    int get_ID_FOURNISSEUR();
    QString get_TYPE_PRODUIT();
    QString get_NOM_FOURNISSEUR();
     int get_DUREE_CONTRAT();


    bool ajouter2();
    QSqlQueryModel * afficher2();
    bool supprimer2(int);
    bool modifier2(int ID_FOURNISSEUR ,QString TYPE_PRODUIT,QString NOM_FOURNISSEUR ,int DUREE_CONTRAT);
 private:
     QString NOM_FOURNISSEUR,TYPE_PRODUIT;
     int ID_FOURNISSEUR,DUREE_CONTRAT ;

};
#endif // MAHER3_H
