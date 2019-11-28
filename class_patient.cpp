#include "class_patient.h"
#include <QDebug>

class_patient::class_patient()
{
    id_patient=0;
    nom_patient="";
    prenom_patient="";
    date_patient="";
    tel_patient=0;
    adresse="";

}
class_patient::class_patient(int id_patient,QString nom_patient,QString prenom_patient, QString date_patient,int tel_patient,QString adresse )
{

    this->id_patient=id_patient;
    this->nom_patient=nom_patient;
    this->prenom_patient=prenom_patient;
    this->date_patient=date_patient;
    this->tel_patient=tel_patient;
    this->adresse=adresse;
}
int class_patient::get_id(){return id_patient;}
QString class_patient::get_nom(){return nom_patient;}
QString class_patient::get_prenom(){return  prenom_patient;}
 QString class_patient::get_date(){return date_patient;}
int class_patient::get_tel(){return tel_patient;}
QString class_patient::get_adresse(){return  adresse;}
bool class_patient::ajouter()
{
QSqlQuery query;
QString res= QString::number(id_patient);
QString res2= (date_patient);
QString res3= QString::number(tel_patient);
query.prepare("INSERT INTO patient (ID_PATIENT,NOM_PATIENT,PRENOM_PATIENT,DATE_N,TEL,ADRESSE) "
                    "VALUES (:id_patient,:nom_patient,:prenom_patient,:date_patient,:tel_patient,:adresse)");
query.bindValue(":id_patient", res);
query.bindValue(":nom_patient", nom_patient);
query.bindValue(":prenom_patient", prenom_patient);
query.bindValue(":date_patient", res2);
query.bindValue(":tel_patient", res3);
query.bindValue(":adresse", adresse);
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
bool class_patient::update()
{

    QSqlQuery query;
        int first=0 ;
     QString res= QString::number(tel_patient);
            QString res1=QString::number(id_patient);
            QString res3= (date_patient);
             QString editer="Update PATIENT set" ;
            query.bindValue(":nom_patient",nom_patient);
            if(nom_patient!="")
            {
                editer+=" NOM_PATIENT = :nom_patient" ;
                first=1 ;
            }

            query.bindValue(":prenom_patient",prenom_patient);
            if(prenom_patient!=""&& first!=0)
                editer+=" ,PRENOM_PATIENT= :prenom_patient" ;
            else if (prenom_patient!=""&&first==0)
              {
                editer+=" PRENOM_PATIENT= :prenom_patient" ;
                first=1 ;
              }
                 query.bindValue(":date_patient",date_patient);
                 if(res3!=""&& first!=0)
                     editer+=" , DATE_N= :date_patient" ;
                 else if (res3!="" && first==0)
                 {
                    editer+="  DATE_N= :date_patient" ;
                    first=1 ;
                 }


                   query.bindValue(":tel_patient",tel_patient);
                   if(res!=""&& first!=0)
                       editer+=" ,TEL = :tel_patient" ;
                   else if (res!=""&&first==0)
                   {
                     editer+=" TEL= :tel_patient" ;
                     first=1 ;
                   }

                   query.bindValue(":adresse",adresse);
                   if(adresse!=""&& first!=0)
                       editer+=" ,ADRESSE = :adresse" ;
                   else if (adresse!=""&&first==0)
                   {
                     editer+=" ADRESSE= :adresse" ;
                     first=1 ;
                   }

                   editer+=" where ID_PATIENT = :id_patient" ;



                   QByteArray chaine = editer.toLocal8Bit();
                   const char *final = chaine.data();


                query.prepare(final);


             query.bindValue(":id_patient",QVariant(res1).toInt());
             query.bindValue(":nom_patient",nom_patient);
            query.bindValue(":prenom_patient",prenom_patient);



                   query.bindValue(":date_patient",QVariant(res3).toInt());
                    query.bindValue(":tel_patient",QVariant(res).toInt());
                     query.bindValue(":adresse",adresse);


             return query.exec();
}


QSqlQueryModel * class_patient::trier()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from patient order by ID_PATIENT ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PATIENT"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PATIENT "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_PATIENT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_N"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("TEL"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE"));

    return model;
}
QSqlQueryModel * class_patient::showidpatient()
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select ID_PATIENT from patient  ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PATIENT"));

}



