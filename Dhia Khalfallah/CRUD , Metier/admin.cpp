#include "admin.h"
#include "ui_admin.h"

admin::admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
}

admin::~admin()
{
    delete ui;
}

void admin::on_pushButton_7_clicked()
{
    close() ;
}

void admin::on_pushButton_clicked()
{
    personelM = new PersonelsMed(this) ;
    personelM->show() ;
}

void admin::on_pushButton_3_clicked()
{
    equip = new equipementmed(this) ;
    equip->show() ;
}

void admin::on_pushButton_2_clicked()
{
    staff = new stafftechnique(this) ;
    staff->show() ;
}

void admin::on_pushButton_6_clicked()
{
    four = new fourniture(this) ;
    four->show() ;
}

void admin::on_pushButton_5_clicked()
{
    fourn = new fournisseurs(this) ;
    fourn->show() ;
}
