#include "degressivetaxfreeamount.hpp"
#include "ui_degressivetaxfreeamount.h"

//#include <QtGlobal>

DegressiveTaxFreeAmount::DegressiveTaxFreeAmount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DegressiveTaxFreeAmount)
{
    ui->setupUi(this);
    connect(ui->end1, QOverload<int>::of(&QSpinBox::valueChanged), ui->begin2, &QSpinBox::setValue);
}

DegressiveTaxFreeAmount::~DegressiveTaxFreeAmount()
{
    delete ui;
}

double DegressiveTaxFreeAmount::monthlyTaxFreeAmount(double taxBase) const
{

}

double DegressiveTaxFreeAmount::yearlyTaxFreeAmount(double taxBase) const
{

}
