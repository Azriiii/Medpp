#include "class_patient.h"

class_patient::class_patient()
{
    id_patient=0;
    nom_patient="";
    prenom_patient="";
    date_patient="";
    tel_patient=0;
    adresse="";
    sexe="";

}
class_patient::class_patient(int id_patient,QString nom_patient,QString prenom_patient, QString date_patient,int tel_patient,QString adresse,QString sexe )
{

    this->id_patient=id_patient;
    this->nom_patient=nom_patient;
    this->prenom_patient=prenom_patient;
    this->date_patient=date_patient;
    this->tel_patient=tel_patient;
    this->adresse=adresse;
    this->sexe=sexe;
}
int class_patient::get_id(){return id_patient;}
QString class_patient::get_nom(){return nom_patient;}
QString class_patient::get_prenom(){return  prenom_patient;}
 QString class_patient::get_date(){return date_patient;}
 int class_patient::get_tel(){return tel_patient;}
QString class_patient::get_adresse(){return  adresse;}
QString class_patient::get_sexe(){return  sexe;}
bool class_patient::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(id_patient);
    QString res2= (date_patient);
    QString res3= QString::number(tel_patient);
    query.prepare("INSERT INTO patient (ID_PATIENT,NOM_PATIENT,PRENOM_PATIENT,DATE_N,TEL,ADRESSE,SEXE) "
                        "VALUES (:id_patient,:nom_patient,:prenom_patient,:date_patient,:tel_patient,:adresse,:sexe)");
    query.bindValue(":id_patient", res);
    query.bindValue(":nom_patient", nom_patient);
    query.bindValue(":prenom_patient", prenom_patient);
    query.bindValue(":date_patient", res2);
    query.bindValue(":tel_patient", res3);
    query.bindValue(":adresse", adresse);
    query.bindValue(":sexe", sexe);
    return    query.exec();
}
QSqlQueryModel * class_patient::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from patient");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PATIENT"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PATIENT "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_PATIENT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_N"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("TEL"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("SEXE"));
    return model;
}
bool class_patient::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from patient where ID_PATIENT = :id_patient ");
query.bindValue(":id_patient", res);
return    query.exec();
}
bool class_patient::modifier(int id_patient,QString nom_patient,QString prenom_patient,QString date_patient,int tel_patient,QString adresse,QString sexe)
{
    QString res= QString::number(id_patient);
    QString res2= (date_patient);
    QString res3= QString::number(tel_patient);
        QSqlQuery query;
         query.prepare("UPDATE patient set ID_PATIENT =:id_patient,NOM_PATIENT=:nom_patient , PRENOM_PATIENT= :prenom_patient,DATE_N=:date_patient,TEL=:tel_patient,ADRESSE= :adresse ,SEXE= :sexe where ID_PATIENT =:id_patient");
         query.bindValue(":id_patient", res);
         query.bindValue(":nom_patient", nom_patient);
         query.bindValue(":prenom_patient", prenom_patient);
         query.bindValue(":date_patient", res2);
         query.bindValue(":tel_patient", res3);
         query.bindValue(":adresse", adresse);
          query.bindValue(":sexe", sexe);
        return    query.exec();


}
QSqlQueryModel * class_patient::trier()
{

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from patient ORDER BY DATE_N");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PATIENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PATIENT "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_PATIENT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_N"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TEL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE"));
        return model;
}
QSqlQueryModel * class_patient::rechercher(int cin)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery c;
    QString res= QString::number(cin);
    c.prepare("Select * from patient where ID_PATIENT=:cin");
    c.bindValue(":cin",res);
    c.exec();
    model->setQuery(c);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PATIENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PATIENT "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_PATIENT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_N"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TEL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE"));

        return model;


}
