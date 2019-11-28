#include "loginsec.h"
#include "ui_loginsec.h"

loginSec::loginSec(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginSec)
{
    ui->setupUi(this);
}

loginSec::~loginSec()
{
    delete ui;
}

void loginSec::on_pushButton_2_clicked()
{
    close() ;
}

void loginSec::on_pushButton_clicked()
{
    sec = new secretaire(this) ;
    sec->show() ;
}
