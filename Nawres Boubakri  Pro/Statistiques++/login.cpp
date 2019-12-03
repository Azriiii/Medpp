#include "login.h"
#include "ui_login.h"
#include "admin.h"
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{

  Admin = new admin(this) ;
  Admin->show() ;

}

void login::on_pushButton_2_clicked()
{
    close() ;
}
