#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include "employment_contract/yearwidget.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto year = new YearWidget(Year::Year2020, this);
    auto net = year->net();
    ui->yearlyTabs->addTab(year, "test");

    ui->graph->addGraph();
    ui->graph->graph(0)->addData(net.first, net.second);
    ui->graph->xAxis->setRange(2000, 15000);
    ui->graph->yAxis->setRange(net.second.first(), net.second.last());
    ui->graph->replot();
}

MainWindow::~MainWindow()
{
    delete ui;
}
