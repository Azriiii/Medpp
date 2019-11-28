#include "ordonnance.h"
#include <QDebug>
#include<QFile>
#include<QTextStream>
#include<QFileDialog>
#include<QMessageBox>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include"ordonnance.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QDate>
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>
#include <QSystemTrayIcon>
#include <QStyledItemDelegate>

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
QSqlQueryModel * ordonnance ::tri_reff_ord()
{
    QSqlQueryModel * model= new QSqlQueryModel();

   model->setQuery("select * from ORDONNANCE ORDER BY REFF_ORD");


   return model;
}

 QSqlQueryModel * ordonnance ::tri_reff_date()
 {
     QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from ORDONNANCE ORDER BY DATE_ORD");


    return model;
 }

  QSqlQueryModel * ordonnance ::tri_reff_const()
  {
      QSqlQueryModel * model= new QSqlQueryModel();

     model->setQuery("select * from ORDONNANCE ORDER BY REFF_CONST");


     return model;

  }

  void ordonnance::recherche_ordonnance(QTableView *table , int reff_ord)

  {
     QSqlQueryModel *model=new QSqlQueryModel();
      QSqlQuery *query =new QSqlQuery();
      query->prepare("select * from ORDONNANCE where regexp_like(reff_ord,:reff_ord);");
      query->bindValue(":reff_ord",reff_ord);

      query->exec();
      model->setQuery(*query);
      table->setModel(model);
      table->show();

  }
  void ordonnance:: sauvegarder()
  {



  /*    // Création d'un objet QFile
     // QFile file("Qt.txt");

      QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QString(), "Texte (*.txt)");
       QFile file(fichier);
         QMessageBox::information(this, "Fichier", "Vous avez sélectionné :\n" + fichier);

      // On ouvre notre fichier en lecture seule et on vérifie l'ouverture
      if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
             {   QMessageBox::critical(this, "Fichier", "Problème rencontré.Soit:\n-Vous n'avez pas ouvert le fichier;\n-Il y a eu un problème lors de l'ouverture.");
          return;}
      else
          {   QMessageBox::critical(this, "Fichier", "Pas de Problème rencontré lors de sauvegarde.");
          // Création d'un objet QTextStream à partir de notre objet QFile
          QTextStream flux(&file);
          // On choisit le codec correspondant au jeu de caractères que l'on souhaite ; ici, UTF-8
          flux.setCodec("UTF-8");
          // Écriture des différentes lignes dans le fichier
          //flux << "NOTE," <<ui->textEdit<< endl ;
         /* QString *codeComplet = new QString;
              *codeComplet = ui->textEdit->toPlainText();

              flux << codeComplet << endl;*/
          //flux << ui->textEdit->toPlainText() << endl;
     // }
  }

