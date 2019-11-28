#ifndef MEDECIN_H
#define MEDECIN_H

#include <QDialog>
#include "consultations.h"
#include "ordonances.h"
#include "rdv.h"
#include "patients.h"

namespace Ui {
class Medecin;
}

class Medecin : public QDialog
{
    Q_OBJECT

public:
    explicit Medecin(QWidget *parent = nullptr);
    ~Medecin();

private slots:
    void on_signout_clicked();

    void on_consultation_clicked();

    void on_ordonance_clicked();

    void on_rdv_clicked();

    void on_patients_clicked();

private:
    Ui::Medecin *ui;
    Consultations *cons ;
    Ordonances *ord ;
    RDV *r ;
    patients *pat ;
};

#endif // MEDECIN_H
