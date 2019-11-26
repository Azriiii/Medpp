#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "loginmed.h"
#include "loginsec.h"

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


void MainWindow::on_ad_clicked()
{
    login Login1 ;
    Login1.setModal(true) ;
    Login1.exec() ;


}

void MainWindow::on_med_clicked()
{
    loginMed Login1 ;
    Login1.setModal(true) ;
    Login1.exec() ;


}

void MainWindow::on_sec_clicked()
{
    loginSec Login1 ;
    Login1.setModal(true) ;
    Login1.exec() ;


}
