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

void Medecin::on_rdv_clicked()
{
    r = new RDV(this) ;
    r->show() ;
}

void Medecin::on_patients_clicked()
{
    pat = new patients(this) ;
    pat->show ;
}
