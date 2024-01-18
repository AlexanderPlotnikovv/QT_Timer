#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTime>
#include <QTimer>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void change_start_stop_button();
    void update_time();
    void add_circle();

private:
    Ui::MainWindow *ui;
    QTime* GeneralTime;
    QTimer* ForWait;
    int previous_time = 0;
    int general_time;
    int time = 0;
    int circle_num = 1;
};
#endif // MAINWINDOW_H
