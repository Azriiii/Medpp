#include "rdv_agent.h"
#include "ui_rdv_agent.h"
#include <QMessageBox>
rdv_agent::rdv_agent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rdv_agent)
{
    ui->setupUi(this);
}

rdv_agent::~rdv_agent()
{
    delete ui;
}

void rdv_agent::on_pushButton_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString date= ui->lineEdit_date->text();
     int  etat=ui->lineEdit_etat->text().toInt();
     int  num=ui->lineEdit_num->text().toInt();




  class_rdv r (id,date,etat,num);

  bool test=r.ajouter();
  if(test)
{ui->tablerdv->setModel(temprdv.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un patient"),
                  QObject::tr("patient ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un patient"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void rdv_agent::on_pushButton_2_clicked()
{
    int id = ui->lineEdit_id_2->text().toInt();
    bool test=temprdv.supprimer(id);
    if(test)
    {ui->tablerdv->setModel(temprdv.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un patient"),
                    QObject::tr("patient supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un patient"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
