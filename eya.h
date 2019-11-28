#ifndef EYA_H
#define EYA_H

#include <QDialog>

namespace Ui {
class eya;
}

class eya : public QDialog
{
    Q_OBJECT

public:
    explicit eya(QWidget *parent = nullptr);
    ~eya();

private:
    Ui::eya *ui;
};

#endif // EYA_H
