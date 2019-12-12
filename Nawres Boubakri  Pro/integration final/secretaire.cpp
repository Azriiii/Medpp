#include "secretaire.h"
#include "ui_secretaire.h"
#include"patients.h"
#include"class_patient.h"
#include"statpatient.h"
#include <QtCharts/QChartView>

#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include<QBarSet>
#include <QBarCategoryAxis>

#include <QtCharts>

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

void secretaire::on_patients_clicked()
{
    pat  = new patients(this) ;
    pat->show() ;
}

void secretaire::on_rdv_clicked()
{
    r=new RDV(this);
    r->show();
}

void secretaire::on_stats_clicked()
{
   stat=new statpatient(this);
   stat->show();

   stat=new statpatient(this);
    //![1]
        QBarSet *set0 = new QBarSet("HOMME");

        QBarSet *set1 = new QBarSet("FEMME");

        int nb0=0;
        QSqlQuery query0("select * from patient where SEXE= 'homme'");
        while(query0.next())
        {
            nb0++;
        }
        int nb1=0;
        QSqlQuery query1("select * from patient where SEXE= 'femme' ");
        while(query1.next())
        {
            nb1++;
        }


        *set0 << nb0 ;
        *set1 << nb1 ;

    //![1]

    //![2]
        QBarSeries *series = new QBarSeries();
        series->append(set0);
        series->append(set1);


    //![2]

    //![3]
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("HOMME/FEMME");
        chart->setAnimationOptions(QChart::SeriesAnimations);
    //![3]

    //![4]
        QStringList categories;
        categories << "NBR";

        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);
   int nb=0;
   QSqlQuery query("select * from patient ");
   while(query.next())
   {
       nb++;
   }

        QValueAxis *axisY = new QValueAxis();
        axisY->setRange(0,nb);
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);
    //![4]

    //![5]
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
    //![5]

    //![6]
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        stat->setCentralWidget(chartView);
        stat->show();

}
