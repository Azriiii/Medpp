#include "ordonances.h"
#include "ui_ordonances.h"
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
#include <QDialog>
#include <QTextCursor>
#include<QPropertyAnimation>
#include<QFile>
#include<QTextStream>
#include<QFileDialog>
#include "numberformatdelegate.h"

Ordonances::Ordonances(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ordonances)
{
    ui->setupUi(this);
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select ID_PATIENT from PATIENT ")  ;
    ui->patient->setModel(model) ;

    ui->traitement->addItem("fervexe");
    ui->traitement->addItem("doliprane");
    ui->traitement->addItem("aspirine");
    ui->traitement->addItem("panadole");



    QSqlQueryModel * model_= new QSqlQueryModel();
    model_->setQuery("select REFF_CONST from CONSULTATION ")  ;
    ui->consultation->setModel(model_) ;

    QSqlQueryModel * model_1= new QSqlQueryModel();
    model_1->setQuery("select REFF_ORD from ORDONNANCE ")  ;
    ui->ord->setModel(model_1) ;

    QSqlQueryModel * model_2= new QSqlQueryModel();
    model_2->setQuery("select REFF_ORD from ORDONNANCE ")  ;
    ui->supp_ord->setModel(model_2) ;

    ui-> TabOrd->setModel(tmpordonnance.afficher());
    ui->TabOrd->resizeColumnsToContents();
    ui->TabOrd->setItemDelegateForColumn(5, new NumberFormatDelegate(this));
    ui->TabOrd->setVisible(true);

    qApp->setStyleSheet("QLineEdit { background-color: pink }QTextEdit { background-color: lightgray } QComboBox { background-color: lightgray } QDateEdit { background-color: lightgray }");
     ui->reff_ord->setValidator( new QRegExpValidator(QRegExp("[0-9]{4}"),this) );

    /*animation*/
    QPropertyAnimation *animation = new QPropertyAnimation(ui->l1, "geometry");
        animation->setDuration(20000);
        animation->setLoopCount(-1);
        animation->setStartValue(QRect(-100, 10, 371, 71));/*(QRect(-400, 10, 371, 71));*/
        animation->setEndValue(QRect(700, 10, 371, 71));
        animation->start();


        QPropertyAnimation *animation1 = new QPropertyAnimation(ui->l2, "geometry");
            animation1->setDuration(20000);
            animation1->setLoopCount(-1);
            animation1->setStartValue(QRect(-100, 10, 371, 71));/*(QRect(-400, 10, 371, 71));*/
            animation1->setEndValue(QRect(700, 10, 371, 71));
            animation1->start();


            QPropertyAnimation *animation2 = new QPropertyAnimation(ui->l3, "geometry");
                animation2->setDuration(20000);
                animation2->setLoopCount(-1);
                animation2->setStartValue(QRect(-100, 10, 371, 71));/*(QRect(-400, 10, 371, 71));*/
                animation2->setEndValue(QRect(700, 10, 371, 71));
                animation2->start();

                QPropertyAnimation *animation3 = new QPropertyAnimation(ui->l4, "geometry");
                    animation3->setDuration(20000);
                    animation3->setLoopCount(-1);
                    animation3->setStartValue(QRect(-100, 10, 371, 71));/*(QRect(-400, 10, 371, 71));*/
                    animation3->setEndValue(QRect(700, 10, 371, 71));
                    animation3->start();

                    ui->reff_ord->setValidator( new QRegExpValidator(QRegExp("[0-9]{4}"),this) );
                    ui->rc->setValidator( new QRegExpValidator(QRegExp("[0-9]{4}"),this) );
                    ui->traitement->setValidator( new QRegExpValidator(QRegExp("[a-z-A-Z_]+"),this) );
                    ui->tr->setValidator( new QRegExpValidator(QRegExp("[a-z-A-Z_]+"),this) );


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



/*


}

void Ordonances::on_pushButton_9_clicked()
{

}

void Ordonances::on_pushButton_10_clicked()
{





}
*/

void Ordonances::on_ajouter_ordonnance_clicked()
{

    int id_patient=ui->patient->currentText().toInt() ;
    int reff_const= ui->consultation->currentText().toInt() ;
    QDate date_ord=ui->dateEdit->date();
    int reff_ord= ui->reff_ord->text().toInt();
    QString traitement=ui->traitement->currentText();
   // QString traitement= ui->trait->text();
    ordonnance o(reff_ord,date_ord,id_patient,reff_const,traitement);
     bool test=o.ajouter();
     if(test){
         QSqlQueryModel * model= new QSqlQueryModel();
          model->setQuery("select ID_PATIENT from PATIENT ")  ;
          ui->patient->setModel(model) ;

          QSqlQueryModel * model_= new QSqlQueryModel();
          model_->setQuery("select REFF_CONST from CONSULTATION ")  ;
          ui->consultation->setModel(model_) ;
          ui->TabOrd->setModel(tmpordonnance.afficher());
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
 /* else   if (ui->reff->text().isEmpty())
    {

        QMessageBox::information(this," EREURE ","VEUILLEZ VERIFIER CHAMP reference ordonnance !!!!") ;

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
      // reff_ord=ui->reff->text().toInt();
       reff_ord=ui->ord->currentText().toInt();
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

void Ordonances::on_supprimer_ordonnance_clicked()
{
    //int reff = ui->lineEdit_15->text().toInt();
    int reff=ui->supp_ord->currentText().toInt();
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

void Ordonances::on_rechercher_ord_clicked()
{
    ordonnance c;

     if(ui->reff_2->text().isEmpty())
     {
         ordonnance c;

         c.recherche_ordonnance(ui->TabOrd,ui->reff_2->text().toInt());

     }
     else {
    int reff_ord=ui->reff_2->text().toInt();
    c.recherche_ordonnance(ui->TabOrd,reff_ord); }

}

void Ordonances::on_tri_const_clicked()
{
    ordonnance c;

    ui->TabOrd->setModel(c.tri_reff_const());
}

void Ordonances::on_tri_ord_clicked()
{
    ordonnance c;

    ui->TabOrd->setModel(c.tri_reff_ord());
}

void Ordonances::on_tri_date_clicked()
{
    ordonnance c;

    ui->TabOrd->setModel(c.tri_reff_date());
}


void Ordonances::on_sauvegarder_clicked()
{


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

         flux << ui->textEdit->toPlainText() << endl;
     }
}

void Ordonances::on_imprimer_clicked()
{
    QPrinter printer (QPrinter::HighResolution) ;
       printer.setPrinterName("Imprimer") ;
       QPrintDialog dialog (&printer,this) ;
       if ( dialog.exec()== QDialog::Rejected) return ;
          ui->textEdit->print(&printer) ;
}

void Ordonances::on_actualiser_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select REFF_ORD from ORDONNANCE")  ;
    ui->ord->setModel(model) ;
}

void Ordonances::on_choisir_clicked()
{
    QString val=ui->ord->currentText()  ;
    QSqlQuery query ;
    query.prepare("select * from ORDONNANCE where REFF_ORD='"+val+"'") ;

  if (query.exec())
  {
      while (query.next()) {

        ui->reff_ord->setText(query.value(0).toString()) ;
        ui->dateEdit_2->setDate(query.value(1).toDate()) ;

        ui->idd->setText(query.value(2).toString()) ;

        ui->rc->setText(query.value(3).toString()) ;
        ui->tr->setText(query.value(4).toString()) ;
      }

  }

}
