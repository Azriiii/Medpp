#include "medecin.h"
#include "ui_medecin.h"

Medecin::Medecin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Medecin)
{
    ui->setupUi(this);
}

Medecin::~Medecin()
{
    delete ui;
}

void Medecin::on_signout_clicked()
{
     close() ;
}

void Medecin::on_consultation_clicked()
{
    cons = new Consultations(this) ;
    cons->show() ;
}

void Medecin::on_ordonance_clicked()
{
    ord = new Ordonances(this) ;
    ord->show() ;
}
