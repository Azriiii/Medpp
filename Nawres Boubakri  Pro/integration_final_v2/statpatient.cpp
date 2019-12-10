#include "statpatient.h"
#include "ui_statpatient.h"

statpatient::statpatient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::statpatient)
{
    ui->setupUi(this);
}

statpatient::~statpatient()
{
    delete ui;
}
