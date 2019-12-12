#ifndef RDV_H
#define RDV_H
#include"class_rdv.h"
#include <QDialog>

namespace Ui {
class RDV;
}
class QSystemTrayIcon;

class RDV : public QDialog
{
    Q_OBJECT

public:
    explicit RDV(QWidget *parent = nullptr);
    ~RDV();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_10_clicked();

    void on_tablerdv_2_clicked();

    void on_rechercher_clicked();

    void on_pushButton_9_clicked();

    void on_ajouter_clicked();

private:
    Ui::RDV *ui;
      class_rdv temprdv;
      QSystemTrayIcon * mysysteme;

};

#endif // RDV_H
