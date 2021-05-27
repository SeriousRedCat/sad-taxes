#include "yearwidget.hpp"
#include "ui_yearwidget.h"

#include "degressivetaxfreeamount.hpp"

YearWidget::YearWidget(Year year, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::YearWidget),
    m_model(new DataModel(this, 14500)),
    m_taxFreeAmount(nullptr)
{
    ui->setupUi(this);

    switch (year) {
        case Year::Year2020: m_taxFreeAmount = new DegressiveTaxFreeAmount; break;
        default: break;
    }

    QGridLayout* grid = new QGridLayout;
    grid->addWidget(dynamic_cast<QWidget*>(m_taxFreeAmount));
    ui->taxFreeGroupBox->setLayout(grid);

    ui->dataView->setModel(m_model);
    m_model->recalculate();

    connect(ui->contribLimit, QOverload<int>::of(&QSpinBox::valueChanged), m_model, &DataModel::recalculate);
    connect(ui->pensionContribEmployee, QOverload<double>::of(&QDoubleSpinBox::valueChanged), m_model, &DataModel::recalculate);
    connect(ui->disabilityPensionContribEmployee, QOverload<double>::of(&QDoubleSpinBox::valueChanged), m_model, &DataModel::recalculate);
    connect(ui->accidentContribEmployee, QOverload<double>::of(&QDoubleSpinBox::valueChanged), m_model, &DataModel::recalculate);
    connect(ui->sicknessContribEmployee, QOverload<double>::of(&QDoubleSpinBox::valueChanged), m_model, &DataModel::recalculate);
    connect(ui->healthCareContribEmployee, QOverload<double>::of(&QDoubleSpinBox::valueChanged), m_model, &DataModel::recalculate);
    connect(ui->healthCareTaxFreeContribEmployee, QOverload<double>::of(&QDoubleSpinBox::valueChanged), m_model, &DataModel::recalculate);
    connect(ui->taxDeductibleCostLimit, QOverload<int>::of(&QSpinBox::valueChanged), m_model, &DataModel::recalculate);
}

YearWidget::~YearWidget()
{
    delete ui;
}

double YearWidget::insuranceLimit() const
{
    return ui->contribLimit->value();
}

double YearWidget::pensionEmployee() const
{
    return ui->pensionContribEmployee->value();
}

double YearWidget::disabilityPensionEmployee() const
{
    return ui->disabilityPensionContribEmployee->value();
}

double YearWidget::accidentEmployee() const
{
    return ui->accidentContribEmployee->value();
}

double YearWidget::sicknessEmployee() const
{
    return ui->sicknessContribEmployee->value();
}

double YearWidget::healthCareEmployee() const
{
    return ui->healthCareContribEmployee->value();
}

double YearWidget::taxDeductibleCost() const
{
    return ui->taxDeductibleCostLimit->value();
}

double YearWidget::taxThreshold() const
{
    return ui->taxThreshold->value();
}

double YearWidget::tax1() const
{
    return ui->tax1->value();
}

double YearWidget::tax2() const
{
    return ui->tax2->value();
}

double YearWidget::healthCareTaxFreeEmployee() const
{
    return ui->healthCareTaxFreeContribEmployee->value();
}

double YearWidget::taxFreeAmount(double cumulativeTaxBase) const
{
    return m_taxFreeAmount->monthlyTaxFreeAmount(cumulativeTaxBase);
}
