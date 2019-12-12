#include "fournisseurs.h"
#include "ui_fournisseurs.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QDebug>
#include <QDateTime>
#include <QSystemTrayIcon>
#include <QStyledItemDelegate>
#include "numberformatdelegate.h"
#include <QRegExpValidator>
#include <QPrinter>
#include <QPrintDialog>
#include<QDialog>
#include<QGraphicsScene>
#include"maher2.h"
#include"maher3.h"


fournisseurs::fournisseurs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fournisseurs)
{
    ui->setupUi(this);


    mySystemTrayIcon=new QSystemTrayIcon(this) ;
    mySystemTrayIcon->setIcon(QIcon(":/icon.png")) ;
    mySystemTrayIcon->setVisible(true) ;
    ui->TabPers_2->setModel(tmppers.afficher());
    ui->TabPers->setModel(tmppers2.afficher2());
    ui->TabPers->setItemDelegateForColumn(6, new NumberFormatDelegate(this));
    ui->TabPers->setItemDelegateForColumn(7, new NumberFormatDelegate(this));

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select ID_FACTURE from FACTURES")  ;
    //ui->comboBox->setModel(model) ;

    //qDebug() << (model->rowCount()) ;
    QSqlQueryModel * model1= new QSqlQueryModel();
    model1->setQuery("select ID8FACTURE from FACTURES")  ;
   // ui->comboBox_2->setModel(model1) ;
     //qDebug() << (model1->rowCount()) ;
  //  QRegularExpression rx("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b",
                        //      QRegularExpression::CaseInsensitiveOption);

    ui->ID_FACTURE->setValidator( new QRegExpValidator(QRegExp("[0-9]{8}"),this) );
    ui->ID_FOURNISSEUR_2->setValidator( new QRegExpValidator(QRegExp("[0-9]{8}"),this) );
    ui->ID_FOURNISSEUR_1->setValidator( new QRegExpValidator(QRegExp("[0-9]{8}"),this) );
    ui->ID_FACTURE_2->setValidator( new QRegExpValidator(QRegExp("[0-9]{8}"),this) );
    ui->RIB->setValidator( new QRegExpValidator(QRegExp("[0-9]{8}"),this) );
    ui->RIB_2->setValidator( new QRegExpValidator(QRegExp("[0-9]{8}"),this) );

}

fournisseurs::~fournisseurs()
{
    delete ui;
}

void fournisseurs::on_pushButton_14_clicked()
{
    QPrinter printer ;
    printer.setPrinterName("imprimante HP") ;
    QPrintDialog dialog; //(&printer,this) ;
    if ( dialog.exec()== QDialog::Rejected) return ;
    ui->textEdit->print(&printer) ;
}

void fournisseurs::on_pushButton_15_clicked()
{
    int ID_FACTURE = ui->lineEdit_2->text().toInt();

    bool test=tmppers.supprimer(ID_FACTURE);
    if(test)
    {
        ui->TabPers_2->setModel(tmppers.afficher());//refresh

        QSqlQueryModel * model1= new QSqlQueryModel();
        model1->setQuery("select ID_FACTURE from FACTURES")  ;
       // ui->textEdit_2->setModel(model1) ;
         //qDebug() << (model1->rowCount()) ;//refresh

        QMessageBox::information(nullptr, QObject::tr("Supprimer un facture"),
                    QObject::tr("facture supprimé.\n"
                                "Click Close to exit."), QMessageBox::Close);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un facture"),
                    QObject::tr("Erreur !.\n"
                                "Click Close to exit."), QMessageBox::Close);


}

void fournisseurs::on_pushButton_18_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString res=ui->lineEdit_4->text() ;

    QSqlQuery query , Quary ;
    query.prepare("select * from FOURNISSEUR where NOM_FOURNISSEUR=:nom OR TYPE_PRODUIT=:nom") ;
    query.bindValue(":nom",res) ;
if ( query.exec())

   {
    mySystemTrayIcon->showMessage(tr("Notification"),tr("Recherche effectuée!")) ;

    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FOURNISSEUR"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_PRODUIT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM_FOURNISSEUR"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DUREE_CONTRAT"));

    ui->TabPers->setModel(model) ; }
}



void fournisseurs::on_pushButton_16_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString res=ui->lineEdit->text() ;

    QSqlQuery query , Quary ;
    query.prepare("select * from FACTURES where ETAT=:nom OR ORDRE_DE=:nom") ;
    query.bindValue(":nom",res) ;
if ( query.exec())

   {
    mySystemTrayIcon->showMessage(tr("Notification"),tr("Recherche effectuée!")) ;

    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FACTURE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("RIB"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_FACT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ORDRE_DE"));

    ui->TabPers_2->setModel(model) ; }
}



void fournisseurs::on_radioButton_2_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from FACTURES ORDER BY ID_FACTURE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FACTURE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("RIB"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_FACT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT "));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ORDRE_DE"));

ui->TabPers_2->setModel(model) ;
}

void fournisseurs::on_radioButton_7_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from FACTURES ORDER BY ORDRE_DE desc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FACTURE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("RIB"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_FACT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT "));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ORDRE_DE"));

ui->TabPers_2->setModel(model) ;

}

void fournisseurs::on_radioButton_4_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from FACTURES ORDER BY ETAT");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FACTURE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("RIB"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_FACT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT "));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ORDRE_DE"));


ui->TabPers_2->setModel(model) ;
}

/*void fournisseurs::on_pushButton_19_clicked()
{
    QString get_ORDRE_DE();
    QString get_ETAT();
    QDate get_DATE_FACT();

    int get_ID_FACTURE();
    int get_RIB();
    bool ajouter();

    QString ORDRE_DE= ui->ORDRE_DE->text();
    QString ETAT= ui->ETAT->text();
     QDate DATE_FACT= ui->dateEdit_2->date();
    int RIB = ui->RIB->text().toInt();
    int ID_FACTURE = ui->ID_FACTURE->text().toInt();

 maher2 p(ORDRE_DE,ETAT,DATE_FACT,ID_FACTURE,RIB);

 if (ui->ID_FACTURE->hasAcceptableInput() && ui->RIB->hasAcceptableInput())
 {
 bool test=p.ajouter();
  if(test)
{ui->TabPers_2->setModel(tmppers.afficher());//refresh
      QSqlQueryModel * model1= new QSqlQueryModel();
      model1->setQuery("select ID_FACTURE from FACTURES")  ;
     // ui->comboBox_2->setModel(model1) ;
       //qDebug() << (model1->rowCount()) ;
QMessageBox::information(nullptr, QObject::tr("Ajouter un FACTURE"),
                  QObject::tr("FACTURE ajouté.\n"
                              "Click Close to exit."), QMessageBox::Close);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un FACTURE"),
                  QObject::tr("Erreur !.\n"
                              "Click Close to exit."), QMessageBox::Close);
}


else {
QMessageBox::critical(nullptr, QObject::tr("Ajouter un FACTURE"),
            QObject::tr("Erreur ! Verifier votre format.\n"
                        "Click Close to exit."), QMessageBox::Close);
}
}*/




void fournisseurs::on_pushButton_8_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select ID_FACTURE from FACTURES")  ;
    ui->comboBox->setModel(model) ;
}

void fournisseurs::on_pushButton_9_clicked()
{
    QString val=ui->comboBox->currentText()  ;
    QSqlQuery query ;
    query.prepare("select * from FACTURES where ID_FACTURE='"+val+"'") ;
    //query.bindValue(":id",val) ;
  if (query.exec())
  {
      while (query.next()) {


        ui->ID_FACTURE->setText(query.value(0).toString()) ;
        ui->RIB->setText(query.value(1).toString()) ;
        ui->DATE_FACT_2->setDate(query.value(4).toDate()) ;
        ui->ETAT->setText(query.value(5).toString()) ;
        ui->ORDRE_DE->setText(query.value(6).toString()) ;

  }
}

}

void fournisseurs::on_pushButton_11_clicked()
{
    bool test ;
   // QSqlQuery query
    QString val=ui->comboBox->currentText()  ;
    int ID_FACTURE = ui->ID_FACTURE_2->text().toInt();
    int RIB = ui->RIB_2->text().toInt();
    QDate DATE_FACT =ui->DATE_FACT_2->date();
    QString ETAT=ui->ETAT_2->text();
    QString ORDRE_DE=ui->ORDER_de_2->text();
  //  query.prepare("UPDATE FACTURES SET  ID_FACTURE= :ID_FACTURE , RIB= :RIB , DATE_FACT= :DATE_FACT , ETAT = :ETAT , ORDRE_DE = :ORDRE_DE");

 if (ui->ID_FACTURE_2->hasAcceptableInput() && ui->RIB_2->hasAcceptableInput())
 {

     maher2 P ;
     test = P.modifier( ID_FACTURE , RIB , DATE_FACT , ETAT , ORDRE_DE);
  if(test)
    { ui->TabPers_2->setModel(tmppers.afficher());//refresh
        QSqlQueryModel * model1= new QSqlQueryModel();
        model1->setQuery("select ID_FACTURE from FACTURE")  ;
        ui->comboBox->setModel(model1) ;
         //qDebug() << (model1->rowCount()) ;
        QMessageBox::information(nullptr, QObject::tr("Modifier un FACTURE"),
                    QObject::tr("FACTURE modifié!.\n"
                                "Click Close to exit."), QMessageBox::Close);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un FACTURE"),
                    QObject::tr("Erreur !.\n"
                                "Click Close to exit."), QMessageBox::Close);


}
 else
     QMessageBox::critical(nullptr, QObject::tr("Modifier un FACTURE"),
                 QObject::tr("Erreur ! Verifier votre format.\n"
                             "Click Close to exit."), QMessageBox::Close);











}



void fournisseurs::on_pushButton_5_clicked()
{
    bool test ;
   // QSqlQuery query
    QString val=ui->comboBox_55->currentText()  ;
    int ID_FOURNISSEUR = ui->ID_FOURNISSEUR_2->text().toInt();
    QString TYPE_PRODUIT=ui->TYPE_PRODUIT_2->text();
    QString NOM_FOURNISSEUR=ui->NOM_FOURNISSEUR_2->text();
    int DUREE_CONTRAT=ui->DUREE_CONTRAT_2->text().toInt();


 if (ui->ID_FOURNISSEUR_2->hasAcceptableInput())
 {

     maher3 P ;
     test = P.modifier2( ID_FOURNISSEUR , TYPE_PRODUIT , NOM_FOURNISSEUR , DUREE_CONTRAT );
  if(test)
    { ui->TabPers->setModel(tmppers2.afficher2());//refresh
        QSqlQueryModel * model1= new QSqlQueryModel();
        model1->setQuery("select ID_FOURNISSEUR from FOURNISSEUR")  ;
        ui->comboBox->setModel(model1) ;
         //qDebug() << (model1->rowCount()) ;
        QMessageBox::information(nullptr, QObject::tr("Modifier un ID_FOURNISSEUR"),
                    QObject::tr("ID_FOURNISSEUR modifié!.\n"
                                "Click Close to exit."), QMessageBox::Close);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un FOURNISSEUR"),
                    QObject::tr("Erreur !.\n"
                                "Click Close to exit."), QMessageBox::Close);


}
 else
     QMessageBox::critical(nullptr, QObject::tr("Modifier un ID_FOURNISSEUR"),
                 QObject::tr("Erreur ! Verifier votre format.\n"
                             "Click Close to exit."), QMessageBox::Close);












}

void fournisseurs::on_save_clicked()
{
    QString get_NOM_FOURNISSEUR();
    QString get_TYPE_PRODUIT();

    int get_ID_FOURNISSEUR();
    int get_DUREE_CONTRAT();
    bool ajouter2();

    QString TYPE_PRODUIT= ui->TYPE_PRODUIT_1->text();
    QString NOM_FOURNISSEUR= ui->NOM_FOURNISSEUR_1->text();
    int DUREE_CONTRAT = ui->DUREE_CONTRAT_1->text().toInt();
    int ID_FOURNISSEUR = ui->ID_FOURNISSEUR_1->text().toInt();

 maher3 p(ID_FOURNISSEUR,TYPE_PRODUIT,NOM_FOURNISSEUR,DUREE_CONTRAT);

 if (ui->ID_FOURNISSEUR_1->hasAcceptableInput())
 {
 bool test=p.ajouter2();
  if(test)
{ui->TabPers->setModel(tmppers2.afficher2());//refresh
      QSqlQueryModel * model1= new QSqlQueryModel();
      model1->setQuery("select ID_FOURNISSEUR from FOURNISSEUR")  ;
     // ui->comboBox_2->setModel(model1) ;
       //qDebug() << (model1->rowCount()) ;
QMessageBox::information(nullptr, QObject::tr("Ajouter un FOURNISSEUR"),
                  QObject::tr("ID_FOURNISSEUR ajouté.\n"
                              "Click Close to exit."), QMessageBox::Close);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un FOURNISSEUR"),
                  QObject::tr("Erreur !.\n"
                              "Click Close to exit."), QMessageBox::Close);
}


else {
QMessageBox::critical(nullptr, QObject::tr("Ajouter un FOURNISSEUR"),
            QObject::tr("Erreur ! Verifier votre format.\n"
                        "Click Close to exit."), QMessageBox::Close);
}
}

void fournisseurs::on_radioButton_5_clicked()
{
     QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from FOURNISSEUR ORDER BY ID_FOURNISSEUR Desc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FOURNISSEUR"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_PRODUIT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM_FOURNISSEUR"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DUREE_CONTRAT"));
    ui->TabPers->setModel(model) ;
}

void fournisseurs::on_radioButton_6_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
   model->setQuery("select * from FOURNISSEUR ORDER BY DUREE_CONTRAT");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FOURNISSEUR"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_PRODUIT"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM_FOURNISSEUR"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("DUREE_CONTRAT"));
   ui->TabPers->setModel(model) ;
}

void fournisseurs::on_pushButton_17_clicked()
{
    QPrinter printer ;
    printer.setPrinterName("imprimante HP") ;
    QPrintDialog dialog; //(&printer,this) ;
    if ( dialog.exec()== QDialog::Rejected) return ;
    ui->textEdit->print(&printer) ;
}

void fournisseurs::on_pushButton_20_clicked()
{
    int ID_FOURNISSEUR = ui->lineEdit_525->text().toInt();

    bool test=tmppers2.supprimer2(ID_FOURNISSEUR);
    if(test)
    {
        ui->TabPers->setModel(tmppers2.afficher2());//refresh

        QSqlQueryModel * model1= new QSqlQueryModel();
        model1->setQuery("select ID_FOURNISSEUR from FOURNISSEUR")  ;
       // ui->textEdit_2->setModel(model1) ;
         //qDebug() << (model1->rowCount()) ;//refresh

        QMessageBox::information(nullptr, QObject::tr("Supprimer un founrniseur"),
                    QObject::tr("facture supprimé.\n"
                                "Click Close to exit."), QMessageBox::Close);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un founrniseur"),
                    QObject::tr("Erreur !.\n"
                                "Click Close to exit."), QMessageBox::Close);

}

void fournisseurs::on_pushButton_4_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select ID_FOURNISSEUR from FOURNISSEUR")  ;
    ui->comboBox_55->setModel(model) ;
}

void fournisseurs::on_pushButton_2_clicked()
{
    QString val=ui->comboBox_55->currentText()  ;
    QSqlQuery query ;
    query.prepare("select * from FOURNISSEUR where ID_FOURNISSEUR='"+val+"'") ;
    //query.bindValue(":id",val) ;
  if (query.exec())
  {
      while (query.next()) {


        ui->ID_FOURNISSEUR_2->setText(query.value(0).toString()) ;
        ui->TYPE_PRODUIT_2->setText(query.value(1).toString()) ;
        ui->NOM_FOURNISSEUR_2->setText(query.value(2).toString()) ;
        ui->DUREE_CONTRAT_2->setText(query.value(3).toString()) ;

  }
}

}

void fournisseurs::on_pushButton_21_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select ID_FOURNISSEUR from FOURNISSEUR")  ;
    ui->comboBox_55->setModel(model) ;
}

void fournisseurs::on_pushButton_19_clicked()
{
    QString get_ORDRE_DE();
    QString get_ETAT();
    QDate get_DATE_FACT();

    int get_ID_FACTURE();
    int get_RIB();
    bool ajouter();

    QString ORDRE_DE= ui->ORDRE_DE->text();
    QString ETAT= ui->ETAT->text();
     QDate DATE_FACT= ui->dateEdit_2->date();
    int RIB = ui->RIB->text().toInt();
    int ID_FACTURE = ui->ID_FACTURE->text().toInt();

 maher2 p(ORDRE_DE,ETAT,DATE_FACT,ID_FACTURE,RIB);

 if (ui->ID_FACTURE->hasAcceptableInput() && ui->RIB->hasAcceptableInput())
 {
 bool test=p.ajouter();
  if(test)
{ui->TabPers_2->setModel(tmppers.afficher());//refresh
      QSqlQueryModel * model1= new QSqlQueryModel();
      model1->setQuery("select ID_FACTURE from FACTURES")  ;
     // ui->comboBox_2->setModel(model1) ;
       //qDebug() << (model1->rowCount()) ;
QMessageBox::information(nullptr, QObject::tr("Ajouter un FACTURE"),
                  QObject::tr("FACTURE ajouté.\n"
                              "Click Close to exit."), QMessageBox::Close);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un FACTURE"),
                  QObject::tr("Erreur !.\n"
                              "Click Close to exit."), QMessageBox::Close);
}


else {
QMessageBox::critical(nullptr, QObject::tr("Ajouter un FACTURE"),
            QObject::tr("Erreur ! Verifier votre format.\n"
                        "Click Close to exit."), QMessageBox::Close);
}
}
