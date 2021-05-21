#ifndef DATAMODEL_HPP
#define DATAMODEL_HPP

#include <QAbstractTableModel>

class Month;

struct Parameters {
    struct {
        double pensionContribEmployee;
        double limit;
    } insuranceContribs;
};

class DataModel : public QAbstractTableModel
{
    public:
        DataModel(Parameters* params, double gross);

        void recalculate();

        // QAbstractItemModel interface
    public:
        int rowCount(const QModelIndex &parent) const;
        int columnCount(const QModelIndex &parent) const;
        QVariant data(const QModelIndex &index, int role) const;

    protected:
        QVector<Month*> m_months;
};

#endif // DATAMODEL_HPP
