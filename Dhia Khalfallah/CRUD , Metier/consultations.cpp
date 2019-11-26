#include "consultations.h"
#include "ui_consultations.h"

Consultations::Consultations(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Consultations)
{
    ui->setupUi(this);
}

Consultations::~Consultations()
{
    delete ui;
}

void Consultations::on_pushButton_clicked()
{
    hide() ;
}

void Consultations::on_pushButton_3_clicked()
{
    hide() ;
}

void Consultations::on_pushButton_5_clicked()
{
    hide() ;
}

void Consultations::on_pushButton_7_clicked()
{
    hide() ;
}
