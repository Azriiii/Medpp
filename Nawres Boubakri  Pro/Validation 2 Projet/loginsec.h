#ifndef LOGINSEC_H
#define LOGINSEC_H

#include <QDialog>
#include "secretaire.h"
namespace Ui {
class loginSec;
}

class loginSec : public QDialog
{
    Q_OBJECT

public:
    explicit loginSec(QWidget *parent = nullptr);
    ~loginSec();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::loginSec *ui;
    secretaire *sec ;
};

#endif // LOGINSEC_H
