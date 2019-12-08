#include "fourniture.h"
#include "ui_fourniture.h"
#include "fournisseurs.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQueryModel>
#include <QSystemTrayIcon>
#include <QPrintDialog>
#include <QPrinter>
#include<QtSql/QSqlError>


fourniture::fourniture(QWidget *parent) :
    QDialog(parent),

    ui(new Ui::fourniture)
{

    mySystemTrayIcon=new QSystemTrayIcon(this) ;
    mySystemTrayIcon->setIcon(QIcon(":/icon.png")) ;
    mySystemTrayIcon->setVisible(true) ;
    ui->setupUi(this);
    ui->taba->setModel(tmpfourn.afficher());//show data.
   QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select REF_FOURN from FOURNITURE ")  ;
    ui->comboBox->setModel(model) ;
    QSqlQueryModel * model1= new QSqlQueryModel();//créer un modèle
    model1->setQuery("select REF_FOURN from FOURNITURE")  ;

    ui->comboBox_2->setModel(model1);
    ui->a->setValidator( new QRegExpValidator(QRegExp("[0-9]*"),this) );
    ui->c->setValidator( new QRegExpValidator(QRegExp("[a-z-A-Z_]+"),this) );
    ui->b->setValidator( new QRegExpValidator(QRegExp("[a-z-A-Z_]+"),this) );
    ui->d->setValidator( new QRegExpValidator(QRegExp("[0-9]*"),this) );
    ui->e->setValidator( new QRegExpValidator(QRegExp("[0-9]*"),this) );

}


fourniture::~fourniture()
{
    delete ui;
}





void fourniture::on_pushButton_2_clicked()//choisir
{
    QString val=ui->comboBox->currentText()  ;
    QSqlQuery query ;
   query.prepare("select * from FOURNITURE where REF_FOURN='"+val+"'") ;//requête sera réutilisable pour différentes valeurs

  if (query.exec())
  {
      while (query.next())
{

        ui->a2->setText(query.value(0).toString()) ;
        ui->b2->setText(query.value(1).toString()) ;
        ui->c2->setText(query.value(2).toString()) ;
        ui->d2->setText(query.value(3).toString()) ;
        ui->e1->setText(query.value(4).toString()) ;

  }
}
}

void fourniture::on_pushButton_6_clicked()//dou
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select REF_FOURN from FOURNITURE")  ;
    ui->comboBox->setModel(model) ;
}

void fourniture::on_pushButton_5_clicked()//modifier
{
    QSqlQuery query ;
    QString val=ui->comboBox->currentText()  ;
    QString Ref_fourn=ui->a2->text() ;
    QString nom_fourn=ui->b2->text();
    QString type_fourn=ui->c2->text();
    QString quant_fourn=ui->d2->text();
    QString prix=ui->e1->text();

 //if ( ui->b->hasAcceptableInput() && ui->d->hasAcceptableInput())
 //{


    query.prepare("UPDATE FOURNITURE SET  REF_FOURN= :Ref_fourn , NOM_FOURN= :nom_fourn , TYPE_FOURN= :type_fourn , QUANT_FOURN= :quant_fourn , PRIX= :prix where REF_FOURN= :Ref_fourn");

    query.bindValue("Ref_fourn:",val) ;
    query.bindValue(":Ref_fourn", Ref_fourn);
    query.bindValue(":nom_fourn", nom_fourn);
    query.bindValue(":type_fourn",type_fourn);
    query.bindValue(":quant_fourn", quant_fourn);
    query.bindValue(":prix", prix);

    if(query.exec())
    {
        ui->taba->setModel(tmpfourn.afficher());//refresh
        QSqlQueryModel * model1= new QSqlQueryModel();
        model1->setQuery("select REF_FOURN from FOURNITURE")  ;
        ui->comboBox_2->setModel(model1) ;
        QMessageBox::information(nullptr, QObject::tr("Modifier un fourniture"),
                    QObject::tr("fourniture modifié!.\n"
                                "Click Close to exit."), QMessageBox::Close);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un fourniture"),
                    QObject::tr("Erreur !.\n"
                                "Click Close to exit."), QMessageBox::Close);


}
 /*else
     QMessageBox::critical(nullptr, QObject::tr("Modifier un fourniture"),
                 QObject::tr("Erreur ! Verifier votre format.\n"
                             "Click Close to exit."), QMessageBox::Close);


}*/





void fourniture::on_Delete_clicked()
{
    int Ref_fourn = ui->comboBox_2->currentText().toInt() ;
    bool test=tmpfourn.supprimer(Ref_fourn);
    if(test)
    {ui->taba->setModel(tmpfourn.afficher());//refresh

        QSqlQueryModel * model1= new QSqlQueryModel();
        model1->setQuery("select REF_FOURN from FOURNITURE")  ;
        ui->comboBox_2->setModel(model1) ;

        QMessageBox::information(nullptr, QObject::tr("Supprimer un fourniture"),
                    QObject::tr("fourniture supprimé.\n"
                                "Click Close to exit."), QMessageBox::Close);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un fourniture"),
                    QObject::tr("Erreur !.\n"
                                "Click Close to exit."), QMessageBox::Close);


}


void fourniture::on_pushButton_7_clicked()//chercher
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString res=ui->lineEdit->text() ;

    QSqlQuery query , Quary ;
    query.prepare("select * from FOURNITURE where NOM_FOURN=:nom_fourn OR TYPE_FOURN=:type_fourn") ;
    query.bindValue(":nom_fourn",res) ;
    /*Quary.prepare("select * from FOURNITURE where REF_FOURN=:nom_fourn  OR QUANT_FOURN=:nom_fourn  OR PRIX=:nom_fourn ") ;
    Quary.bindValue(":type_fourn",res) ;*/
if ( query.exec())

   {
    mySystemTrayIcon->showMessage(tr("Notification"),tr("Recherche effectuée!")) ;

    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF_FOURN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_FOURN"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE_FOURN"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUNT_FOURN"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX"));
    ui->taba->setModel(model) ; }
 /*if (Quary.exec())
{
      mySystemTrayIcon->showMessage(tr("Notification"),tr("Recherche effectuée!")) ;
    model->setQuery(Quary);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF_FOURN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_FOURN"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE_FOURN"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUNT_FOURN"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX"));

    ui->taba->setModel(model) ;

}*/


}


void fourniture::on_radioButton_clicked()
{
    /*QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from FOURNITURE ORDER BY NOM_FOURN ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr(" REF_FOURN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_FOURN"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE_FOURN"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUNT_FOURN"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX"));

ui->taba->setModel(model) ;*/
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from FOURNITURE ORDER BY NOM_FOURN");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF_FOURN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_FOURN"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE_FOURN"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUNT_FOURN"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX"));

    ui->taba->setModel(model) ;
}

void fourniture::on_radioButton_2_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from FOURNITURE ORDER BY NOM_FOURN desc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF_FOURN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_FOURN"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE_FOURN"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUNT_FOURN"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX"));

    ui->taba->setModel(model) ;

}


void fourniture::on_radioButton_3_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from FOURNITURE ORDER BY QUANT_FOURN desc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr(" REF_FOURN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_FOURN"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE_FOURN"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUNT_FOURN"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX"));

ui->taba->setModel(model) ;
}

void fourniture::on_radioButton_6_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from FOURNITURE ORDER BY  QUANT_FOURN ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr(" REF_FOURN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_FOURN"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE_FOURN"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUNT_FOURN"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX"));

ui->taba->setModel(model) ;
}

void fourniture::on_pa_clicked()//imprimer
{


    QPrinter printer ;//QPrinter:
    //printer un objet
    printer.setPrinterName("imprimer") ;
    QPrintDialog dialog (&printer,this) ;//permet aux utilisateurs de modifier les paramètres relatifs au document ex nb,page..
    if ( dialog.exec()== QDialog::Rejected) return ;//QDialog est la classe de base des boîtes de dialogue
    ui->mm->print(&printer) ;




}

void fourniture::on_pushButton_clicked()
{
    hide();
}

void fourniture::on_retour_clicked()
{
    hide();
}

void fourniture::on_retour_2_clicked()
{
    hide();
}

void fourniture::on_pushButton_3_clicked()
{
    hide();
}



void fourniture::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

void fourniture::on_sendBtn_2_clicked()
{
    Smtp* smtp = new Smtp(ui->uname_2->text(), ui->paswd_2->text(), ui->server_2->text(), ui->port_2->text().toUShort());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->uname_2->text(), ui->rcpt_2->text() , ui->subject_2->text(),ui->msg_2->toPlainText());
}

void fourniture::on_ajouter_clicked()
{
    int Ref_fourn = ui->a->text().toInt();
    QString type_fourn= ui->b->text();
    QString nom_fourn= ui->c->text();
    int quant_fourn = ui->d->text().toInt();
    int prix= ui->e->text().toInt();
    fournitures f(Ref_fourn,nom_fourn,type_fourn,quant_fourn,prix);



    if ( ui->b->hasAcceptableInput() && ui->d->hasAcceptableInput()&& ui->e->hasAcceptableInput()&& ui->a->hasAcceptableInput()&& ui->c->hasAcceptableInput())
{
bool test=f.ajouter();
 if(test)
{
     ui->taba->setModel(tmpfourn.afficher());//refresh
     QSqlQueryModel * model1= new QSqlQueryModel();

     model1->setQuery("select REF_FOURN from FOURNITURE")  ;
     ui->comboBox_2->setModel(model1) ;
    QMessageBox::information(nullptr, QObject::tr("Ajouter un fourniture"),
                 QObject::tr("fourniture  ajouté.\n"
                             "Click Close to exit."), QMessageBox::Close);

}
 else
 QMessageBox::critical(nullptr, QObject::tr("Ajouter un fourniture"),//tr()est définie dans  QObject pour traduire le texte du bouton
               QObject::tr("Erreur !.\n"
                             "Click Close to exit."), QMessageBox::Close);
}


 else {
 QMessageBox::critical(nullptr, QObject::tr("Ajouter un fourniture"),
           QObject::tr("Erreur ! Verifier votre format.\n"
                       "Click Close to exit."), QMessageBox::Close);
}

}
