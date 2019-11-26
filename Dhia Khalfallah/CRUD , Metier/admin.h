#ifndef ADMIN_H
#define ADMIN_H
#include "personelsmed.h"
#include "equipementmed.h"
#include "fourniture.h"
#include "fournisseurs.h"
#include "stafftechnique.h"

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

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::admin *ui;
    PersonelsMed *personelM ;
    equipementmed *equip ;
    fourniture *four ;
    fournisseurs *fourn ;
    stafftechnique *staff ;
};

#endif // ADMIN_H
