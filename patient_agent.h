#ifndef PATIENT_AGENT_H
#define PATIENT_AGENT_H
#include"class_patient.h"
#include <QDialog>

namespace Ui {
class patient_agent;
}

class patient_agent : public QDialog
{
    Q_OBJECT

public:
    explicit patient_agent(QWidget *parent = nullptr);
    ~patient_agent();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::patient_agent *ui;
    class_patient temppatient;
};

#endif // PATIENT_AGENT_H
