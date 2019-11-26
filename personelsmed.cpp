#include "personelsmed.h"
#include "ui_personelsmed.h"
#include "personelsm.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QDebug>
PersonelsMed::PersonelsMed(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonelsMed)
{
    ui->setupUi(this);
    ui->TabPers->setModel(tmppers.afficher());
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select CIN from PERSONELS")  ;
    ui->comboBox->setModel(model) ;
    //qDebug() << (model->rowCount()) ;
    ui->carteid->setValidator( new QIntValidator(0, 99999999, this) );
    ui->Tel->setValidator( new QIntValidator(0, 99999999, this) );
    ui->CINsup->setValidator( new QIntValidator(0, 99999999, this) );
}

PersonelsMed::~PersonelsMed()
{
    delete ui;
}

void PersonelsMed::on_save_clicked()
{
    QString occupation= ui->Occupation->text();
    QString specialite= ui->Special->text();
    QString nom= ui->Nom->text();
    QString prenom= ui->Prenom->text();
    QString date= ui->Date->text();
    QString sexe= ui->Sexe->text();
    int CIN = ui->carteid->text().toInt();
    int Telephone = ui->Tel->text().toInt();
    int Salaire = ui->Salaire->text().toInt();
    int Contrat = ui->LineEdit_6->text().toInt();
    int Horaire = ui->Horaire->text().toInt();

    QString mail= ui->Mail->text();

 PersonelsM p(occupation,specialite,nom,prenom,date,sexe,CIN,Telephone,Salaire,Contrat,Horaire,mail);

  bool test=p.ajouter();
  if(test)
{ui->TabPers->setModel(tmppers.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un personel"),
                  QObject::tr("Personel ajouté.\n"
                              "Click Close to exit."), QMessageBox::Close);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un personel"),
                  QObject::tr("Erreur !.\n"
                              "Click Close to exit."), QMessageBox::Close);
}



void PersonelsMed::on_retour_clicked()
{
    hide() ;
}


void PersonelsMed::on_pushButton_clicked()
{
    hide() ;
}

void PersonelsMed::on_pushButton_3_clicked()
{
    hide() ;
}

void PersonelsMed::on_Delete_clicked()
{
    int CIN = ui->CINsup->text().toInt();
    bool test=tmppers.supprimer(CIN);
    if(test)
    {ui->TabPers->setModel(tmppers.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un personel"),
                    QObject::tr("Personel supprimé.\n"
                                "Click Close to exit."), QMessageBox::Close);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un personel"),
                    QObject::tr("Erreur !.\n"
                                "Click Close to exit."), QMessageBox::Close);


}




void PersonelsMed::on_pushButton_2_clicked()
{
    hide();
}
