#ifndef PATIENT_H
#define PATIENT_H
#include "class_patient.h"
#include <QDialog>

namespace Ui {
class patient;
}
class QSystemTrayIcon;
class patient : public QDialog
{
    Q_OBJECT

public:
    explicit patient(QWidget *parent = nullptr);
    ~patient();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_tripatient_clicked();

private:
    Ui::patient *ui;
    class_patient temppatient;
    QSystemTrayIcon * mysysteme;
};

#endif // PATIENT_H
