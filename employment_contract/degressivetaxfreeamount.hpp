#ifndef DEGRESSIVETAXFREEAMOUNT_HPP
#define DEGRESSIVETAXFREEAMOUNT_HPP

#include <QWidget>

#include "itaxfreeamount.hpp"

namespace Ui {
class DegressiveTaxFreeAmount;
}

class DegressiveTaxFreeAmount : public QWidget, public ITaxFreeAmount
{
        Q_OBJECT

    public:
        explicit DegressiveTaxFreeAmount(QWidget *parent = nullptr);
        ~DegressiveTaxFreeAmount();

        double monthlyTaxFreeAmount(double taxBase) const override;
        double yearlyTaxFreeAmount(double taxBase) const override;

    private:
        Ui::DegressiveTaxFreeAmount *ui;
};

#endif // DEGRESSIVETAXFREEAMOUNT_HPP
