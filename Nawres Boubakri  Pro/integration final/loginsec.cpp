#include "loginsec.h"
#include "ui_loginsec.h"
#include <QMessageBox>
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
    QString res = ui->lineEdit->text() ;
    QString res1 = ui->lineEdit_2->text() ;
    if (res=="secretaire" && res1=="secretaire")
    {
        sec = new secretaire(this) ;
        sec->show() ;
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur d'authentification"),
                    QObject::tr("Information incorrecte .\n"
                                "Click Close to exit."), QMessageBox::Close);
    }


}
