#ifndef PATIENTS_H
#define PATIENTS_H
#include"class_patient.h"
#include <QDialog>

namespace Ui {
class patients;
}
class QSystemTrayIcon;

class patients : public QDialog
{
    Q_OBJECT

public:
    explicit patients(QWidget *parent = nullptr);
    ~patients();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_tripatient_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::patients *ui;
  class_patient temppatient;
    QSystemTrayIcon * mysysteme;
};

#endif // PATIENTS_H
