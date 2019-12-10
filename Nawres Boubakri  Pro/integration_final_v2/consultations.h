#ifndef CONSULTATIONS_H
#define CONSULTATIONS_H
#include"consultation.h"
#include <QDialog>
#include <QMediaPlayer>

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

  /*  void on_pushButton_2_clicked();

   void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_2_clicked();



    void on_pushButton_10_clicked();*/



   // void on_statistiques_clicked();

    void on_Ajouter_clicked();

    void on_modifier_consultation_clicked();

    void on_supprimer_consultation_clicked();

    void on_rechercher_clicked();



    void on_sauvegarder_clicked();

    void on_imprimer_clicked();

    void on_tri_date_clicked();

    void on_tri_reff_clicked();

    void on_tri_id_clicked();

private:
    Ui::Consultations *ui;
    Consultation tmpconsultation,tmpc,tmc,tmpC;
    QSystemTrayIcon *mySystemTrayIcon ;

};

#endif // CONSULTATIONS_H
