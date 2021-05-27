#include "datamodel.hpp"
#include "month.hpp"

DataModel::DataModel(const IInputData *params, double gross):
    m_params(params)
{
    for(int i = 0; i < 12; ++i) {
        auto month = new Month(params, i > 0 ? m_months[i-1] : nullptr, gross);
        m_months.append(month);
//        month->recalculate();
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
    return m_months.size() + 1;
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
            if (index.row() < 12) {
                auto month = m_months[index.row()];
                switch (index.column()) {
                    case 0: return month->gross();
                    case 1: return month->pensionContribution();
                    case 2: return month->disabilityContribution();
                    case 3: return month->accidentContribution();
                    case 4: return month->sicknessContribution();
                    case 5: return month->healthCareContribution();
                    case 6: return month->taxBase();
                    case 7: return month->tax();
                    case 8: return month->net();
                    default: return QVariant();
                }
            } else {
                switch (index.column()) {
                    case 0: return std::accumulate(m_months.begin(), m_months.end(), 0.,
                                                   [](double acc, Month* el){return acc + el->gross();});
                    case 1: return std::accumulate(m_months.begin(), m_months.end(), 0.,
                                                   [](double acc, Month* el){return acc + el->pensionContribution();});
                    case 2: return std::accumulate(m_months.begin(), m_months.end(), 0.,
                                                   [](double acc, Month* el){return acc + el->disabilityContribution();});
                    case 3: return std::accumulate(m_months.begin(), m_months.end(), 0.,
                                                   [](double acc, Month* el){return acc + el->accidentContribution();});
                    case 4: return std::accumulate(m_months.begin(), m_months.end(), 0.,
                                                   [](double acc, Month* el){return acc + el->sicknessContribution();});
                    case 5: return std::accumulate(m_months.begin(), m_months.end(), 0.,
                                                   [](double acc, Month* el){return acc + el->healthCareContribution();});
                    case 6: return std::accumulate(m_months.begin(), m_months.end(), 0.,
                                                   [](double acc, Month* el){return acc + el->taxBase();});
                    case 7: return std::accumulate(m_months.begin(), m_months.end(), 0.,
                                                   [](double acc, Month* el){return acc + el->tax();});
                    case 8: return std::accumulate(m_months.begin(), m_months.end(), 0.,
                                                   [](double acc, Month* el){return acc + el->net();});
                    default: return QVariant();
                }
            }

        }
        default:
            return QVariant();
    }
}

QVariant DataModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole) {
        switch (orientation) {
            case Qt::Vertical: {
                switch (section) {
                    case 0: return tr("January");
                    case 1: return tr("February");
                    case 2: return tr("March");
                    case 3: return tr("April");
                    case 4: return tr("May");
                    case 5: return tr("June");
                    case 6: return tr("July");
                    case 7: return tr("August");
                    case 8: return tr("September");
                    case 9: return tr("October");
                    case 10: return tr("November");
                    case 11: return tr("December");
                    default: return QVariant();
                }
            }
            case Qt::Horizontal: {
                switch (section) {
                    case 0: return tr("Gross");
                    case 1: return tr("Pension");
                    case 2: return tr("Disability");
                    case 3: return tr("Accident");
                    case 4: return tr("Sickness");
                    case 5: return tr("Health");
                    case 6: return tr("Tax base");
                    case 7: return tr("Tax");
                    case 8: return tr("Net");

                    default: return QVariant();
                }
            }
        }
    }
    return QAbstractTableModel::headerData(section, orientation, role);
}

double DataModel::yearlyNetSalary() const
{
    double gross = std::accumulate(m_months.begin(), m_months.end(), 0.,
                                                       [](double acc, Month* el){return acc + el->gross();});

    double dochod = gross - m_params->taxDeductibleCost();

    double tax_taken = std::accumulate(m_months.begin(), m_months.end(), 0.,
                                      [](double acc, Month* el){return acc + el->tax();});

    double contribs = std::accumulate(m_months.begin(), m_months.end(), 0.,
                                                                         [](double acc, Month* el){return acc + el->pensionContribution();})
                                          +std::accumulate(m_months.begin(), m_months.end(), 0.,
                                                                         [](double acc, Month* el){return acc + el->disabilityContribution();})
                                          +std::accumulate(m_months.begin(), m_months.end(), 0.,
                                                                         [](double acc, Month* el){return acc + el->accidentContribution();})
                                          +std::accumulate(m_months.begin(), m_months.end(), 0.,
                                                                         [](double acc, Month* el){return acc + el->sicknessContribution();});

    double podstawa = dochod - contribs;

    double _1 = std::min(m_params->taxThreshold(), podstawa);
    double _2 = podstawa - _1;
    double tax = _1 * m_params->tax1()/100 + _2 * m_params->tax2()/100 - std::accumulate(m_months.begin(), m_months.end(), 0.,
[](double acc, Month* el){return acc + el->healthCareContribution();}) * m_params->healthCareTaxFreeEmployee()/m_params->healthCareEmployee();

    double net = std::accumulate(m_months.begin(), m_months.end(), 0.,
                                                       [](double acc, Month* el){return acc + el->net();});

    return net + (tax_taken - tax);
}
