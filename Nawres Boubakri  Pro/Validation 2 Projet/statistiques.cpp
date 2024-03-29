#include "statistiques.h"
#include "ui_statistiques.h"
#include <QSqlRecord>
#include <QSqlQuery>
#include<QBrush>
#include"qcustomplot.h"

Statistiques::Statistiques(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statistiques)
{
    ui->setupUi(this);
    this->setWindowTitle("Statistiques");
       makePolt();
}

Statistiques::~Statistiques()
{
    delete ui;
}











void Statistiques::makePolt()
{



    ///////////////////////////////////////////////////////////////////////
    // set dark background gradient:
       QLinearGradient gradient(0, 0, 0, 400);
       gradient.setColorAt(0, QColor(90, 90, 90));
       gradient.setColorAt(0.38, QColor(105, 105, 105));
       gradient.setColorAt(1, QColor(70, 70, 70));
       ui->customPlot->setBackground(QBrush(gradient));

       // create empty bar chart objects:
       QCPBars *amande = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
       amande->setAntialiased(false);
       amande->setStackingGap(1);
        //set names and colors:
       amande->setName("Repartition des patient selon les consultations");
       amande->setPen(QPen(QColor(0, 168, 140).lighter(130)));
       amande->setBrush(QColor(0, 168, 140));
       // stack bars on top of each other:


       // prepare x axis with country labels:
       QVector<double> ticks;
       QVector<QString> labels;
       QSqlQuery q;
       int i=0;
      // q.exec("select reff_const from consultation");
        q.exec("select reff_const from CONSULTATION ORDER BY REFF_CONST ");
       while (q.next()) {
           QString adresse= q.value(0).toString();
           i++;
           ticks<<i;
           labels <<adresse;
       }
       QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
       textTicker->addTicks(ticks, labels);
       ui->customPlot->xAxis->setTicker(textTicker);
       ui->customPlot->xAxis->setTickLabelRotation(60);
       ui->customPlot->xAxis->setSubTicks(false);
       ui->customPlot->xAxis->setTickLength(0, 4);
       ui->customPlot->xAxis->setRange(0, 8);
       ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
       ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
       ui->customPlot->xAxis->grid()->setVisible(true);
       ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
       ui->customPlot->xAxis->setTickLabelColor(Qt::white);
       ui->customPlot->xAxis->setLabelColor(Qt::white);

       // prepare y axis:
       ui->customPlot->yAxis->setRange(0,10);
       ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
       ui->customPlot->yAxis->setLabel("Statistiques");
       ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
       ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
       ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
       ui->customPlot->yAxis->grid()->setSubGridVisible(true);
       ui->customPlot->yAxis->setTickLabelColor(Qt::white);
       ui->customPlot->yAxis->setLabelColor(Qt::white);
       ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
       ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

       // Add data:

       QVector<double> PlaceData;
    // QSqlQuery q1("select reff_const from consultation  ");
       //select * from CONSULTATION ORDER BY REFF_CONST
   //  QSqlQuery q1("select id_patient from consultation ");
                QSqlQuery q1("select id_patient from CONSULTATION ORDER BY REFF_CONST ");
       while (q1.next()) {
                     int  nbr_fautee = q1.value(0).toInt();
                     PlaceData<< nbr_fautee;
                       }
       amande->setData(ticks, PlaceData);
       // setup legend:
       ui->customPlot->legend->setVisible(true);
       ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
       ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
       ui->customPlot->legend->setBorderPen(Qt::NoPen);
       QFont legendFont = font();
       legendFont.setPointSize(10);
       ui->customPlot->legend->setFont(legendFont);
       ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}


