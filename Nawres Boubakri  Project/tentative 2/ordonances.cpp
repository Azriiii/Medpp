#include "ordonances.h"
#include "ui_ordonances.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include"ordonnance.h"


Ordonances::Ordonances(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ordonances)
{
    ui->setupUi(this);
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select ID_PATIENT from PATIENT ")  ;
    ui->comboBox_2->setModel(model) ;

    QSqlQueryModel * model_= new QSqlQueryModel();
    model_->setQuery("select REFF_CONST from CONSULTATION ")  ;
    ui->comboBox->setModel(model_) ;

    ui-> TabOrd->setModel(tmpordonnance.afficher());
    ui->TabOrd->resizeColumnsToContents();
    ui->TabOrd->setVisible(true);

    qApp->setStyleSheet("QLineEdit { background-color: pink }QTextEdit { background-color: gray } QComboBox { background-color: green } QDateEdit { background-color: purple }");

}

Ordonances::~Ordonances()
{
    delete ui;
}

void Ordonances::on_pushButton_clicked()
{
    hide() ;
}

void Ordonances::on_pushButton_3_clicked()
{
    hide () ;
}

void Ordonances::on_pushButton_5_clicked()
{
    hide() ;
}

void Ordonances::on_pushButton_7_clicked()
{
    hide() ;
}



void Ordonances::on_ajouter_clicked()
{




    int id_patient=ui->comboBox_2->currentText().toInt() ;
    int reff_const= ui->comboBox->currentText().toInt() ;
    QDate date_ord=ui->dateEdit->date();
    int reff_ord= ui->reff_ord->text().toInt();
    QString traitement= ui->trait->text();
    ordonnance o(reff_ord,date_ord,id_patient,reff_const,traitement);
     bool test=o.ajouter();
     if(test){
         QSqlQueryModel * model= new QSqlQueryModel();
          model->setQuery("select ID_PATIENT from PATIENT ")  ;
          ui->comboBox_2->setModel(model) ;

          QSqlQueryModel * model_= new QSqlQueryModel();
          model_->setQuery("select REFF_CONST from CONSULTATION ")  ;
          ui->comboBox->setModel(model_) ;
         QMessageBox::information(nullptr, QObject::tr("Ordonnance ajouté"),
                                  QObject::tr(" successful.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
     }
}

void Ordonances::on_modifier_clicked()
{
    int reff_const,reff_ord;
    int id_patient;
    QDate date_ord;
    QString traitement;
    id_patient=ui->idd->text().toInt();
    reff_const=ui->rc->text().toInt();
    reff_ord=ui->reff->text().toInt();
    date_ord=ui->dateEdit_2->date();
    traitement=ui->tr->text();
   if (ui->idd->text().isEmpty())
    {

        QMessageBox::information(this," EREURE ","VEUILLEZ VERIFIER CHAMP identifiant !!!!") ;

    }
  else   if (ui->reff->text().isEmpty())
    {

        QMessageBox::information(this," EREURE ","VEUILLEZ VERIFIER CHAMP reference ordonnance !!!!") ;

    }
/*else    if (ui->date_const_6->text().isEmpty())
    {

        QMessageBox::information(this," EREURE "," VEUILLEZ VERIFIER CHAMP date ordonnance!!!!") ;
    }*/
    else    if (ui->rc->text().isEmpty())
        {

            QMessageBox::information(this," EREURE "," VEUILLEZ VERIFIER CHAMP reference consultation!!!!") ;
        }
   else    if (ui->tr->text().isEmpty())
       {

           QMessageBox::information(this," EREURE "," VEUILLEZ VERIFIER CHAMP reference traitement!!!!") ;
       }
else{
       int reff_const,reff_ord;
       int id_patient;
       QDate date_ord;
       QString traitement;
       id_patient=ui->idd->text().toInt();
       reff_const=ui->rc->text().toInt();
       reff_ord=ui->reff->text().toInt();
       date_ord=ui->dateEdit_2->date();
       traitement=ui->tr->text();

     bool test=tmpordonnance.modifier(reff_ord,date_ord,id_patient,reff_const,traitement);
     ui->TabOrd->setModel(tmpordonnance.afficher());//refresh
     if(test)
     {ui->TabOrd->setModel(tmpordonnance.afficher());//refresh
         QMessageBox::information(nullptr, QObject::tr("Modifier une Consultation"),
                     QObject::tr("Consultation modifié.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
         ui->TabOrd->setModel(tmpordonnance.afficher());//refresh

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Modifier une Consultation"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void Ordonances::on_supprimer_clicked()
{
    int reff = ui->lineEdit_15->text().toInt();
    bool test=tmpordonnance.supprimer(reff);
    if(test)
    {ui->TabOrd->setModel(tmpordonnance.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une ordonnance"),
                    QObject::tr("Ordonnance supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une ordonnance"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
