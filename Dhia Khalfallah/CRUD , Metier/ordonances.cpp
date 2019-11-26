#include "ordonances.h"
#include "ui_ordonances.h"

Ordonances::Ordonances(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ordonances)
{
    ui->setupUi(this);
}

Ordonances::~Ordonances()
{
    delete ui;
}

void Ordonances::on_pushButton_clicked()
{
    hide() ;
}

void Ordonances::on_pushButton_3_clicked()
{
    hide () ;
}

void Ordonances::on_pushButton_5_clicked()
{
    hide() ;
}

void Ordonances::on_pushButton_7_clicked()
{
    hide() ;
}
