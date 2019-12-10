#include "patients.h"
#include "ui_patients.h"
#include"class_patient.h"
#include<QMessageBox>
#include<QSystemTrayIcon>
#include<QPrinter>
#include<QPrintDialog>
patients::patients(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::patients)
{
    ui->setupUi(this);
    mysysteme= new QSystemTrayIcon(this);
    mysysteme->setIcon(QIcon(":/icon.png"));
    mysysteme->setVisible(true);
    QSqlQueryModel * model1= new QSqlQueryModel();
    model1->setQuery("select ID_PATIENT from patient")  ;
    ui->comboBox->setModel(model1) ;
}

patients::~patients()
{
    delete ui;
}

void patients::on_pushButton_6_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
     QString prenom= ui->lineEdit_prenom->text();
      QString  date=ui->lineEdit_date->text();
     int tel= ui->lineEdit_tel->text().toInt();
     QString adresse= ui->lineEdit_adresse->text();
QString sexe=ui->lineEdit_sexe->text();

  class_patient p (id,nom,prenom,date,tel,adresse,sexe);

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


void patients::on_pushButton_7_clicked()
{
    int id = ui->lineEdit_id_2->text().toInt();
    QString nom= ui->lineEdit_nom_2->text();
     QString prenom= ui->lineEdit_prenom_2->text();
      QString  date=ui->lineEdit_date_2->text();
     int tel= ui->lineEdit_tel_2->text().toInt();
     QString adresse= ui->lineEdit_adresse_2->text();
QString sexe=ui->lineEdit_sexe_2->text();
     bool test = temppatient.modifier(  id,nom, prenom, date, tel, adresse,sexe);
         if (test)
         {
              ui->tablepatient->setModel( temppatient.afficher());
             QMessageBox::information(nullptr, QObject::tr("modifier avec sucess !"),
                         QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);
         }
         else
             QMessageBox::critical(nullptr, QObject::tr("modifier non sucess !"),
                      QObject::tr( "Click Cancel to exit."), QMessageBox::Cancel);
}

void patients::on_pushButton_8_clicked()
{
 int id = ui->comboBox->currentText().toInt() ;
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

void patients::on_tripatient_clicked()
{
    ui->tablepatient->setModel(temppatient.trier());
    mysysteme->showMessage(tr("notification"),tr("tableau triee"));

}

void patients::on_pushButton_9_clicked()
{
      int id = ui->lineEdit_19->text().toInt();
    ui->tablepatient->setModel(temppatient.rechercher(id));
    mysysteme->showMessage(tr("notification"),tr("element trouvee"));

}

void patients::on_pushButton_10_clicked()
{
    QPrinter printer ;
       printer.setPrinterName("hp") ;
       QPrintDialog dialog (&printer,this) ;
       if ( dialog.exec()== QDialog::Rejected) return ;
       ui->textEdit->print(&printer) ;
}

void patients::on_pushButton_11_clicked()
{
      ui->tablepatient->setModel( temppatient.afficher());
}
