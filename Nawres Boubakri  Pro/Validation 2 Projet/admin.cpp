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
