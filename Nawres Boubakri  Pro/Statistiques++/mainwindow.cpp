#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "loginmed.h"
#include "loginsec.h"
#include <QSystemTrayIcon>
#include <QStyledItemDelegate>
#include"consultations.h"
#include<QtMultimedia>
#include<QMediaPlayer>
#include <QDialog>
#include"statistiques.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player=new QMediaPlayer(this);
    connect(player,&QMediaPlayer::positionChanged,this,&MainWindow::on_positionChanged);
    connect(player,&QMediaPlayer::durationChanged,this,&MainWindow::on_durationChanged);

   /* Statistiques*a=new Statistiques();
    a->show();*/

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


void MainWindow::on_durationChanged(qint64 position)
{
ui->slidervolume->setValue(position);
}

void MainWindow::on_positionChanged(qint64 position)
{
ui->sliderprogress->setValue(position);
}
void MainWindow::on_strart_Button_clicked()
{
 player->setMedia(QUrl::fromLocalFile("C:/Users/esprit/Desktop/QT nawres/FirstProject/son/son2.wav"));
 player->play();
 qDebug()<<player->errorString();
}

void MainWindow::on_stop_button_clicked()
{
    player->stop();
}

void MainWindow::on_slidervolume_sliderMoved(int position)
{
    player->setVolume(position);
}

void MainWindow::on_sliderprogress_sliderMoved(int position)
{
    player->setPosition(position);
}
