#include "patients.h"
#include "ui_patients.h"

patients::patients(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::patients)
{
    ui->setupUi(this);
}

patients::~patients()
{
    delete ui;
}
