#ifndef STATPATIENT_H
#define STATPATIENT_H

#include <QMainWindow>

namespace Ui {
class statpatient;
}

class statpatient : public QMainWindow
{
    Q_OBJECT

public:
    explicit statpatient(QWidget *parent = nullptr);
    ~statpatient();

private:
    Ui::statpatient *ui;
};

#endif // STATPATIENT_H
