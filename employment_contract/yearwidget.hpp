#ifndef YEARWIDGET_HPP
#define YEARWIDGET_HPP

#include <QWidget>
#include "datamodel.hpp"

namespace Ui {
class YearWidget;
}

class YearWidget : public QWidget, public IInputData
{
        Q_OBJECT

    public:
        explicit YearWidget(QWidget *parent = nullptr);
        ~YearWidget();

    private:
        Ui::YearWidget *ui;
        DataModel* m_model;

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
};

#endif // YEARWIDGET_HPP
