#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"patient.h"
#include"redv.h"
#include "patient_agent.h"
#include"rdv_agent.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    patient patient;
    patient.setModal(true);
    patient.exec();

}

void MainWindow::on_pushButton_2_clicked()
{
    redv redv;
    redv.setModal(true);
    redv.exec();

}

void MainWindow::on_pushButton_3_clicked()
{
    patient_agent patient_agent;
    patient_agent.setModal(true);
    patient_agent.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    rdv_agent rdv_agent;
    rdv_agent.setModal(true);
    rdv_agent.exec();
}

void MainWindow::on_pushButton_5_clicked()
{
    close();
}
