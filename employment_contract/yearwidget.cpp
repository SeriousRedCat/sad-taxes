#include "yearwidget.hpp"
#include "ui_yearwidget.h"

YearWidget::YearWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::YearWidget),
    m_model(new DataModel(this, 14500))
{
    ui->setupUi(this);

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
