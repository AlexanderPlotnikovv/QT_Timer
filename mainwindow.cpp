#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ForWait = new QTimer(this);
    GeneralTime = new QTime(0,0,0,0);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::change_start_stop_button);
    connect(ForWait, SIGNAL(timeout()), this, SLOT(update_time()));
    ForWait->start(1);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::add_circle);
}

void MainWindow::change_start_stop_button()
{
    if (ui->pushButton->text() == "Start")
    {
        ui->pushButton->setText("Stop");
    }
    else
    {
        ui->pushButton->setText("Start");
    }
}

void MainWindow::update_time()
{
    if (ui->pushButton->text() == "Stop")
    {
        QString s = QString::fromStdString(std::to_string(time));
        ui->label_3->setText(s + "ms");
        ++time;
    }
    else
    {
        ui->label_3->setText("0ms");
        ui->listWidget->clear();
        time = 0;
        previous_time = 0;
        circle_num = 1;
    }
}

void MainWindow::add_circle()
{
    ui->listWidget->addItem("Circle " + QString::fromStdString(std::to_string(circle_num)) +
    ": " + QString::fromStdString(std::to_string(time-previous_time)) + "ms");
    previous_time = time;
    circle_num++;
}

MainWindow::~MainWindow()
{
    delete ui;
}
