#ifndef SECRETAIRE_H
#define SECRETAIRE_H
#include"class_patient.h"
#include"patients.h"
#include"rdv.h"
#include <QDialog>
#include"statpatient.h"

namespace Ui {
class secretaire;
}

class secretaire : public QDialog
{
    Q_OBJECT

public:
    explicit secretaire(QWidget *parent = nullptr);
    ~secretaire();

private slots:
    void on_signout_clicked();

    void on_patients_clicked();

    void on_rdv_clicked();

    void on_stats_clicked();

private:
    Ui::secretaire *ui;
    patients * pat;
    RDV *r;
    statpatient *stat;

};

#endif // SECRETAIRE_H
