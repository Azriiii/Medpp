#ifndef REDV_H
#define REDV_H

#include <QDialog>
#include"class_rdv.h"
#include"class_patient.h"
namespace Ui {
class redv;
}

class redv : public QDialog
{
    Q_OBJECT

public:
    explicit redv(QWidget *parent = nullptr);
    ~redv();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_rechercher_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::redv *ui;
    class_rdv temprdv;
  class_patient p;
  stat stat;

};

#endif // REDV_H
