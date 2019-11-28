#include "class_rdv.h"

class_rdv::class_rdv()
{
id_patient=0;
date_rdv="";
etat_rdv=0;
num_rdv=0;
}
class_rdv::class_rdv(int id_patient,QString date_rdv,int etat_rdv,int num_rdv)
{
    this->id_patient=id_patient;
    this->date_rdv=date_rdv;
    this->etat_rdv=etat_rdv;
    this->num_rdv=num_rdv;

}
int class_rdv::get_num(){return num_rdv;}
int class_rdv::get_id_patient(){return id_patient;}
QString class_rdv::get_date_rdv(){return date_rdv;}
int class_rdv::get_etat_rdv(){return etat_rdv;}
bool class_rdv::ajouter()
{
QSqlQuery query;
QString res= QString::number(id_patient);
QString res2=date_rdv;
QString res3= QString::number(etat_rdv);
QString res4= QString::number(num_rdv);
query.prepare("INSERT INTO rdv (NUM_RDV,DATE_RDV,ETAT_RDV,ID_PATIENT) "
                    "VALUES (:num_rdv,:date_rdv,:etat_rdv,:id_patient)");
query.bindValue(":num_rdv", res4);
query.bindValue(":date_rdv", res2);
query.bindValue(":etat_rdv", res3);
query.bindValue(":id_patient", res);
return    query.exec();
}
QSqlQueryModel * class_rdv::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from rdv");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_RDV"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_RDV "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT_RDV"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_PATIENT"));


    return model;
}
bool class_rdv::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from rdv where ID_PATIENT = :id_patient ");
query.bindValue(":id_patient", res);
return    query.exec();
}

QSqlQueryModel * class_rdv::trier()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from rdv order by DATE_RDV ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_RDV"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_RDV "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT_RDV"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_PATIENT"));


    return model;
}


QSqlQueryModel *class_rdv::rechercherrdv(QString date)
{


QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from rdv where DATE_RDV like '"+date+"' ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_RDV"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_RDV "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT_RDV"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_PATIENT"));
return model;
}


