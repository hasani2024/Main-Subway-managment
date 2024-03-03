#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "subwaymanagement.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_SubwayButton_clicked()
{
    SubwayManagement* subwayPage = new SubwayManagement();
    subwayPage->show();
}

