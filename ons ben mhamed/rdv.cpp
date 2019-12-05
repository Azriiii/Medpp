#include "rdv.h"
#include "ui_rdv.h"

RDV::RDV(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RDV)
{
    ui->setupUi(this);
}

RDV::~RDV()
{
    delete ui;
}
