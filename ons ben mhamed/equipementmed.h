#ifndef EQUIPEMENTMED_H
#define EQUIPEMENTMED_H
#include"equipement.h"
#include<QSystemTrayIcon>
#include <QDialog>

namespace Ui {
class equipementmed;
}

class equipementmed : public QDialog
{
    Q_OBJECT

public:
    explicit equipementmed(QWidget *parent = nullptr);
    ~equipementmed();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_retour_2_clicked();

    void on_retour_clicked();

    void on_save_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_Delete_clicked();

    void on_pushButton_7_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_6_clicked();

    void on_pa_clicked();

private:
    Ui::equipementmed *ui;
    equipement tmpequip ;
    QSystemTrayIcon *mySystemTrayIcon ;
};

#endif // EQUIPEMENTMED_H
