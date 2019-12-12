#ifndef ORDONANCES_H
#define ORDONANCES_H

#include <QDialog>
#include"ordonnance.h"
namespace Ui {
class Ordonances;
}

class Ordonances : public QDialog
{
    Q_OBJECT

public:
    explicit Ordonances(QWidget *parent = nullptr);
    ~Ordonances();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();



   /* void on_ajouter_clicked();

    void on_modifier_clicked();

    void on_supprimer_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_rechercher_ord_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_8_clicked();*/

    void on_ajouter_ordonnance_clicked();

    void on_modifier_clicked();

    void on_supprimer_ordonnance_clicked();

    void on_rechercher_ord_clicked();

    void on_tri_const_clicked();

    void on_tri_ord_clicked();

    void on_tri_date_clicked();

    void on_sauvegarder_clicked();

    void on_imprimer_clicked();

    void on_actualiser_clicked();

    void on_choisir_clicked();

private:
    Ui::Ordonances *ui;
    ordonnance tmpordonnance;
};

#endif // ORDONANCES_H
