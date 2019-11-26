#include "fourniture.h"
#include "ui_fourniture.h"

fourniture::fourniture(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fourniture)
{
    ui->setupUi(this);
}

fourniture::~fourniture()
{
    delete ui;
}
