#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include "employment_contract/yearwidget.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->yearlyTabs->addTab(new YearWidget(this), "test");
}

MainWindow::~MainWindow()
{
    delete ui;
}
