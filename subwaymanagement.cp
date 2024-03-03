#include "subwaymanagement.h"
#include "ui_subwaymanagement.h"

SubwayManagement::SubwayManagement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SubwayManagement)
{
    ui->setupUi(this);
}

SubwayManagement::~SubwayManagement()
{
    delete ui;
}

void SubwayManagement::on_pushButton_clicked()
{
    QString startStation = ui->StartlineEdit->text();
    QString endStation = ui->EndlineEdit_2->text();


}

