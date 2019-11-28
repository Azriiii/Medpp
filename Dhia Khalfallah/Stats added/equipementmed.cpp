#include "equipementmed.h"
#include "ui_equipementmed.h"

equipementmed::equipementmed(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::equipementmed)
{
    ui->setupUi(this);
}

equipementmed::~equipementmed()
{
    delete ui;
}

void equipementmed::on_pushButton_clicked()
{
    hide() ;
}

void equipementmed::on_pushButton_3_clicked()
{
    hide() ;
}

void equipementmed::on_retour_2_clicked()
{
    hide();
}

void equipementmed::on_retour_clicked()
{
    hide();
}
