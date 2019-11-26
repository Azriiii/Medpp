#include "personelsmed.h"
#include "ui_personelsmed.h"
#include "personelsm.h"
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
PersonelsMed::PersonelsMed(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonelsMed)
{
    ui->setupUi(this);
    mySystemTrayIcon=new QSystemTrayIcon(this) ;
    mySystemTrayIcon->setIcon(QIcon(":/icon.png")) ;
    mySystemTrayIcon->setVisible(true) ;
    ui->TabPers->setModel(tmppers.afficher());
    ui->TabPers->setItemDelegateForColumn(6, new NumberFormatDelegate(this));
    ui->TabPers->setItemDelegateForColumn(7, new NumberFormatDelegate(this));

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select CIN from PERSONELS")  ;
    ui->comboBox->setModel(model) ;

    //qDebug() << (model->rowCount()) ;
    QSqlQueryModel * model1= new QSqlQueryModel();
    model1->setQuery("select CIN from PERSONELS")  ;
    ui->comboBox_2->setModel(model1) ;
     //qDebug() << (model1->rowCount()) ;
    QRegularExpression rx("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b",
                              QRegularExpression::CaseInsensitiveOption);

    ui->Mail->setValidator(new QRegularExpressionValidator(rx, this));
    ui->Mail_2->setValidator(new QRegularExpressionValidator(rx, this));
    ui->carteid->setValidator( new QRegExpValidator(QRegExp("[0-9]{8}"),this) );
    ui->carteid_2->setValidator( new QRegExpValidator(QRegExp("[0-9]{8}"),this) );
    ui->Tel->setValidator( new QRegExpValidator(QRegExp("[0-9]{8}"),this) );
    ui->Tel_2->setValidator( new QRegExpValidator(QRegExp("[0-9]{8}"),this) );

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
    QDate date= ui->dateEdit_2->date();
    QString sexe= ui->Sexe->text();
    int CIN = ui->carteid->text().toInt();
    int Telephone = ui->Tel->text().toInt();
    int Salaire = ui->Salaire->text().toInt();
    int Contrat = ui->LineEdit_6->text().toInt();
    int Horaire = ui->Horaire->text().toInt();

    QString mail= ui->Mail->text();

 PersonelsM p(occupation,specialite,nom,prenom,date,sexe,CIN,Telephone,Salaire,Contrat,Horaire,mail);

 if (ui->Mail->hasAcceptableInput()&& ui->carteid->hasAcceptableInput() && ui->Tel->hasAcceptableInput())
 {
 bool test=p.ajouter();
  if(test)
{ui->TabPers->setModel(tmppers.afficher());//refresh
      QSqlQueryModel * model1= new QSqlQueryModel();
      model1->setQuery("select CIN from PERSONELS")  ;
      ui->comboBox_2->setModel(model1) ;
       //qDebug() << (model1->rowCount()) ;
QMessageBox::information(nullptr, QObject::tr("Ajouter un personel"),
                  QObject::tr("Personel ajouté.\n"
                              "Click Close to exit."), QMessageBox::Close);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un personel"),
                  QObject::tr("Erreur !.\n"
                              "Click Close to exit."), QMessageBox::Close);
}


else {
QMessageBox::critical(nullptr, QObject::tr("Ajouter un personel"),
            QObject::tr("Erreur ! Verifier votre format.\n"
                        "Click Close to exit."), QMessageBox::Close);
}
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
    int CIN = ui->comboBox_2->currentText().toInt() ;
    bool test=tmppers.supprimer(CIN);
    if(test)
    {ui->TabPers->setModel(tmppers.afficher());//refresh

        QSqlQueryModel * model1= new QSqlQueryModel();
        model1->setQuery("select CIN from PERSONELS")  ;
        ui->comboBox_2->setModel(model1) ;
         //qDebug() << (model1->rowCount()) ;//refresh

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
    QString val=ui->comboBox->currentText()  ;
    QSqlQuery query ;
    query.prepare("select * from PERSONELS where CIN='"+val+"'") ;
    //query.bindValue(":id",val) ;
  if (query.exec())
  {
      while (query.next()) {


        ui->Occupation_2->setText(query.value(0).toString()) ;
        ui->Special_2->setText(query.value(1).toString()) ;
        ui->Nom_2->setText(query.value(2).toString()) ;
        ui->Prenom_2->setText(query.value(3).toString()) ;
        ui->dateEdit->setDate(query.value(4).toDate()) ;
        ui->Sexe_2->setText(query.value(5).toString()) ;
        ui->carteid_2->setText(query.value(6).toString()) ;
        ui->Tel_2->setText(query.value(7).toString()) ;
        ui->Salaire_2->setText(query.value(8).toString()) ;
        ui->LineEdit_7->setText(query.value(9).toString()) ;
        ui->Horaire_2->setText(query.value(10).toString()) ;
        ui->Mail_2->setText(query.value(11).toString()) ;
  }
}

}

void PersonelsMed::on_retour_2_clicked()
{
    hide() ;
}

void PersonelsMed::on_pushButton_4_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select CIN from PERSONELS")  ;
    ui->comboBox->setModel(model) ;
}





void PersonelsMed::on_pushButton_5_clicked()
{
    QSqlQuery query ;
    QString val=ui->comboBox->currentText()  ;
    QString occ=ui->Occupation_2->text() ;
    QString special=ui->Special_2->text();
    QString nom=ui->Nom_2->text();
    QString prenom=ui->Prenom_2->text();
    //QString date=ui->Date_2->text();
    QDate date1 =ui->dateEdit->date();
    QString sexe=ui->Sexe_2->text();
    QString cin=ui->carteid_2->text();
    QString tel=ui->Tel_2->text();
    QString sal=ui->Salaire_2->text();
    QString cont=ui->LineEdit_7->text();
    QString hor=ui->Horaire_2->text();
    QString mail=ui->Mail_2->text();
    //QDateTime date1 = QDateTime::fromString(date, "dd-MM-yyyy") ;
 if (ui->Mail_2->hasAcceptableInput()&& ui->carteid_2->hasAcceptableInput() && ui->Tel_2->hasAcceptableInput())
 {
    query.prepare("UPDATE PERSONELS SET  OCCUPATION= :occupation , SPECIALITE= :special , NOM= :nom , PRENOM= :prenom , DATEN = :date , SEXE = :sexe , CIN= :cin , TEL= :tel , SALAIRE= :sal , CONTRAT= :cont , HORAIRE= :hor , MAIL= :mail where CIN= :cin1 ");
    query.bindValue(":cin1",val) ;
    query.bindValue(":occupation",occ);
    query.bindValue(":special",special);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":date",date1);
    query.bindValue(":sexe",sexe);
    query.bindValue(":cin",cin);
    query.bindValue(":tel",tel);
    query.bindValue(":sal",sal);
    query.bindValue(":cont",cont);
    query.bindValue(":hor",hor);
    query.bindValue(":mail",mail);

    if(query.exec())
    {ui->TabPers->setModel(tmppers.afficher());//refresh
        QSqlQueryModel * model1= new QSqlQueryModel();
        model1->setQuery("select CIN from PERSONELS")  ;
        ui->comboBox_2->setModel(model1) ;
         //qDebug() << (model1->rowCount()) ;
        QMessageBox::information(nullptr, QObject::tr("Modifier un personel"),
                    QObject::tr("Personel modifié!.\n"
                                "Click Close to exit."), QMessageBox::Close);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un personel"),
                    QObject::tr("Erreur !.\n"
                                "Click Close to exit."), QMessageBox::Close);


}
 else
     QMessageBox::critical(nullptr, QObject::tr("Modifier un personel"),
                 QObject::tr("Erreur ! Verifier votre format.\n"
                             "Click Close to exit."), QMessageBox::Close);

}

void PersonelsMed::on_radioButton_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PERSONELS ORDER BY NOM");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Occupation "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Specialite"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date de naissance"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Sexe"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("telephone"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("Salaire"));
model->setHeaderData(9, Qt::Horizontal, QObject::tr("Contrat"));
model->setHeaderData(10, Qt::Horizontal, QObject::tr("Heure de travail"));
model->setHeaderData(11, Qt::Horizontal, QObject::tr("Mail"));
ui->TabPers->setModel(model) ;
}

void PersonelsMed::on_radioButton_2_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PERSONELS ORDER BY NOM desc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Occupation "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Specialite"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date de naissance"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Sexe"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("telephone"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("Salaire"));
model->setHeaderData(9, Qt::Horizontal, QObject::tr("Contrat"));
model->setHeaderData(10, Qt::Horizontal, QObject::tr("Heure de travail"));
model->setHeaderData(11, Qt::Horizontal, QObject::tr("Mail"));
ui->TabPers->setModel(model) ;
}

void PersonelsMed::on_radioButton_3_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PERSONELS ORDER BY CONTRAT");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Occupation "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Specialite"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date de naissance"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Sexe"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("telephone"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("Salaire"));
model->setHeaderData(9, Qt::Horizontal, QObject::tr("Contrat"));
model->setHeaderData(10, Qt::Horizontal, QObject::tr("Heure de travail"));
model->setHeaderData(11, Qt::Horizontal, QObject::tr("Mail"));
ui->TabPers->setModel(model) ;
}

void PersonelsMed::on_radioButton_4_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PERSONELS ORDER BY SALAIRE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Occupation "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Specialite"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date de naissance"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Sexe"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("telephone"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("Salaire"));
model->setHeaderData(9, Qt::Horizontal, QObject::tr("Contrat"));
model->setHeaderData(10, Qt::Horizontal, QObject::tr("Heure de travail"));
model->setHeaderData(11, Qt::Horizontal, QObject::tr("Mail"));
ui->TabPers->setModel(model) ;
}

void PersonelsMed::on_radioButton_6_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PERSONELS ORDER BY CONTRAT desc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Occupation "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Specialite"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date de naissance"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Sexe"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("telephone"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("Salaire"));
model->setHeaderData(9, Qt::Horizontal, QObject::tr("Contrat"));
model->setHeaderData(10, Qt::Horizontal, QObject::tr("Heure de travail"));
model->setHeaderData(11, Qt::Horizontal, QObject::tr("Mail"));
ui->TabPers->setModel(model) ;

}

void PersonelsMed::on_radioButton_5_clicked()
{
        QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from PERSONELS ORDER BY SALAIRE desc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Occupation "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Specialite"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date de naissance"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("telephone"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Salaire"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("Contrat"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("Heure de travail"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("Mail"));
    ui->TabPers->setModel(model) ;
}

void PersonelsMed::on_radioButton_7_clicked()
{
    ui->TabPers->setModel(tmppers.afficher());
}

void PersonelsMed::on_pushButton_6_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString res=ui->lineEdit->text() ;

    QSqlQuery query , Quary ;
    query.prepare("select * from PERSONELS where NOM=:nom OR PRENOM=:nom OR MAIL=:nom OR OCCUPATION=:nom OR SPECIALITE=:nom OR SEXE=:nom") ;
    query.bindValue(":nom",res) ;
    Quary.prepare("select * from PERSONELS where CIN=:nom OR TEL=:nom OR CONTRAT=:nom OR SALAIRE=:nom") ;
    Quary.bindValue(":nom",res) ;
if ( query.exec())

   {
    mySystemTrayIcon->showMessage(tr("Notification"),tr("Recherche effectuée!")) ;

    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Occupation "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Specialite"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date de naissance"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("telephone"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Salaire"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("Contrat"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("Heure de travail"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("Mail"));
    ui->TabPers->setModel(model) ; }
 if (Quary.exec())
{
      mySystemTrayIcon->showMessage(tr("Notification"),tr("Recherche effectuée!")) ;
    model->setQuery(Quary);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Occupation "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Specialite"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date de naissance"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("telephone"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Salaire"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("Contrat"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("Heure de travail"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("Mail"));
    ui->TabPers->setModel(model) ;

}




}



void PersonelsMed::on_pushButton_7_clicked()
{
    QPrinter printer ;
    printer.setPrinterName("blablabla") ;
    QPrintDialog dialog (&printer,this) ;
    if ( dialog.exec()== QDialog::Rejected) return ;
    ui->textEdit->print(&printer) ;
}
