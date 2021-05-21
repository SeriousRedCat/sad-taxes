#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include "employment_contract/datamodel.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_params = new Parameters;
    m_params->insuranceContribs.pensionContribEmployee = ui->pensionContribEmployee->value();
    m_params->insuranceContribs.limit = ui->contribLimit->value();

    m_model = new DataModel(m_params, 14500);
    ui->dataView->setModel(m_model);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pensionContribEmployee_valueChanged(double arg1)
{
    m_params->insuranceContribs.pensionContribEmployee = arg1;
    m_model->recalculate();
}

void MainWindow::on_contribLimit_valueChanged(int arg1)
{
    m_params->insuranceContribs.limit = arg1;
    m_model->recalculate();
}
