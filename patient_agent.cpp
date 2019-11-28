#include "patient_agent.h"
#include "ui_patient_agent.h"
#include<QMessageBox>
patient_agent::patient_agent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::patient_agent)
{
    ui->setupUi(this);
}

patient_agent::~patient_agent()
{
    delete ui;
}

void patient_agent::on_pushButton_4_clicked()
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
QMessageBox::information(nullptr, QObject::tr("Ajouter un patient"),
                  QObject::tr("patient ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un patient"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}



void patient_agent::on_pushButton_6_clicked()
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
