#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->cbx_direction->addItem("朝左", QVariant("LEFT"));
    ui->cbx_direction->addItem("朝右", QVariant("RIGHT"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_cbx_horn_state_stateChanged(int arg1)
{
    bool state = false;

    state = arg1 ? true : false;

    ui->widget->setHornState(state);
}

void MainWindow::on_cbx_direction_currentIndexChanged(const QString &arg1)
{
    QString str = ui->cbx_direction->currentData().toString();
    if (str == "LEFT")
    {
        ui->widget->setHornDir(QCustomHorn::HORNDIR_LEFT);
    } else {
        ui->widget->setHornDir(QCustomHorn::HORNDIR_RIGHT);
    }

}
