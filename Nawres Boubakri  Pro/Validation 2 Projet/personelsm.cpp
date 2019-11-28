#include "personelsm.h"
#include <QDebug>
#include <QDateTime>
PersonelsM::PersonelsM()
{
occupation="";
specialite="";
nom="";
prenom="";
date="";
sexe="";
mail="";
 CIN=0;
 tel=0;
 salaire=0;
 contrat=0;
 horaire=0;

}
PersonelsM::PersonelsM( QString occupation,QString specialite,QString nom,QString prenom,QString date,QString sexe, int CIN, int tel, int salaire, int contrat, int horaire ,QString mail)
{

this->occupation=occupation ;
this->specialite=specialite;
this->nom=nom ;
this->prenom=prenom ;
this->date=date ;
this->sexe=sexe ;
this->CIN=CIN ;
this->tel=tel ;
this->salaire=salaire ;
this->contrat=contrat ;
this->horaire=horaire ;
this->mail=mail ;
}

QString PersonelsM::get_occupation(){return occupation ;}
QString PersonelsM::get_specialite(){return specialite ;}
QString PersonelsM::get_nom(){return nom ;}
QString PersonelsM::get_prenom(){return prenom ;}
QString PersonelsM::get_date(){return date ;}
QString PersonelsM::get_sexe(){return sexe ;}
QString PersonelsM::get_mail(){return mail ;}

int PersonelsM::get_cin(){return CIN ;}
int PersonelsM::get_tel(){return tel ;}
int PersonelsM::get_salaire(){return salaire ;}
int PersonelsM::get_contrat(){return contrat ;}
int PersonelsM::get_horaire(){return horaire ;}

bool PersonelsM::ajouter()
{
    QSqlQuery query;
    QDateTime res = QDateTime::fromString(date, "dd-MM-yyyy") ;
    QString res1= QString::number(tel);
    QString res2= QString::number(salaire);
    QString res3= QString::number(contrat);
    QString res4= QString::number(horaire);

    query.prepare("INSERT INTO PERSONELS ( OCCUPATION , SPECIALITE , NOM , PRENOM , DATEN , SEXE , CIN , TEL , SALAIRE , CONTRAT , HORAIRE , MAIL) "
                        "VALUES (:occupation, :specialite, :nom, :prenom, :date, :sexe, :CIN, :tel, :salaire, :contrat, :horaire, :mail)");

    query.bindValue(":occupation", occupation);
    query.bindValue(":specialite", specialite);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":date", res);
    query.bindValue(":sexe", sexe);
    query.bindValue(":CIN", CIN);
    query.bindValue(":tel", tel);
    query.bindValue(":salaire", salaire);
    query.bindValue(":contrat", contrat);
    query.bindValue(":horaire", horaire);
    query.bindValue(":mail", mail);


    return    query.exec();

}



QSqlQueryModel * PersonelsM::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PERSONELS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Occupation "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Specialite"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date de naissance"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Sexe"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("telephone"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("Salaire"));
model->setHeaderData(9, Qt::Horizontal, QObject::tr("Contrat"));
model->setHeaderData(10, Qt::Horizontal, QObject::tr("Heure de travail"));
model->setHeaderData(11, Qt::Horizontal, QObject::tr("Mail"));
    return model;
}

bool PersonelsM::supprimer(int CIN )
{
QSqlQuery query;
QString res= QString::number(CIN);
query.prepare("Delete from PERSONELS where CIN = :CIN ");
query.bindValue(":CIN", res);
return    query.exec();
}
