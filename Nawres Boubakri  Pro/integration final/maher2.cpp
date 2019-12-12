#include "maher2.h"
#include <QDebug>
#include <QDateTime>

maher2::maher2()
{
ORDRE_DE="";
ETAT="";
 ID_FACTURE=0;
 RIB=0;


}
maher2::maher2( QString ORDRE_DE,QString ETAT,QDate DATE_FACT,int ID_FACTURE, int RIB)
{

this->ORDRE_DE=ORDRE_DE ;
this->ETAT=ETAT;
this->ID_FACTURE=ID_FACTURE ;
this->RIB=RIB ;
this->DATE_FACT=DATE_FACT ;

}

QString maher2::get_ORDRE_DE(){return ORDRE_DE ;}
QString maher2::get_ETAT(){return ETAT ;}
QDate maher2::get_DATE_FACT(){return DATE_FACT ;}

int maher2::get_ID_FACTURE(){return ID_FACTURE ;}
int maher2::get_RIB(){return RIB ;}


bool maher2::ajouter()
{
    QSqlQuery query;
    QDate res = DATE_FACT;
   /* QString res1= QString::number(tel);
    QString res2= QString::number(salaire);
    QString res3= QString::number(contrat);
    QString res4= QString::number(horaire);
    */

    query.prepare("INSERT INTO FACTURE ( ORDRE_DE , ETAT , ID_FACTURE , RIB , DATE_FACT ) "
                        "VALUES (:ORDRE_DE, :ETAT, :ID_FACTURE, :RIB, :DATE_FACT)");

    query.bindValue(":ORDRE_DE", ORDRE_DE);
    query.bindValue(":ETAT", ETAT);
    query.bindValue(":ID_FACTURE", ID_FACTURE);
    query.bindValue(":RIB", RIB);
    query.bindValue(":DATE_FACT", res);



    return    query.exec();

}



QSqlQueryModel * maher2::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from FACTURE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FACTURE "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("RIB"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ORDRE_DE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_FACT"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("ETAT"));

    return model;
}

bool maher2::supprimer(int ID_FACTURE )
{
QSqlQuery query;
QString res= QString::number(ID_FACTURE);
query.prepare("Delete from FACTURE where ID_FACTURE = :ID_FACTURE ");
query.bindValue(":ID_FACTURE", res);
return    query.exec();
}

bool maher2::modifier(int ID_FACTURE ,int RIB ,QDate DATE_FACT,QString ETAT ,QString ORDRE_DE)
{
QSqlQuery query ;
query.prepare("UPDATE FACTURE SET  ID_FACTURE= :ID_FACTURE , RIB= :RIB , ORDRE_DE= :ORDRE_DE , DATE_FACT = :DATE_FACT , ETAT = :ETAT where ID_FACTURE= :ID_FACTURE ");
query.bindValue(":ID_FACTURE",ID_FACTURE) ;
query.bindValue(":RIB",RIB);
query.bindValue(":ORDRE_DE",ORDRE_DE);
query.bindValue(":DATE_FACT",DATE_FACT);
query.bindValue(":ETAT",ETAT);
return    query.exec();

}
