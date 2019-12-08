#include "admin.h"
#include "ui_admin.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtCharts/QChartView>
#include "personelsm.h"
#include "stafft.h"
#include "stati.h"
#include "donutbreakdownchart.h"
#include <iostream>
using namespace  std ;
admin::admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
}

admin::~admin()
{
    delete ui;
}

void admin::on_pushButton_7_clicked()
{
    close() ;
}

void admin::on_pushButton_clicked()
{
    personelM = new PersonelsMed(this) ;
    personelM->show() ;
}

void admin::on_pushButton_3_clicked()
{
    equip = new equipementmed(this) ;
    equip->show() ;
}

void admin::on_pushButton_2_clicked()
{
    staff = new stafftechnique(this) ;
    staff->show() ;
}

void admin::on_pushButton_6_clicked()
{
    four = new fourniture(this) ;
    four->show() ;
}

void admin::on_pushButton_5_clicked()
{
    fourn = new fournisseurs(this) ;
    fourn->show() ;
}

void admin::on_pushButton_4_clicked()
{
  /*  stat = new stats(this) ;
    int mnbf,mnbm,snbf,snbm ;
    PersonelsM P ;
    stafft S ;
    QPieSeries *series1 = new QPieSeries();
    mnbm=P.medcalM() ;
    mnbf=P.medcalF() ;
    snbm=S.stcalM() ;
    snbf=S.stcalF() ;
    series1->setName("Personel Medical");
    series1->append("Homme",mnbm);
    series1->append("Femme",mnbf);

    QPieSeries *series2 = new QPieSeries();
    series2->setName("Personel technique");
    series2->append("Homme",snbm);
    series2->append("Femme",snbf);


    //![1]

    //![2]
    DonutBreakdownChart *donutBreakdown = new DonutBreakdownChart();
    donutBreakdown->setAnimationOptions(QChart::AllAnimations);
    donutBreakdown->setTitle("Repartition du personel par sexe");
    donutBreakdown->legend()->setAlignment(Qt::AlignRight);
    donutBreakdown->addBreakdownSeries(series1, Qt::red);
    donutBreakdown->addBreakdownSeries(series2, Qt::blue);
    //![2]

    //![3]
    QMainWindow window;
    QChartView *chartView = new QChartView(donutBreakdown);
    chartView->setRenderHint(QPainter::Antialiasing);
    stat->setCentralWidget(chartView);
    stat->show();*/

    stati stat ;
    stat.setModal(true);
     stat.exec();

}
