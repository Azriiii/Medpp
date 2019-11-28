#ifndef ADMIN_H
#define ADMIN_H
#include "personelsmed.h"

#include <QDialog>

namespace Ui {
class admin;
}

class admin : public QDialog
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = nullptr);
    ~admin();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

private:
    Ui::admin *ui;
    PersonelsMed *personelM ;
};

#endif // ADMIN_H
