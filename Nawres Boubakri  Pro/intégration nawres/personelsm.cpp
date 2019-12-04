#include "personelsm.h"
#include <QDebug>
#include <QDateTime>
PersonelsM::PersonelsM()
{
occupation="";
specialite="";
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
PersonelsM::PersonelsM( QString occupation,QString specialite,QString nom,QString prenom,QDate date,QString sexe, int CIN, int tel, int salaire, int contrat, int horaire ,QString mail)
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
QDate PersonelsM::get_date(){return date ;}
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
    QDate res = date;
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

bool PersonelsM::modifier(QString val ,QString occ ,QString special,QString nom ,QString prenom ,QDate date1 ,QString sexe,QString cin,QString tel,QString sal,QString cont,QString hor,QString mail)
{
QSqlQuery query ;
query.prepare("UPDATE PERSONELS SET  OCCUPATION= :occupation , SPECIALITE= :special , NOM= :nom , PRENOM= :prenom , DATEN = :date , SEXE = :sexe , CIN= :cin , TEL= :tel , SALAIRE= :sal , CONTRAT= :cont , HORAIRE= :hor , MAIL= :mail where CIN= :cin1 ");
query.bindValue(":cin1",val) ;
query.bindValue(":occupation",occ);
query.bindValue(":special",special);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);
query.bindValue(":date",date1);
query.bindValue(":sexe",sexe);
query.bindValue(":cin",cin);
query.bindValue(":tel",tel);
query.bindValue(":sal",sal);
query.bindValue(":cont",cont);
query.bindValue(":hor",hor);
query.bindValue(":mail",mail);
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

int PersonelsM::medcalM()
{
    int nbf=0 ;

    QSqlQuery query("select * from PERSONELS where SEXE ='Homme'") ;

while (query.next())
{
   nbf++ ;
}
return  nbf ;
}
int PersonelsM::medcalF()
{
    int nbf=0 ;

    QSqlQuery query("select * from PERSONELS where SEXE ='Femme'") ;

while (query.next())
{
   nbf++ ;
}
return  nbf ;
}

QSqlQueryModel* PersonelsM:: trier1 ()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PERSONELS ORDER BY NOM");
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
return model ;
}
QSqlQueryModel* PersonelsM:: trier2 ()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PERSONELS ORDER BY NOM desc");
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
return model ;
}
QSqlQueryModel* PersonelsM:: trier3 ()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PERSONELS ORDER BY CONTRAT");
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
return model ;
}
QSqlQueryModel* PersonelsM:: trier4 ()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PERSONELS ORDER BY SALAIRE");
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
return model ;
}
QSqlQueryModel* PersonelsM:: trier5 ()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PERSONELS ORDER BY CONTRAT desc");
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
return model ;
}
QSqlQueryModel* PersonelsM:: trier6 ()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from PERSONELS ORDER BY SALAIRE desc");
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
return model ;
}

QSqlQuery PersonelsM::recherche1(QString res)
{

    QSqlQuery query ;
    query.prepare("select * from PERSONELS where NOM=:nom OR PRENOM=:nom OR MAIL=:nom OR OCCUPATION=:nom OR SPECIALITE=:nom OR SEXE=:nom") ;
    query.bindValue(":nom",res) ;
return query ;
}

QSqlQuery PersonelsM::recherche2(QString res)
{

    QSqlQuery Quary ;
    Quary.prepare("select * from PERSONELS where CIN=:nom OR TEL=:nom OR CONTRAT=:nom OR SALAIRE=:nom OR HORAIRE=:nom") ;
    Quary.bindValue(":nom",res) ;
    return  Quary ;
}
