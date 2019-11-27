#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"
#include "loginmed.h"
#include "loginsec.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ad_clicked();

    void on_med_clicked();

    void on_sec_clicked();

private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
