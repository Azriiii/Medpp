#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"
#include "loginmed.h"
#include "loginsec.h"
#include<QMediaPlayer>
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

    void on_slidervolume_actionTriggered(int action);
    void on_durationChanged(qint64  position);
    void on_positionChanged(qint64  position);

    void on_slidervolume_sliderMoved(int position);

    void on_sliderprogress_sliderMoved(int position);

    void on_strart_Button_clicked();

    void on_stop_button_clicked();

private:
    Ui::MainWindow *ui;
     QMediaPlayer*player;

};
#endif // MAINWINDOW_H
