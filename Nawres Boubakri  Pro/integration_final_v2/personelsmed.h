#ifndef PERSONELSMED_H
#define PERSONELSMED_H
#include <QDialog>
#include "personelsm.h"

namespace Ui {
class PersonelsMed;
}

class  QSystemTrayIcon ;

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

    void on_retour_2_clicked();

    void on_pushButton_4_clicked();



    void on_pushButton_5_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_6_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_7_clicked();


    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::PersonelsMed *ui;
    PersonelsM tmppers ;
    QSystemTrayIcon *mySystemTrayIcon ;
};

#endif // PERSONELSMED_H
