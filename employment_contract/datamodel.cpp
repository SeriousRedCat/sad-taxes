#include "datamodel.hpp"
#include "month.hpp"

DataModel::DataModel(Parameters *params, double gross)
{
    for(int i = 0; i < 12; ++i) {
        auto month = new Month(params, i > 0 ? m_months[i-1] : nullptr, gross);
        m_months.append(month);
        month->recalculate();
    }
}

void DataModel::recalculate()
{
    for (auto month: m_months) {
        month->recalculate();
    }

    emit endResetModel();
}

int DataModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_months.size();
}


int DataModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 16;
}

QVariant DataModel::data(const QModelIndex &index, int role) const
{
    switch(role) {
        case Qt::DisplayRole: {
            auto month = m_months[index.row()];
            switch (index.column()) {
                case 0: return month->gross();
                case 1: return month->pensionContribution();
                default: return QVariant();
            }
        }
        default:
            return QVariant();
    }
}
