#include "stats.h"
#include "ui_stats.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtCharts/QChartView>
#include "donutbreakdownchart.h"

stats::stats(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::stats)
{
    ui->setupUi(this);
}

stats::~stats()
{
    delete ui;
}

void stats::on_pushButton_clicked()
{
hide();
}
