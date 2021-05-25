#ifndef ITAXFREEAMOUNT_HPP
#define ITAXFREEAMOUNT_HPP

class ITaxFreeAmount {
        virtual double monthlyTaxFreeAmount(double taxBase) const = 0;
        virtual double yearlyTaxFreeAmount(double taxBase) const = 0;
};

#endif // ITAXFREEAMOUNT_HPP
