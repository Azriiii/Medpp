#ifndef CONSULTATIONS_H
#define CONSULTATIONS_H
#include"consultation.h"
#include <QDialog>

namespace Ui {
class Consultations;
}
class  QSystemTrayIcon ;
class Consultations : public QDialog
{
    Q_OBJECT

public:
    explicit Consultations(QWidget *parent = nullptr);
    ~Consultations();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_2_clicked();

private:
    Ui::Consultations *ui;
    Consultation tmpconsultation,tmpc,tmc;
    QSystemTrayIcon *mySystemTrayIcon ;

};

#endif // CONSULTATIONS_H
