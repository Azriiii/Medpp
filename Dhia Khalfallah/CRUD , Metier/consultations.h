#ifndef CONSULTATIONS_H
#define CONSULTATIONS_H

#include <QDialog>

namespace Ui {
class Consultations;
}

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

private:
    Ui::Consultations *ui;
};

#endif // CONSULTATIONS_H
