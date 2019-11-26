#ifndef EQUIPEMENTMED_H
#define EQUIPEMENTMED_H

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

private:
    Ui::equipementmed *ui;
};

#endif // EQUIPEMENTMED_H
