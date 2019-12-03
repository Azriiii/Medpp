#include "secretaire.h"
#include "ui_secretaire.h"

secretaire::secretaire(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secretaire)
{
    ui->setupUi(this);
}

secretaire::~secretaire()
{
    delete ui;
}

void secretaire::on_signout_clicked()
{
     close() ;
}
