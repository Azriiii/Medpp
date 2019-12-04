#ifndef FOURNITURE_H
#define FOURNITURE_H

#include <QDialog>

namespace Ui {
class fourniture;
}

class fourniture : public QDialog
{
    Q_OBJECT

public:
    explicit fourniture(QWidget *parent = nullptr);
    ~fourniture();

private:
    Ui::fourniture *ui;
};

#endif // FOURNITURE_H
