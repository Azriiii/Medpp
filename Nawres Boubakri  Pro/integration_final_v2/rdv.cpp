#include "rdv.h"
#include "ui_rdv.h"
#include<QMessageBox>
#include<QSystemTrayIcon>
#include<QPrinter>
#include<QPrintDialog>
RDV::RDV(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RDV)
{
    ui->setupUi(this);
    mysysteme= new QSystemTrayIcon(this);
    mysysteme->setIcon(QIcon(":/icon.png"));
    mysysteme->setVisible(true);
    QSqlQueryModel * model1= new QSqlQueryModel();
    model1->setQuery("select ID_PATIENT from rdv")  ;
    ui->comboBox->setModel(model1) ;
}

RDV::~RDV()
{
    delete ui;
}

void RDV::on_pushButton_6_clicked()
{
  /*  int  id=ui->lineEdit_id->text().toInt();
    QString date= ui->lineEdit_date->text();
     int  etat=ui->lineEdit_etat->text().toInt();
     int  ref=ui->lineEdit_ref->text().toInt();
  class_rdv r (id,date,etat,ref);
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
                              */
}

void RDV::on_pushButton_7_clicked()
{
    int  id=ui->lineEdit_id_3->text().toInt();
    QString date= ui->lineEdit_date_3->text();
     int  etat=ui->lineEdit_etat_3->text().toInt();
     int  ref=ui->lineEdit_ref_3->text().toInt();

     bool test = temprdv.modifier(id,date,etat,ref);
         if (test)
         {
              ui->tablerdv->setModel( temprdv.afficher());
             QMessageBox::information(nullptr, QObject::tr("modifier avec sucess !"),
                         QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);
         }
         else
             QMessageBox::critical(nullptr, QObject::tr("modifier non sucess !"),
                         QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);
}

void RDV::on_pushButton_21_clicked()
{
    int id = ui->comboBox->currentText().toInt() ;
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

void RDV::on_pushButton_10_clicked()
{
    QPrinter printer ;
       printer.setPrinterName("hp") ;
       QPrintDialog dialog (&printer,this) ;
       if ( dialog.exec()== QDialog::Rejected) return ;
       ui->textEdit->print(&printer) ;
}

void RDV::on_tablerdv_2_clicked()
{
    ui->tablerdv->setModel(temprdv.trier());
    mysysteme->showMessage(tr("notification"),tr("tableau triee"));

}

void RDV::on_rechercher_clicked()
{
    int id= ui->id_2->text().toInt();

       ui->tablerdv->setModel( temprdv.rechercher(id));
       mysysteme->showMessage(tr("notification"),tr("element trouvee"));

}

void RDV::on_pushButton_9_clicked()
{
    ui->tablerdv->setModel(temprdv.afficher());//refresh

}

void RDV::on_ajouter_clicked()
{
    int  id=ui->lineEdit_id->text().toInt();
    QString date= ui->lineEdit_date->text();
     int  etat=ui->lineEdit_etat->text().toInt();
     int  ref=ui->lineEdit_ref->text().toInt();
  class_rdv r (id,date,etat,ref);
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
