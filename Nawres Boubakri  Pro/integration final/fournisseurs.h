#ifndef FOURNISSEURS_H
#define FOURNISSEURS_H
#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QDateTime>
#include <QDialog>
#include<maher2.h>
#include<maher3.h>

namespace Ui {
class fournisseurs;
}
class  QSystemTrayIcon ;

class fournisseurs : public QDialog
{
    Q_OBJECT

public:
    explicit fournisseurs(QWidget *parent = nullptr);
    ~fournisseurs();
     QSqlQueryModel * afficher();

private slots:
    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_16_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_7_clicked();

    void on_radioButton_4_clicked();

   // void on_pushButton_19_clicked();

    void on_RIB_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_5_clicked();

    void on_save_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_19_clicked();

private:
    Ui::fournisseurs *ui;
    maher2 tmppers ;
    maher3 tmppers2;
    QSystemTrayIcon *mySystemTrayIcon ;
};

#endif // FOURNISSEURS_H
