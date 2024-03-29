#include "stafftechnique.h"
#include "ui_stafftechnique.h"
#include "stafft.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QDebug> //stafftechnique
#include <QDateTime>
#include <QSystemTrayIcon>
#include <QStyledItemDelegate>
#include "numberformatdelegate.h"
#include <QRegExpValidator>
#include <QPrinter>
#include <QPrintDialog>
#include <QDateTime>
#include <QChartView>
#include <QBarSeries>
#include <QBarSet>
#include <QLegend>
#include <QBarCategoryAxis>
#include <QValueAxis>

stafftechnique::stafftechnique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stafftechnique)
{
    ui->setupUi(this);
    mySystemTrayIcon=new QSystemTrayIcon(this) ;
    mySystemTrayIcon->setIcon(QIcon(":/icon.png")) ;
    mySystemTrayIcon->setVisible(true) ;
    ui->TabPers->setModel(tmppers.afficher());
    ui->TabPers->setItemDelegateForColumn(6, new NumberFormatDelegate(this));
    ui->TabPers->setItemDelegateForColumn(7, new NumberFormatDelegate(this));

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select CIN from STAFF")  ;
    ui->comboBox->setModel(model) ;

    //qDebug() << (model->rowCount()) ;
    QSqlQueryModel * model1= new QSqlQueryModel();
    model1->setQuery("select CIN from STAFF")  ;
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

stafftechnique::~stafftechnique()
{
    delete ui;
}

void stafftechnique::on_save_clicked()
{
    QString occupation= ui->Occupation->text();
    QString role= ui->Role->text();
    QString nom= ui->Nom->text();
    QString prenom= ui->Prenom->text();
    QDate date= ui->dateEdit_2->date();
    QString sexe= ui->Sexe->currentText();
    int CIN = ui->carteid->text().toInt();
    int Telephone = ui->Tel->text().toInt();
    int Salaire = ui->Salaire->text().toInt();
    int Contrat = ui->LineEdit_6->text().toInt();
    int Horaire = ui->Horaire->text().toInt();

    QString mail= ui->Mail->text();

 stafft p(occupation,role,nom,prenom,date,sexe,CIN,Telephone,Salaire,Contrat,Horaire,mail);

 if (ui->Mail->hasAcceptableInput()&& ui->carteid->hasAcceptableInput() && ui->Tel->hasAcceptableInput())
 {
 bool test=p.ajouter();
  if(test)
{ui->TabPers->setModel(tmppers.afficher());//refresh
      QSqlQueryModel * model1= new QSqlQueryModel();
      model1->setQuery("select CIN from STAFF")  ;
      ui->comboBox_2->setModel(model1) ;
       //qDebug() << (model1->rowCount()) ;
QMessageBox::information(nullptr, QObject::tr("Ajouter un staff"),
                  QObject::tr("staff ajouté.\n"
                              "Click Close to exit."), QMessageBox::Close);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un staff"),
                  QObject::tr("Erreur !.\n"
                              "Click Close to exit."), QMessageBox::Close);
}


else {
QMessageBox::critical(nullptr, QObject::tr("Ajouter un staff"),
            QObject::tr("Erreur ! Verifier votre format.\n"
                        "Click Close to exit."), QMessageBox::Close);
}
}
void stafftechnique::on_retour_clicked()
{
    hide() ;
}


void stafftechnique::on_pushButton_clicked()
{
    hide() ;
}

void stafftechnique::on_pushButton_3_clicked()
{
    hide() ;
}

void stafftechnique::on_Delete_clicked()
{
    int CIN = ui->comboBox_2->currentText().toInt() ;
    bool test=tmppers.supprimer(CIN);
    if(test)
    {ui->TabPers->setModel(tmppers.afficher());//refresh

        QSqlQueryModel * model1= new QSqlQueryModel();
        model1->setQuery("select CIN from STAFF")  ;
        ui->comboBox_2->setModel(model1) ;
         //qDebug() << (model1->rowCount()) ;//refresh

        QMessageBox::information(nullptr, QObject::tr("Supprimer un staff"),
                    QObject::tr("staff supprimé.\n"
                                "Click Close to exit."), QMessageBox::Close);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un staff"),
                    QObject::tr("Erreur !.\n"
                                "Click Close to exit."), QMessageBox::Close);


}




void stafftechnique::on_pushButton_2_clicked()
{
    QString val=ui->comboBox->currentText()  ;
    QSqlQuery query ;
    query.prepare("select * from STAFF where CIN='"+val+"'") ;
    //query.bindValue(":id",val) ;
  if (query.exec())
  {
      while (query.next()) {


        ui->Occupation_2->setText(query.value(0).toString()) ;
        ui->Role_2->setText(query.value(1).toString()) ;
        ui->Nom_2->setText(query.value(2).toString()) ;
        ui->Prenom_2->setText(query.value(3).toString()) ;
        ui->dateEdit->setDate(query.value(4).toDate()) ;
        ui->Sexe_2->setCurrentText(query.value(5).toString()) ;
        ui->carteid_2->setText(query.value(6).toString()) ;
        ui->Tel_2->setText(query.value(7).toString()) ;
        ui->Salaire_2->setText(query.value(8).toString()) ;
        ui->LineEdit_7->setText(query.value(9).toString()) ;
        ui->Horaire_2->setText(query.value(10).toString()) ;
        ui->Mail_2->setText(query.value(11).toString()) ;
  }
}

}

void stafftechnique::on_retour_2_clicked()
{
    hide() ;
}

void stafftechnique::on_pushButton_4_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select CIN from STAFF")  ;
    ui->comboBox->setModel(model) ;
}





void stafftechnique::on_pushButton_5_clicked()
{
    bool test ;
    stafft S ;
    QString val=ui->comboBox->currentText()  ;
    QString occ=ui->Occupation_2->text() ;
    QString Role=ui->Role_2->text();
    QString nom=ui->Nom_2->text();
    QString prenom=ui->Prenom_2->text();
    //QString date=ui->Date_2->text();
    QDate date1 =ui->dateEdit->date();
    QString sexe=ui->Sexe_2->currentText();
    QString cin=ui->carteid_2->text();
    QString tel=ui->Tel_2->text();
    QString sal=ui->Salaire_2->text();
    QString cont=ui->LineEdit_7->text();
    QString hor=ui->Horaire_2->text();
    QString mail=ui->Mail_2->text();
    //QDateTime date1 = QDateTime::fromString(date, "dd-MM-yyyy") ;
 if (ui->Mail_2->hasAcceptableInput()&& ui->carteid_2->hasAcceptableInput() && ui->Tel_2->hasAcceptableInput())
 {
   /* query.prepare("UPDATE STAFF SET  OCCUPATION= :occupation , ROLE= :Role , NOM= :nom , PRENOM= :prenom , DATENS = :date , SEXE = :sexe , CIN= :cin , TEL= :tel , SALAIRE= :sal , CONTRAT= :cont , HORAIRE= :hor , MAIL= :mail where CIN= :cin1 ");
    query.bindValue(":cin1",val) ;
    query.bindValue(":occupation",occ);
    query.bindValue(":Role",Role);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":date",date1);
    query.bindValue(":sexe",sexe);
    query.bindValue(":cin",cin);
    query.bindValue(":tel",tel);
    query.bindValue(":sal",sal);
    query.bindValue(":cont",cont);
    query.bindValue(":hor",hor);
    query.bindValue(":mail",mail);*/
  test = S.modifier(val , occ , Role, nom , prenom , date1 , sexe, cin, tel, sal, cont, hor, mail) ;
    if(test)
    {ui->TabPers->setModel(tmppers.afficher());//refresh
        QSqlQueryModel * model1= new QSqlQueryModel();
        model1->setQuery("select CIN from STAFF")  ;
        ui->comboBox_2->setModel(model1) ;
         //qDebug() << (model1->rowCount()) ;
        QMessageBox::information(nullptr, QObject::tr("Modifier un staff"),
                    QObject::tr("staff modifié!.\n"
                                "Click Close to exit."), QMessageBox::Close);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un staff"),
                    QObject::tr("Erreur !.\n"
                                "Click Close to exit."), QMessageBox::Close);


}
 else
     QMessageBox::critical(nullptr, QObject::tr("Modifier un staff"),
                 QObject::tr("Erreur ! Verifier votre format.\n"
                             "Click Close to exit."), QMessageBox::Close);

}

void stafftechnique::on_radioButton_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from STAFF ORDER BY NOM");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Occupation "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Role"));
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

void stafftechnique::on_radioButton_2_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from STAFF ORDER BY NOM desc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Occupation "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Role"));
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

void stafftechnique::on_radioButton_3_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from STAFF ORDER BY CONTRAT");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Occupation "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Role"));
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

void stafftechnique::on_radioButton_4_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from STAFF ORDER BY SALAIRE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Occupation "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Role"));
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

void stafftechnique::on_radioButton_6_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from STAFF ORDER BY CONTRAT desc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Occupation "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Role"));
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

void stafftechnique::on_radioButton_5_clicked()
{
        QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from STAFF ORDER BY SALAIRE desc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Occupation "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Role"));
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

void stafftechnique::on_radioButton_7_clicked()
{
    ui->TabPers->setModel(tmppers.afficher());
}

void stafftechnique::on_pushButton_6_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString res=ui->lineEdit->text() ;

    QSqlQuery query , Quary ;
    query.prepare("select * from STAFF where NOM=:nom OR PRENOM=:nom OR MAIL=:nom OR OCCUPATION=:nom OR ROLE=:nom OR SEXE=:nom") ;
    query.bindValue(":nom",res) ;
    Quary.prepare("select * from STAFF where CIN=:nom OR TEL=:nom OR CONTRAT=:nom OR SALAIRE=:nom") ;
    Quary.bindValue(":nom",res) ;
if ( query.exec())

   {
    mySystemTrayIcon->showMessage(tr("Notification"),tr("Recherche effectuée!")) ;

    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Occupation "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Role"));
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
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Role"));
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



void stafftechnique::on_pushButton_7_clicked()
{
    QPrinter printer ;
    printer.setPrinterName("blablabla") ;
    QPrintDialog dialog (&printer,this) ;
    if ( dialog.exec()== QDialog::Rejected) return ;
    ui->textEdit->print(&printer) ;
}
