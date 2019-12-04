#include "factures.h"
#include "ui_factures.h"

factures::factures(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::factures)
{
    ui->setupUi(this);
}

factures::~factures()
{
    delete ui;
}
