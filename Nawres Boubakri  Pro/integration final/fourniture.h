#ifndef FOURNITURE_H
#define FOURNITURE_H
#include"fournitures.h"
#include <QTableView>

#include <QDialog>
#include "smtp.h"
#include <QtWidgets/QMessageBox>


namespace Ui {
class fourniture;
}
class  QSystemTrayIcon ;
class fourniture : public QDialog
{
    Q_OBJECT

public:
    explicit fourniture(QWidget *parent = nullptr);
    ~fourniture();

private slots:
  //  void on_save_clicked();

    void on_pushButton_5_clicked();

    void on_e2_customContextMenuRequested(const QPoint &pos);

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_label_linkActivated(const QString &link);

    void on_Delete_clicked();

    void on_pushButton_7_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_6_clicked();

    void on_pa_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_2_activated(const QString &arg1);

    void on_pushButton_clicked();

    void on_retour_clicked();

    void on_retour_2_clicked();

    void on_pushButton_3_clicked();

    void on_taba_windowIconChanged(const QIcon &icon);

private slots:
    void sendMail();
    void mailSent(QString);

    void on_sendBtn_2_clicked();

    void on_ajouter_clicked();


private:
    Ui::fourniture *ui;
    fournitures tmpfourn ;
    QSystemTrayIcon *mySystemTrayIcon ;
};

#endif // FOURNITURE_H
