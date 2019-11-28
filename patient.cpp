#include "patient.h"
#include "ui_patient.h"
#include "class_patient.h"
#include <QMessageBox>
#include <QSystemTrayIcon>
patient::patient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::patient)
{
    ui->setupUi(this);
    mysysteme= new QSystemTrayIcon(this);
    mysysteme->setIcon(QIcon(":/icon.png"));
    mysysteme->setVisible(true);
}

patient::~patient()
{
    delete ui;
}

void patient::on_pushButton_4_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
     QString prenom= ui->lineEdit_prenom->text();
      QString  date=ui->lineEdit_date->text();
     int tel= ui->lineEdit_tel->text().toInt();
     QString adresse= ui->lineEdit_adresse->text();



  class_patient p (id,nom,prenom,date,tel,adresse);

  bool test=p.ajouter();
  if(test)
{ui->tablepatient->setModel(temppatient.afficher());//refresh
      mysysteme->showMessage(tr("notification"),tr("ajout avec succes"));
QMessageBox::information(nullptr, QObject::tr("Ajouter un patient"),
                  QObject::tr("patient ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un patient"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void patient::on_pushButton_6_clicked()
{
    int id = ui->lineEdit_id_2->text().toInt();
    bool test=temppatient.supprimer(id);
    if(test)
    {ui->tablepatient->setModel(temppatient.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un patient"),
                    QObject::tr("patient supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un patient"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void patient::on_pushButton_5_clicked()
{
    int id = ui->lineEdit_id2->text().toInt();
       QString nom= ui->lineEdit_9->text();
       QString prenom= ui->lineEdit_10->text();

       QString  date=ui->lineEdit_12->text();
       int tel= ui->lineEdit_11->text().toInt();
       QString adresse=ui->lineEdit_13->text();
    class_patient p(id,nom,prenom,date,tel,adresse);
     bool test=p.update();

     if(test)
   {


   QMessageBox::information(nullptr, QObject::tr("modifier un patient"),
                     QObject::tr("patient modifie.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

   }
     else
         QMessageBox::critical(nullptr, QObject::tr("modifier un patient"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

}


void patient::on_tripatient_clicked()
{
ui->tablepatient->setModel(temppatient.trier());
}

void patient::on_pushButton_7_clicked()
{

}
