#include "ordonnance.h"
#include <QDebug>
ordonnance::ordonnance()
{
    id_patient=0;
    reff_ord=0;
    reff_const=0;
    traitement=" ";
}
ordonnance::ordonnance(int reff_ord,QDate date_ord,int id_patient,int reff_const,QString traitement)
{
    this->id_patient=id_patient;
    this->reff_ord=reff_ord;
    this->reff_const=reff_const;
    this->date_ord=date_ord;
    this->traitement=traitement;
}







int ordonnance::get_reff_ord(){return reff_ord;}
QDate ordonnance::get_date_ord(){return  date_ord;}
int ordonnance::get_reff_const(){return reff_const;}
int ordonnance::get_id_patient(){return id_patient;}
QString ordonnance::get_traitement(){return traitement;}

bool ordonnance::ajouter()
{
QSqlQuery query;
QString res= QString::number(reff_ord);
query.prepare("INSERT INTO ordonnance (REFF_ORD, DATE_ORD, REFF_CONST, ID_PATIENT, TRAITEMENT ) "
                    "VALUES (:reff_ord, :date_ord, :reff_const, :id_patient, :traitement)");
query.bindValue(":reff_ord", res);
query.bindValue(":date_ord", date_ord);
query.bindValue(":reff_const",reff_const );
query.bindValue(":id_patient", id_patient);
query.bindValue(":traitement", traitement);

return    query.exec();
}

QSqlQueryModel * ordonnance::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from ordonnance");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("reff_ord"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_ord "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("reff_const"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("id_patient"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("traitement"));
    return model;
}



bool ordonnance::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from ordonnance where REFF_ORD = :idd ");
query.bindValue(":idd", res);
return    query.exec();
}
bool ordonnance :: modifier(int reff_ord,QDate date_ord,int id_patient,int reff_const,QString traitement)
{

    QSqlQuery query;
    QString res= QString::number(reff_ord);

    query.prepare("update ordonnance set reff_ord='" +QString::number(reff_ord)+"', id_patient='"+QString::number(id_patient)+"', reff_const='"+QString::number(reff_const)+"', date_ord= :date_ord, traitement=:traitement where REFF_ORD="+QString::number(reff_ord));
    query.bindValue(":reff_ord",res);
    query.bindValue(":date_ord",date_ord);
    query.bindValue(":id_patient",id_patient);
    query.bindValue(":reff_const",reff_const);
    query.bindValue(":traitement",traitement);
    return    query.exec();


}

