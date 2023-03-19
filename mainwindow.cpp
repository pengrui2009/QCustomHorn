#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
