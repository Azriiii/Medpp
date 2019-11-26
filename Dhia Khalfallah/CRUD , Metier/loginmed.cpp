#include "loginmed.h"
#include "ui_loginmed.h"
#include "medecin.h"
#include <QString>
#include <QMessageBox>
loginMed::loginMed(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginMed)
{
    ui->setupUi(this);
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
    QString res = ui->lineEdit->text() ;
    QString res1 = ui->lineEdit_2->text() ;
    if (res=="medecin" && res1=="medecin")
    {
    medecin = new Medecin(this) ;
    medecin->show() ;
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur d'authentification"),
                    QObject::tr("Information incorrecte .\n"
                                "Click Close to exit."), QMessageBox::Close);
    }

}
