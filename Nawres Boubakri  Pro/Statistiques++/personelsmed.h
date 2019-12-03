#ifndef PERSONELSMED_H
#define PERSONELSMED_H
#include <QDialog>
#include "personelsm.h"

namespace Ui {
class PersonelsMed;
}

class PersonelsMed : public QDialog
{
    Q_OBJECT

public:
    explicit PersonelsMed(QWidget *parent = nullptr);
    ~PersonelsMed();

private slots:
    void on_save_clicked();

    void on_retour_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_Delete_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::PersonelsMed *ui;
    PersonelsM tmppers ;
};

#endif // PERSONELSMED_H
