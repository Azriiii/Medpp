#include "stafft.h"
#include <QDebug>
#include <QDateTime>
#include <QChartView>
#include <QBarSeries>
#include <QBarSet>
#include <QLegend>
#include <QBarCategoryAxis>
#include <QValueAxis>
stafft::stafft()
{
occupation="";
role="";
nom="";
prenom="";
sexe="";
mail="";
 CIN=0;
 tel=0;
 salaire=0;
 contrat=0;
 horaire=0;

}
stafft::stafft( QString occupation,QString role,QString nom,QString prenom,QDate date,QString sexe, int CIN, int tel, int salaire, int contrat, int horaire ,QString mail)
{

this->occupation=occupation ;
this->role=role;
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

QString stafft::get_occupation(){return occupation ;}
QString stafft::get_role(){return role ;}
QString stafft::get_nom(){return nom ;}
QString stafft::get_prenom(){return prenom ;}
QDate stafft::get_date(){return date ;}
QString stafft::get_sexe(){return sexe ;}
QString stafft::get_mail(){return mail ;}

int stafft::get_cin(){return CIN ;}
int stafft::get_tel(){return tel ;}
int stafft::get_salaire(){return salaire ;}
int stafft::get_contrat(){return contrat ;}
int stafft::get_horaire(){return horaire ;}

bool stafft::ajouter()
{
    QSqlQuery query;
    QDate res = date;
    QString res1= QString::number(tel);
    QString res2= QString::number(salaire);
    QString res3= QString::number(contrat);
    QString res4= QString::number(horaire);

    query.prepare("INSERT INTO STAFF ( OCCUPATION , ROLE , NOM , PRENOM , DATENS , SEXE , CIN , TEL , SALAIRE , CONTRAT , HORAIRE , MAIL) "
                        "VALUES (:occupation, :role, :nom, :prenom, :date, :sexe, :CIN, :tel, :salaire, :contrat, :horaire, :mail)");

    query.bindValue(":occupation", occupation);
    query.bindValue(":role", role);
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


bool stafft::modifier(QString val ,QString occ ,QString Role ,QString nom ,QString prenom ,QDate date1 ,QString sexe,QString cin,QString tel,QString sal,QString cont,QString hor,QString mail)
{
    QSqlQuery query ;
    query.prepare("UPDATE STAFF SET  OCCUPATION= :occupation , ROLE= :Role , NOM= :nom , PRENOM= :prenom , DATENS = :date , SEXE = :sexe , CIN= :cin , TEL= :tel , SALAIRE= :sal , CONTRAT= :cont , HORAIRE= :hor , MAIL= :mail where CIN= :cin1 ");
    query.bindValue(":cin1",val) ;
    query.bindValue(":occupation",occ);
    query.bindValue(":Role",Role);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":date",date1);
    query.bindValue(":sexe",sexe);
    query.bindValue(":cin",cin);
    query.bindValue(":tel",tel);
    query.bindValue(":sal",sal);
    query.bindValue(":cont",cont);
    query.bindValue(":hor",hor);
    query.bindValue(":mail",mail) ;
            return    query.exec();


}
QSqlQueryModel * stafft::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from STAFF");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Occupation "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Role"));
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

bool stafft::supprimer(int CIN )
{
QSqlQuery query;
QString res= QString::number(CIN);
query.prepare("Delete from STAFF where CIN = :CIN ");
query.bindValue(":CIN", res);
return    query.exec();
}

int stafft::stcalM()
{
    int nbf=0 ;

    QSqlQuery query("select * from STAFF where SEXE ='Homme'") ;

while (query.next())
{
   nbf++ ;
}
return  nbf ;
}
int stafft::stcalF()
{
    int nbf=0 ;

    QSqlQuery query("select * from STAFF where SEXE ='Femme'") ;

while (query.next())
{
   nbf++ ;
}
return  nbf ;
}
