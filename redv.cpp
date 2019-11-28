#include "redv.h"
#include "ui_redv.h"
#include<QMessageBox>
#include"class_rdv.h"
#include <QPropertyAnimation>
#include<QGraphicsBlurEffect>
#include<QPropertyAnimation>
#include <QMessageBox>
#include <QPropertyAnimation>
#include<QGraphicsBlurEffect>
#include<QPropertyAnimation>
#include<QMediaContent>
#include<QMediaPlayer>
#include<QAudioFormat>
#include "mail.h"
#include "statis.h"
#include<QFile>
#include"statis.h"
#include<QAudioOutput>
redv::redv(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::redv)
{
    ui->setupUi(this);
    ui->comboBox->setModel(p.showidpatient());
}

redv::~redv()
{
    delete ui;
}

void redv::on_pushButton_clicked()
{
    int id = ui->comboBox->currentText().toInt();
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
smtp_rec* smtp= new smtp_rec("hajmoussa2368@gmail.com","Hm123456","smtp.gmail.com",465);
           smtp->sendMail("hajmoussa2368@gmail.com","amina.mtiri@esprit.tn","le patient est ajouté","le patient est ajouté");

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un patient"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void redv::on_pushButton_2_clicked()
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

void redv::on_pushButton_4_clicked()
{
    ui->tablerdv->setModel(temprdv.trier());
}

void redv::on_rechercher_clicked()
{
  QString date= ui->id->text();
  ui->tablerdv->setModel(temprdv.rechercherrdv(date));
}

void redv::on_pushButton_5_clicked()
{
    statis stat;
    stat.setModal(true);
    stat.exec();
}

void redv::on_pushButton_6_clicked()
{

    statis stat;
    stat.setModal(true);
    stat.exec();
}
