#include "eya.h"
#include "ui_eya.h"

eya::eya(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::eya)
{
    ui->setupUi(this);
}

eya::~eya()
{
    delete ui;
}
