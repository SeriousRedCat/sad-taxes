#include "degressivetaxfreeamount.hpp"
#include "ui_degressivetaxfreeamount.h"

//#include <QtGlobal>

DegressiveTaxFreeAmount::DegressiveTaxFreeAmount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DegressiveTaxFreeAmount)
{
    ui->setupUi(this);
    connect(ui->end1, QOverload<int>::of(&QSpinBox::valueChanged), ui->begin2, &QSpinBox::setValue);
    connect(ui->end2, QOverload<int>::of(&QSpinBox::valueChanged), ui->begin3, &QSpinBox::setValue);
    connect(ui->end3, QOverload<int>::of(&QSpinBox::valueChanged), ui->begin4, &QSpinBox::setValue);
//    connect(ui->end1, QOverload<int>::of(&QSpinBox::valueChanged), ui->begin2, &QSpinBox::setValue);
}

DegressiveTaxFreeAmount::~DegressiveTaxFreeAmount()
{
    delete ui;
}

double DegressiveTaxFreeAmount::monthlyTaxFreeAmount(double taxBase) const
{
    if (taxBase < ui->end3->value()) {
        return ui->value3->value() / 12;
    } else {
        return 0;
    }
}

double DegressiveTaxFreeAmount::yearlyTaxFreeAmount(double taxBase) const
{   
    return 0;
}
