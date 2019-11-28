#ifndef RDV_AGENT_H
#define RDV_AGENT_H

#include <QDialog>
#include"class_rdv.h"
namespace Ui {
class rdv_agent;
}

class rdv_agent : public QDialog
{
    Q_OBJECT

public:
    explicit rdv_agent(QWidget *parent = nullptr);
    ~rdv_agent();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::rdv_agent *ui;
    class_rdv temprdv;
};

#endif // RDV_AGENT_H
