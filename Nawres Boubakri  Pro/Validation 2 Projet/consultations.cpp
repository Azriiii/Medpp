#include "consultations.h"
#include "ui_consultations.h"
#include"consultation.h"
#include"statistiques.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QDate>
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>
#include <QSystemTrayIcon>
#include <QStyledItemDelegate>
#include <QDialog>
#include <QTextCursor>
#include<QPropertyAnimation>
#include<QFile>
#include<QTextStream>
#include<QFileDialog>
Consultations::Consultations(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Consultations)
{
    ui->setupUi(this);

    mySystemTrayIcon=new QSystemTrayIcon(this) ;
    mySystemTrayIcon->setIcon(QIcon(":/icon.png")) ;
    mySystemTrayIcon->setVisible(true) ;

   /*  QMediaPlayer *music=new QMediaPlayer();

    music->setMedia(QUrl::fromLocalFile("C:/Users/esprit/Desktop/MedppGUI/son/son2.wav"));
    music->play();
  */


    QPixmap bkng ("C:/Users/esprit/Desktop/MedppGUI/icon.png");

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select ID_PATIENT from PATIENT ")  ;
    ui->comboBox_2->setModel(model) ;

    QSqlQueryModel * model_1= new QSqlQueryModel();
    model_1->setQuery("select REFF_CONST from CONSULTATION ")  ;
    ui->comboBox_3->setModel(model_1) ;

    ui-> TabConsultation->setModel(tmpconsultation.afficher());
    ui->TabConsultation->resizeColumnsToContents();
    ui->TabConsultation->setVisible(true);
   // ui->tableView_r->setModel(tmpc.afficher());

    qApp->setStyleSheet("QLineEdit { background-color: pink }QTextEdit { background-color: gray } QComboBox { background-color: green } QDateEdit { background-color: green }");


    QPropertyAnimation *animation = new QPropertyAnimation(ui->label_3, "geometry");
        animation->setDuration(20000);
        animation->setLoopCount(-1);
        animation->setStartValue(QRect(-100, 10, 371, 71));/*(QRect(-400, 10, 371, 71));*/
        animation->setEndValue(QRect(700, 10, 371, 71));
        animation->start();


        QPropertyAnimation *animation1 = new QPropertyAnimation(ui->lc1, "geometry");
            animation1->setDuration(20000);
            animation1->setLoopCount(-1);
            animation1->setStartValue(QRect(-100, 10, 371, 71));/*(QRect(-400, 10, 371, 71));*/
            animation1->setEndValue(QRect(700, 10, 371, 71));
            animation1->start();


            QPropertyAnimation *animation2 = new QPropertyAnimation(ui->lc_2, "geometry");
                animation2->setDuration(20000);
                animation2->setLoopCount(-1);
                animation2->setStartValue(QRect(-100, 10, 371, 71));/*(QRect(-400, 10, 371, 71));*/
                animation2->setEndValue(QRect(700, 10, 371, 71));
                animation2->start();

                QPropertyAnimation *animation3 = new QPropertyAnimation(ui->lc_3, "geometry");
                    animation3->setDuration(20000);
                    animation3->setLoopCount(-1);
                    animation3->setStartValue(QRect(-100, 10, 371, 71));/*(QRect(-400, 10, 371, 71));*/
                    animation3->setEndValue(QRect(700, 10, 371, 71));
                    animation3->start();

}

Consultations::~Consultations()
{
    delete ui;
}

void Consultations::on_pushButton_clicked()
{
    hide() ;
}

void Consultations::on_pushButton_3_clicked()
{
    hide() ;
}

void Consultations::on_pushButton_5_clicked()
{
    hide() ;
}

void Consultations::on_pushButton_7_clicked()
{
    hide() ;
}
/*ajouter Consultation*/
void Consultations::on_pushButton_2_clicked()
{






    int id_patient=ui->comboBox_2->currentText().toInt();
    int reff_const= ui->line_reff->text().toInt();

    QString symp=ui->line_sym->text();
    QString diag=ui->line_dia->text();
    QString exam=ui->line_exa->text();
    QString res=ui->line_res->text();
    QDate date_const=ui->dateEdit->date();


    Consultation c(reff_const,date_const,symp,diag,exam,res,id_patient);
     bool test=c.ajouter();

     if(test){
         mySystemTrayIcon->showMessage(tr("Notifications"),tr("Consultation Ajoutée"));

         ui->TabConsultation->setModel(tmpconsultation.afficher());//refresh
         QSqlQueryModel * model= new QSqlQueryModel();
             model->setQuery("select ID_PATIENT from PATIENT ")  ;
             ui->comboBox_2->setModel(model) ;

         bool a= tmc.notifier();
         if(a==true){QMessageBox::warning(this,"System","Vous Avez dépasser x Consultations");}

         QMessageBox::information(nullptr, QObject::tr("Ajouter une consultation"),
                                  QObject::tr(" successful.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Ajouter une Consultation"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}
/*Supprimer Consultation*/
void Consultations::on_pushButton_6_clicked()
{
    int reff = ui->reff->text().toInt();
    bool test=tmpconsultation.supprimer(reff);


    if(test)
    {ui->TabConsultation->setModel(tmpconsultation.afficher());//refresh
         mySystemTrayIcon->showMessage(tr("Notifications"),tr("Consultation Supprimée"));




        QMessageBox::information(nullptr, QObject::tr("Supprimer une consultation"),
                    QObject::tr("Consultation supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une consultation"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
/*Modifier Consultation*/
void Consultations::on_pushButton_4_clicked()
{

    QDate date_const;
    //int  id_patient=ui->idd->text().toInt();
    //int reff_const=ui->reff_const->text().toInt();
    date_const=ui->dateEdit_2->date();
    if (ui->idd->text().isEmpty())
    {

        QMessageBox::information(this," EREURE ","VEUILLEZ VERIFIER CHAMP identifiant !!!!") ;

    }
  else   if (ui->comboBox_3->currentText().isEmpty())
    {

        QMessageBox::information(this," EREURE ","VEUILLEZ VERIFIER CHAMP reference consultation !!!!") ;

    }
//else    if (ui->dateEdit_2->date().isEmpty())
   // {

       // QMessageBox::information(this," EREURE "," VEUILLEZ VERIFIER CHAMP date!!!!") ;
   // }
    else   if (ui->symp->text().isEmpty())
      {

          QMessageBox::information(this," EREURE ","VEUILLEZ VERIFIER CHAMP SYMPTOMES !!!!") ;

      }
    else   if (ui->diag->text().isEmpty())
      {

          QMessageBox::information(this," EREURE ","VEUILLEZ VERIFIER CHAMP DIAGNOSTIQUE !!!!") ;

      }
    else   if (ui->exam->text().isEmpty())
      {

          QMessageBox::information(this," EREURE ","VEUILLEZ VERIFIER CHAMP EXAMENS_CLINIQUES !!!!") ;

      }
    else   if (ui->res_exam->text().isEmpty())
      {

          QMessageBox::information(this," EREURE ","VEUILLEZ VERIFIER CHAMP RESULTATS_EXAMENS_CLINIQUES !!!!") ;

      }
else{

        int id_patient = ui->idd->text().toInt();
       // int reff_const=ui->reff_const->text().toInt();
       // int date_const=ui->line_date->text().toInt();
       int reff_const=ui->comboBox_3->currentText().toInt() ;

        QDate date_const=ui->dateEdit_2->date();
        QString symp=ui->symp->text();
        QString diag=ui->diag->text();
        QString exam=ui->exam->text();
        QString res_exam=ui->res_exam->text();
     bool test=tmpconsultation.modifier(reff_const,date_const,symp,diag,exam,res_exam,id_patient);
     ui->TabConsultation->setModel(tmpconsultation.afficher());//refresh
     if(test)
     {ui->TabConsultation->setModel(tmpconsultation.afficher());//refresh
          mySystemTrayIcon->showMessage(tr("Notifications"),tr("Consultation Modifiée "));
         QMessageBox::information(nullptr, QObject::tr("Modifier une Consultation"),
                     QObject::tr("Consultation modifié.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
         ui->TabConsultation->setModel(tmpconsultation.afficher());//refresh

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Modifier une Consultation"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

/*recherche consultation*/
void Consultations::on_pushButton_8_clicked()
{
   Consultation c;




    if(ui->reff_consultation->text().isEmpty())
    {
        Consultation c;

        c.recherche_consultation(ui->tableView_r,ui->reff_consultation->text().toInt());

    }
    else {


   int reff_const=ui->reff_consultation->text().toInt();
   c.recherche_consultation(ui->tableView_r,reff_const); }


}

void Consultations::on_pushButton_9_clicked()
{
 QPrinter printer (QPrinter::HighResolution) ;
    printer.setPrinterName("Imprimer") ;
    QPrintDialog dialog (&printer,this) ;
    if ( dialog.exec()== QDialog::Rejected) return ;
       ui->textEdit1->print(&printer) ;






}

void Consultations::on_radioButton_3_clicked()
{

    Consultation c;

    ui->TabConsultation->setModel(c.tri_reff_const());
}

void Consultations::on_radioButton_4_clicked()
{

    Consultation c;
ui->TabConsultation->setModel(c.tri_reff_id()) ;
}

void Consultations::on_radioButton_2_clicked()
{
    Consultation c;

ui->TabConsultation->setModel(c.tri_reff_date()) ;
}



void Consultations::on_pushButton_10_clicked()
{


       // Création d'un objet QFile
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
           flux << ui->textEdit1->toPlainText() << endl;
      }
}



void Consultations::on_statistiques_clicked()
 { //ui->tablestat->setModel(tmpC.stats());
   Statistiques*a=new Statistiques();
   a->show();
}
