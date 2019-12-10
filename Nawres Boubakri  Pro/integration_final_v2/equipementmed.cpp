#include "equipementmed.h"
#include "ui_equipementmed.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQueryModel>
#include <QSystemTrayIcon>
#include <QPrintDialog>
#include <QPrinter>

equipementmed::equipementmed(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::equipementmed)
{
    mySystemTrayIcon=new QSystemTrayIcon(this) ;
    mySystemTrayIcon->setIcon(QIcon(":/icon.png")) ;
    mySystemTrayIcon->setVisible(true) ;
    ui->setupUi(this);
    ui->taba->setModel(tmpequip.afficher());
   QSqlQueryModel * model= new QSqlQueryModel();// to customize the contents of the data before showing it to the user
    model->setQuery("select REF_EQUIP from EQUIPEMENT ")  ;
    ui->comboBox->setModel(model) ;
    QSqlQueryModel * model1= new QSqlQueryModel();
    model1->setQuery("select REF_EQUIP  from EQUIPEMENT ")  ;
    ui->comboBox_2->setModel(model1);
      ui->a->setValidator( new QRegExpValidator(QRegExp("[0-9]*"),this) );
      ui->b->setValidator( new QRegExpValidator(QRegExp("[a-z-A-Z_]+"),this) );
      ui->c->setValidator( new QRegExpValidator(QRegExp("[0-9]*"),this) );
      ui->d->setValidator( new QRegExpValidator(QRegExp("[0-9]*"),this) );



}

equipementmed::~equipementmed()
{
    delete ui;
}

void equipementmed::on_pushButton_clicked()
{
    hide() ;
}

void equipementmed::on_pushButton_3_clicked()
{
    hide() ;
}

void equipementmed::on_retour_2_clicked()
{
    hide();
}

void equipementmed::on_retour_clicked()
{
    hide();
}

void equipementmed::on_save_clicked()
{
    int Ref_equip = ui->a->text().toInt();
    QString type_equip= ui->b->text();
    int quant_equip = ui->c->text().toInt();
    int prix= ui->d->text().toInt();
    equipement e(Ref_equip,type_equip,quant_equip,prix);



    if ( ui->b->hasAcceptableInput() && ui->a->hasAcceptableInput()&& ui->c->hasAcceptableInput()&& ui->d->hasAcceptableInput())
{
bool test=e.ajouter();
 if(test)
{
     ui->taba->setModel(tmpequip.afficher());//refresh
     QSqlQueryModel * model1= new QSqlQueryModel();

     model1->setQuery("select REF_EQUIP from EQUIPEMENT")  ;
     ui->comboBox_2->setModel(model1) ;
QMessageBox::information(nullptr, QObject::tr("Ajouter un equipement"),
                 QObject::tr("equipement ajouté.\n"
                             "Click Close to exit."), QMessageBox::Close);

}
 else
     QMessageBox::critical(nullptr, QObject::tr("Ajouter un equipement"),
                 QObject::tr("Erreur !.\n"
                             "Click Close to exit."), QMessageBox::Close);
}


else {
QMessageBox::critical(nullptr, QObject::tr("Ajouter un equipement"),
           QObject::tr("Erreur ! Verifier votre format.\n"
                       "Click Close to exit."), QMessageBox::Close);
}

}



void equipementmed::on_pushButton_6_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select REF_EQUIP from EQUIPEMENT")  ;
    ui->comboBox->setModel(model) ;
}

void equipementmed::on_pushButton_2_clicked()
{
    QString val=ui->comboBox->currentText()  ;
    QSqlQuery query ;
    query.prepare("select * from EQUIPEMENT where REF_EQUIP='"+val+"'") ;
  if (query.exec())
  {
      while (query.next()) {


        ui->a2->setText(query.value(0).toString()) ;
        ui->b2->setText(query.value(1).toString()) ;
        ui->c2->setText(query.value(2).toString()) ;
        ui->d2->setText(query.value(3).toString()) ;


  }
}
}

void equipementmed::on_pushButton_5_clicked()
{
    QSqlQuery query ;
    QString val=ui->comboBox->currentText()  ;
    QString Ref_equip=ui->a2->text() ;
    QString type_equip=ui->b2->text();
    QString quant_equip=ui->c2->text();
    QString prix=ui->d2->text();

 /*if ( ui->b->hasAcceptableInput() && ui->d->hasAcceptableInput())
 {*/


    query.prepare("UPDATE EQUIPEMENT SET  REF_EQUIP= :Ref_equip ,TYPE_EQUIP= :type_equip , QUANT_EQUIP= :quant_equip , PRIX= :prix where REF_EQUIP= :Ref_equip");

    query.bindValue("Ref_equip:",val) ;
    query.bindValue(":Ref_equip", Ref_equip);
    query.bindValue(":type_equip",type_equip);
    query.bindValue(":quant_equip", quant_equip);
    query.bindValue(":prix", prix);

    if(query.exec())
    {
        ui->taba->setModel(tmpequip.afficher());//refresh
        QSqlQueryModel * model1= new QSqlQueryModel();
        model1->setQuery("select REF_EQUIP from EQUIPEMENT")  ;
        ui->comboBox_2->setModel(model1) ;
        QMessageBox::information(nullptr, QObject::tr("Modifier un equipement"),
                    QObject::tr("equipement modifié!.\n"
                                "Click Close to exit."), QMessageBox::Close);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un equipement"),
                    QObject::tr("Erreur !.\n"
                                "Click Close to exit."), QMessageBox::Close);


}
 /*else
     QMessageBox::critical(nullptr, QObject::tr("Modifier un equipement"),
                 QObject::tr("Erreur ! Verifier votre format.\n"
                             "Click Close to exit."), QMessageBox::Close);


}*/


void equipementmed::on_Delete_clicked()
{

    int Ref_equip = ui->comboBox_2->currentText().toInt() ;
    bool test=tmpequip.supprimer(Ref_equip);
    if(test)
    {ui->taba->setModel(tmpequip.afficher());//refresh

        QSqlQueryModel * model1= new QSqlQueryModel();
        model1->setQuery("select REF_EQUIP from EQUIPEMENT")  ;
        ui->comboBox_2->setModel(model1) ;

        QMessageBox::information(nullptr, QObject::tr("Supprimer un equipement"),
                    QObject::tr(" equipement supprimé.\n"
                                "Click Close to exit."), QMessageBox::Close);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un equipement"),
                    QObject::tr("Erreur !.\n"
                                "Click Close to exit."), QMessageBox::Close);
}

void equipementmed::on_pushButton_7_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString res=ui->lineEdit->text() ;

    QSqlQuery query , Quary ;
    query.prepare("select * from EQUIPEMENT where TYPE_EQUIP=:type_equip") ;
    query.bindValue(":type_equip",res) ;
    Quary.prepare("select * from EQUIPEMENT where REF_EQUIP=:type_equip  OR QUANT_EQUIP=:type_equip  OR PRIX=:type_equip ") ;
    Quary.bindValue(":type_equip",res) ;
if ( query.exec())

   {
    mySystemTrayIcon->showMessage(tr("Notification"),tr("Recherche effectuée!")) ;

    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF_EQUIP"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_EQUIP"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUNT_EQUIP"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX"));
    ui->taba->setModel(model) ; }
 if (Quary.exec())
{
      mySystemTrayIcon->showMessage(tr("Notification"),tr("Recherche effectuée!")) ;
    model->setQuery(Quary);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF_EQUIP"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_EQUIP"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUNT_EQUIP"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX"));

    ui->taba->setModel(model) ;

}

}

void equipementmed::on_radioButton_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from EQUIPEMENT ORDER BY TYPE_EQUIP  ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr(" REF_EQUIP"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_EQUIP"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUNT_EQUIP"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX"));

ui->taba->setModel(model) ;
}

void equipementmed::on_radioButton_2_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from EQUIPEMENT ORDER BY TYPE_EQUIP desc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr(" REF_EQUIP"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_EQUIP"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUNT_EQUIP"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX"));

    ui->taba->setModel(model) ;
}

void equipementmed::on_radioButton_3_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from EQUIPEMENT ORDER BY QUANT_EQUIP ");


model->setHeaderData(0, Qt::Horizontal, QObject::tr(" REF_EQUIP"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE_EQUIP"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUNTEQUIPFOURN"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX"));

ui->taba->setModel(model) ;
}

void equipementmed::on_radioButton_6_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from EQUIPEMENT ORDER BY  QUANT_EQUIP desc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr(" REF_EQUIP"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE_EQUIP"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUNT_EQUIP"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX"));

ui->taba->setModel(model) ;
}

void equipementmed::on_pa_clicked()
{
    QPrinter printer ;
    printer.setPrinterName("imprimer") ;
    QPrintDialog dialog (&printer,this) ;
    if ( dialog.exec()== QDialog::Rejected) return ;
    ui->mm->print(&printer) ;
}
