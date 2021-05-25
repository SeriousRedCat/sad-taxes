#ifndef DATAMODEL_HPP
#define DATAMODEL_HPP

#include <QAbstractTableModel>

class Month;

struct Parameters {
    struct {
        double pensionContribEmployee;
        double disabilityPensionContribEmployee;
        double accidentContribEmployee;
        double sicknessContribEmployee;
        double healthCareContribEmployee;
        double limit;
    } insuranceContribs;
};

class IInputData {
    public:
        virtual double insuranceLimit() const = 0;
        virtual double pensionEmployee() const = 0;
        virtual double disabilityPensionEmployee() const = 0;
        virtual double accidentEmployee() const = 0;
        virtual double sicknessEmployee() const = 0;
        virtual double healthCareEmployee() const = 0;
        virtual double healthCareTaxFreeEmployee() const = 0;
        virtual double taxDeductibleCost() const = 0;
        virtual double taxThreshold() const = 0;
        virtual double tax1() const = 0;
        virtual double tax2() const = 0;
};

class DataModel : public QAbstractTableModel
{
    public:
        DataModel(IInputData* params, double gross);

        void recalculate();

        // QAbstractItemModel interface
    public:
        int rowCount(const QModelIndex &parent) const;
        int columnCount(const QModelIndex &parent) const;
        QVariant data(const QModelIndex &index, int role) const;
        QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    protected:
        QVector<Month*> m_months;
};

#endif // DATAMODEL_HPP
