#ifndef LOGINMED_H
#define LOGINMED_H

#include <QDialog>
#include "medecin.h"
namespace Ui {
class loginMed;
}

class loginMed : public QDialog
{
    Q_OBJECT

public:
    explicit loginMed(QWidget *parent = nullptr);
    ~loginMed();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::loginMed *ui;
    Medecin *medecin ;
};

#endif // LOGINMED_H
