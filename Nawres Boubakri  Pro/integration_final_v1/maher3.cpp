#include "maher3.h"
#include <QDebug>
#include <QDateTime>


maher3::maher3()
{
NOM_FOURNISSEUR="";
TYPE_PRODUIT="";
 ID_FOURNISSEUR=0;
 DUREE_CONTRAT=0;


}
maher3::maher3(int ID_FOURNISSEUR, QString TYPE_PRODUIT,QString NOM_FOURNISSEUR, int DUREE_CONTRAT)
{

this->NOM_FOURNISSEUR=NOM_FOURNISSEUR ;
this->TYPE_PRODUIT=TYPE_PRODUIT;
this->ID_FOURNISSEUR=ID_FOURNISSEUR ;
this->DUREE_CONTRAT=DUREE_CONTRAT ;

}

QString maher3::get_NOM_FOURNISSEUR(){return NOM_FOURNISSEUR ;}
QString maher3::get_TYPE_PRODUIT(){return TYPE_PRODUIT ;}

int maher3::get_ID_FOURNISSEUR(){return ID_FOURNISSEUR ;}
int maher3::get_DUREE_CONTRAT(){return DUREE_CONTRAT ;}


bool maher3::ajouter2()
{
    QSqlQuery query;
  

    query.prepare("INSERT INTO FOURNISSEUR ( ID_FOURNISSEUR , TYPE_PRODUIT , NOM_FOURNISSEUR , DUREE_CONTRAT ) "
                        "VALUES (:ID_FOURNISSEUR, :TYPE_PRODUIT, :NOM_FOURNISSEUR, :DUREE_CONTRAT)");

    query.bindValue(":NOM_FOURNISSEUR", NOM_FOURNISSEUR);
    query.bindValue(":TYPE_PRODUIT", TYPE_PRODUIT);
    query.bindValue(":ID_FOURNISSEUR", ID_FOURNISSEUR);
    query.bindValue(":DUREE_CONTRAT", DUREE_CONTRAT);



    return    query.exec();

}



QSqlQueryModel * maher3::afficher2()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from FOURNISSEUR");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FOURNISSEUR "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DUREE_CONTRAT"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM_FOURNISSEUR"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_FACT"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("TYPE_PRODUIT"));

    return model;
}

bool maher3::supprimer2(int ID_FOURNISSEUR )
{
QSqlQuery query;
QString res= QString::number(ID_FOURNISSEUR);
query.prepare("Delete from FOURNISSEUR where ID_FOURNISSEUR = :ID_FOURNISSEUR ");
query.bindValue(":ID_FOURNISSEUR", res);
return    query.exec();
}

bool maher3::modifier2(int ID_FOURNISSEUR , QString TYPE_PRODUIT ,QString NOM_FOURNISSEUR , int DUREE_CONTRAT)
{
QSqlQuery query ;
query.prepare("UPDATE FOURNISSEUR SET  ID_FOURNISSEUR= :ID_FOURNISSEUR , DUREE_CONTRAT= :DUREE_CONTRAT , NOM_FOURNISSEUR= :NOM_FOURNISSEUR  , TYPE_PRODUIT = :TYPE_PRODUIT where ID_FOURNISSEUR= :ID_FOURNISSEUR ");
query.bindValue(":ID_FOURNISSEUR",ID_FOURNISSEUR) ;
query.bindValue(":DUREE_CONTRAT",DUREE_CONTRAT);
query.bindValue(":NOM_FOURNISSEUR",NOM_FOURNISSEUR);
query.bindValue(":TYPE_PRODUIT",TYPE_PRODUIT);
return    query.exec();

}
