#include "medecin.h"
#include "ui_medecin.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtCharts/QChartView>
#include "personelsm.h"
#include "donutbreakdownchart.h"
#include <iostream>

Medecin::Medecin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Medecin)
{
    ui->setupUi(this);
}

Medecin::~Medecin()
{
    delete ui;
}

void Medecin::on_signout_clicked()
{
     close() ;
}

void Medecin::on_consultation_clicked()
{
    cons = new Consultations(this) ;
    cons->show() ;
}

void Medecin::on_ordonance_clicked()
{
    ord = new Ordonances(this) ;
    ord->show() ;
}

void Medecin::on_stats_clicked()
{
    stat = new stats(this) ;
    int mnbf,mnbm;/*,snbf,snbm ;*/
    Consultation C ;
    ordonnance S ;


    QPieSeries *series1 = new QPieSeries();


    mnbm=C.rougeole() ;
    mnbf=C.grippe() ;
    int mnbs=C.anemie();
    int d=C.diabete();


    int dol=S.doliprane();
    int ferv=S.fervexe() ;
    int asp=S.aspirine();
    int p=S.panadole();




    series1->setName(" Diagnostique ");
    series1->append("Rougeole",mnbm);
    series1->append("Grippe",mnbf);
    series1->append("Anemie",mnbs);
     series1->append("Diabete",d);

   QPieSeries *series2 = new QPieSeries();
    series2->setName("Traitement");
    series2->append("Doliprane",dol);
    series2->append("Fervexe",ferv);
     series2->append("Aspirine",asp);
      series2->append("Panadole",p);


    //![1]

    //![2]
    DonutBreakdownChart *donutBreakdown = new DonutBreakdownChart();
    donutBreakdown->setAnimationOptions(QChart::AllAnimations);
    donutBreakdown->setTitle("Repartition des consultations par maladie");
    donutBreakdown->legend()->setAlignment(Qt::AlignRight);
    donutBreakdown->addBreakdownSeries(series1, Qt::red);
    donutBreakdown->addBreakdownSeries(series2, Qt::blue);
    //![2]

    //![3]
    QMainWindow window;
    QChartView *chartView = new QChartView(donutBreakdown);
    chartView->setRenderHint(QPainter::Antialiasing);
    stat->setCentralWidget(chartView);
    stat->show();
}
