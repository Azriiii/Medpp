#ifndef FACTURES_H
#define FACTURES_H

#include <QDialog>

namespace Ui {
class factures;
}

class factures : public QDialog
{
    Q_OBJECT

public:
    explicit factures(QWidget *parent = nullptr);
    ~factures();

private:
    Ui::factures *ui;
};

#endif // FACTURES_H
