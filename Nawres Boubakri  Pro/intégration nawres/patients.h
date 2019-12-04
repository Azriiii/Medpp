#ifndef PATIENTS_H
#define PATIENTS_H

#include <QDialog>

namespace Ui {
class patients;
}

class patients : public QDialog
{
    Q_OBJECT

public:
    explicit patients(QWidget *parent = nullptr);
    ~patients();

private:
    Ui::patients *ui;
};

#endif // PATIENTS_H
