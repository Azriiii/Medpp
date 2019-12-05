#include "fournisseurs.h"
#include "ui_fournisseurs.h"

fournisseurs::fournisseurs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fournisseurs)
{
    ui->setupUi(this);
}

fournisseurs::~fournisseurs()
{
    delete ui;
}
