#include "login.h"
#include "ui_login.h"
#include "admin.h"
#include <QMessageBox>
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->lineEdit_2->Password ;
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    QString res = ui->lineEdit->text() ;
    QString res1 = ui->lineEdit_2->text() ;
    if (res=="admin" && res1=="admin")
    {

        Admin = new admin(this) ;
        Admin->show() ;
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur d'authentification"),
                    QObject::tr("Information incorrecte .\n"
                                "Click Close to exit."), QMessageBox::Close);
    }


}

void login::on_pushButton_2_clicked()
{
    close() ;
}
