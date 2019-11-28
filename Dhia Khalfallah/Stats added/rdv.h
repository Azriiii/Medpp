#ifndef RDV_H
#define RDV_H

#include <QDialog>

namespace Ui {
class RDV;
}

class RDV : public QDialog
{
    Q_OBJECT

public:
    explicit RDV(QWidget *parent = nullptr);
    ~RDV();

private:
    Ui::RDV *ui;
};

#endif // RDV_H
