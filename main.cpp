#include "mainwindow.h"
#include<QtSql>
#include<QtDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("eya-3");
    db.setUserName("eya");
    db.setPassword("09779471");
    if (db.open())
    {
        qDebug()<<"data base open";
    }
    else
    {
        qDebug()<<"data base closed or there is an error";
    }
    return a.exec();
}

