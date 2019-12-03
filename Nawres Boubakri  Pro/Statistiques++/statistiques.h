#ifndef STATISTIQUES_H
#define STATISTIQUES_H
#include <QDialog>
#include "qcustomplot.h"
#include <QDialog>

namespace Ui {
class Statistiques;
}

class Statistiques : public QDialog
{
    Q_OBJECT

public:
    explicit Statistiques(QWidget *parent = nullptr);
    ~Statistiques();
     void makePolt();

private:
    Ui::Statistiques *ui;
};

#endif // STATISTIQUES_H
