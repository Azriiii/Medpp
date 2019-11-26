#ifndef SECRETAIRE_H
#define SECRETAIRE_H

#include <QDialog>

namespace Ui {
class secretaire;
}

class secretaire : public QDialog
{
    Q_OBJECT

public:
    explicit secretaire(QWidget *parent = nullptr);
    ~secretaire();

private slots:
    void on_signout_clicked();

private:
    Ui::secretaire *ui;
};

#endif // SECRETAIRE_H
