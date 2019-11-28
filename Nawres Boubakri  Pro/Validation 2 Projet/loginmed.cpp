#include "loginmed.h"
#include "ui_loginmed.h"
#include "medecin.h"
#include<QDialog>
#include<QMessageBox>
#include"consultations.h"
#include <QSystemTrayIcon>
#include <QStyledItemDelegate>

loginMed::loginMed(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginMed)
{
    ui->setupUi(this);
    mySystem=new QSystemTrayIcon(this) ;
    mySystem->setIcon(QIcon(":/icon.png")) ;
    mySystem->setVisible(true) ;

    QString username = ui->id->text();
    QString password = ui->mdp->text();

    ui->mdp->setClearButtonEnabled(true);
    ui->id->setClearButtonEnabled(true);

    ui->mdp->setEchoMode(QLineEdit::Password);


   // ui->id->addAction(username,QLineEdit::LeadingPosition);
}

loginMed::~loginMed()
{
    delete ui;
}

void loginMed::on_pushButton_3_clicked()
{
    close() ;
}

void loginMed::on_pushButton_clicked()
{

    QString username = ui->id->text();
    QString password = ui->mdp->text();

  /*  ui->mdp->setClearButtonEnabled(true);
    ui->id->setClearButtonEnabled(true);

    ui->mdp->setEchoMode(QLineEdit::Password);
*/

    if(username == "nawres" && password =="nawres") {
     mySystem->showMessage(tr("Notifications"),tr("You are Connected"));
      QMessageBox::information(this, "Bienvenue ","Bienvenue ");

      medecin=new Medecin(this);
      medecin->show();
    }
    else
    {
      QMessageBox::information(this, "Mot de passe Incorrect","Veuillez Vérifier vos Cordonnées");
    }
}
