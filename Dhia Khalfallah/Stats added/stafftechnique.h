#ifndef STAFFTECHNIQUE_H
#define STAFFTECHNIQUE_H

#include <QDialog>
#include <stafft.h>
namespace Ui {
class stafftechnique;
}
class  QSystemTrayIcon ;

class stafftechnique : public QDialog
{
    Q_OBJECT

public:
    explicit stafftechnique(QWidget *parent = nullptr);
    ~stafftechnique();
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
    Ui::stafftechnique *ui;
    stafft tmppers ;
    QSystemTrayIcon *mySystemTrayIcon ;
};

#endif // STAFFTECHNIQUE_H
