#ifndef ORDONANCES_H
#define ORDONANCES_H

#include <QDialog>

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

private:
    Ui::Ordonances *ui;
};

#endif // ORDONANCES_H
