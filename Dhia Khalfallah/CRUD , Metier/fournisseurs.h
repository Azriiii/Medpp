#ifndef FOURNISSEURS_H
#define FOURNISSEURS_H

#include <QDialog>

namespace Ui {
class fournisseurs;
}

class fournisseurs : public QDialog
{
    Q_OBJECT

public:
    explicit fournisseurs(QWidget *parent = nullptr);
    ~fournisseurs();

private:
    Ui::fournisseurs *ui;
};

#endif // FOURNISSEURS_H
