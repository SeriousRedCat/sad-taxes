#ifndef YEARWIDGET_HPP
#define YEARWIDGET_HPP

#include <QWidget>
#include "datamodel.hpp"

namespace Ui {
class YearWidget;
}

enum class Year {
    Year2020,
    Year2021
};

class ITaxFreeAmount;

class YearWidget : public QWidget, public IInputData
{
        Q_OBJECT

    public:
        explicit YearWidget(Year year, QWidget *parent = nullptr);
        ~YearWidget();

    private:
        Ui::YearWidget *ui;
        DataModel* m_model;
        ITaxFreeAmount* m_taxFreeAmount;

        // IInputData interface
    public:
        double insuranceLimit() const;
        double pensionEmployee() const;
        double disabilityPensionEmployee() const;
        double accidentEmployee() const;
        double sicknessEmployee() const;
        double healthCareEmployee() const;
        double taxDeductibleCost() const;
        double taxThreshold() const;
        double tax1() const;
        double tax2() const;
        double healthCareTaxFreeEmployee() const;
        double taxFreeAmount(double cumulativeTaxBase) const;

        QPair<QVector<double>, QVector<double> > net() const;
};

#endif // YEARWIDGET_HPP
