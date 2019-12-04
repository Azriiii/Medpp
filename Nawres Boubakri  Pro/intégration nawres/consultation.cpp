#include "consultation.h"
#include <QDebug>
#include<QDate>
#include <QComboBox>
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>
#include <QSystemTrayIcon>
#include <QStyledItemDelegate>
#include <QDialog>
#include <QTextCursor>
#include<QPropertyAnimation>

//consultation::consultation(int reff_const,int date_const,int id_patient)
Consultation::Consultation(int reff_const,QDate date_const,QString symp,QString diag,QString exam,QString resultat,int id_patient)
{
    this->id_patient=id_patient;
    this->reff_const=reff_const;
    this->date_const=date_const;
    this->symptomes=symp;
    this->diagnostique=diag;
    this->examens_cliniques=exam;
    this->res_examens_cliniques=resultat;
}


//int consultation::get_date_const(){return  date_const;}

QDate Consultation::get_date_const(){return  date_const;}
int Consultation::get_reff_const(){return reff_const;}
int Consultation::get_id_patient(){return  id_patient;}

QString  Consultation::get_symptomes(){return symptomes;}
QString  Consultation::get_diagnostique(){return diagnostique;}
QString  Consultation::get_examens_cliniques(){return examens_cliniques;}
QString  Consultation::get_res_examens_cliniques(){return res_examens_cliniques;}

bool Consultation::ajouter()
{
QSqlQuery query;
QString res= QString::number(id_patient);

query.prepare("INSERT INTO consultation (REFF_CONST, DATE_CONST, SYMPTOMES, DIAGNOSTIQUE, EXAM_CLINIQUE, RES_EXAM, ID_PATIENT) "
                    "VALUES (:reff_const, :date_const, :symptomes, :diagnostique, :examens_cliniques, :res_examens_cliniques, :id_patient)");

query.bindValue(":reff_const", reff_const);
query.bindValue(":date_const", date_const);
query.bindValue(":symptomes", symptomes);
query.bindValue(":diagnostique", diagnostique);
query.bindValue(":examens_cliniques", examens_cliniques);
query.bindValue(":res_examens_cliniques", res_examens_cliniques);
query.bindValue(":id_patient", res);

return    query.exec();
}

QSqlQueryModel * Consultation::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Consultation order by REFF_CONST");
/*model->setHeaderData(0, Qt::Horizontal, QObject::tr("reff_const"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_const "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("id_patient"));*/
    return model;
}



bool Consultation::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from consultation where REFF_CONST = :idd ");
query.bindValue(":idd", res);
return    query.exec();
}



bool Consultation :: modifier( int reff_const ,QDate date_const,QString symptomes,QString diagnostique,QString exam_clinique,QString res_exam, int idd)
{
    QSqlQuery query;
    QString res= QString::number(reff_const);
    QString d;
    d=date_const.toString("dd-MMM-yyyy");

    query.prepare("update consultation set id_patient='"+QString::number(idd)+"', reff_const='"+QString::number(reff_const)+"', date_const= :date_const, symptomes=:symptomes, diagnostique=:diagnostique, exam_clinique=:exam_clinique, res_exam=:res_exam where REFF_CONST="+QString::number(reff_const));
    query.bindValue(":reff_const", res);
    query.bindValue(":symptomes",symptomes);
    query.bindValue(":diagnostique",diagnostique);
    query.bindValue(":exam_clinique",exam_clinique);
     query.bindValue(":res_exam",res_exam);
     query.bindValue(":date_const",date_const);



    return    query.exec();

}

void Consultation::recherche_consultation(QTableView *table , int reff_const)

{
   QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *query =new QSqlQuery();
  //ligne ajoutée
    // QString str= QString::number(reff_const);

    query->prepare("select * from CONSULTATION where regexp_like(reff_const,:reff_const);");

   // query->prepare("select * from CONSULTATION where(REFF_CONST LIKE '"+str+"%')");

    query->bindValue(":reff_const",reff_const);

    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();

}
QSqlQueryModel *  Consultation::recherche()
{


            QSqlQuery *query=new QSqlQuery("SELECT * from CONSULTATION");
            QSqlQueryModel *model=new QSqlQueryModel();
            model->setQuery(*query);
            return model;

}

bool Consultation::notifier()
{
    int i=0 ;
    //int x=0;
    QSqlQuery query;
    QSqlQuery query1;


 /* query.prepare("SELECT COUNT(DISTINCT reff_const) FROM consultation");
    query.bindValue(":x",x);
*/
    //query.prepare("SELECT *FROM consultation where(select COUNT(DISTINCT reff_const)from consultation) ");
    query.prepare("select * from CONSULTATION where REFF_CONST=15");
    if(query.exec())
    {while (query.next())
        {i++;}
    }
    if(i!=0)
    return true;
    else
        return false;

}
  QSqlQueryModel *Consultation:: tri_reff_const()
{
    QSqlQueryModel * model= new QSqlQueryModel();

   model->setQuery("select * from CONSULTATION ORDER BY REFF_CONST");


   return model;


}
  QSqlQueryModel * Consultation:: tri_reff_date()
  {
      QSqlQueryModel * model= new QSqlQueryModel();

     model->setQuery("select * from CONSULTATION ORDER BY DATE_CONST");


     return model;
  }
   QSqlQueryModel * Consultation:: tri_reff_id()
   {

       QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("select * from CONSULTATION ORDER BY ID_PATIENT");


      return model;
   }

    void Consultation::imprimer()
    {
       /* QPrinter printer (QPrinter::HighResolution) ;
           printer.setPrinterName("Imprimer") ;
           QPrintDialog dialog (&printer,this) ;
           if ( dialog.exec()== QDialog::Rejected) return ;
              ui->textEdit->print(&printer) ;
           */

    }
    QSqlQueryModel * Consultation::stats()
    {
        QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("SELECT reff_const, id_patient,((id_patient*100)/(select SUM(reff_const) from consultation) from consultation");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("reff_const"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_patient"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("stats"));

            return model;
    }

    Consultation::Consultation()
    {
        id_patient=0;
        reff_const=0;
        //date_const=0;
    }


    int Consultation::grippe()
    {

        int nbf=0;
        QSqlQuery query ("select * from Consultation where DIAGNOSTIQUE='grippe'");
        while(query.next())
        {
            nbf++;
        }
        return nbf;
    }
    int Consultation::rougeole()
    {

        int nbf=0;
        QSqlQuery query ("select * from Consultation where DIAGNOSTIQUE='rougeole'");
        while(query.next())
        {
            nbf++;
        }
        return nbf;
    }
    int Consultation::anemie()
    {

        int nbf=0;
        QSqlQuery query ("select * from Consultation where DIAGNOSTIQUE='anemie'");
        while(query.next())
        {
            nbf++;
        }
        return nbf;
    }

    int Consultation::diabete()
    {

        int nbf=0;
        QSqlQuery query ("select * from Consultation where DIAGNOSTIQUE='diabete'");
        while(query.next())
        {
            nbf++;
        }
        return nbf;
    }




