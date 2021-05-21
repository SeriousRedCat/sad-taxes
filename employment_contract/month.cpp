#include "month.hpp"
#include "datamodel.hpp"

Month::Month(Parameters* params, Month *monthBefore, double gross):
    m_params(params),
    m_monthBefore(monthBefore),
    m_gross(gross),
    m_grossCumulative(monthBefore ? monthBefore->grossCumulative() + gross : gross)
{

}

double Month::gross() const
{
    return m_gross;
}

double Month::grossCumulative() const
{
    return m_grossCumulative;
}

double Month::pensionContribution() const
{
    return m_pensionContribution;
}

void Month::recalculate()
{
    if (m_grossCumulative < m_params->insuranceContribs.limit) {
        m_pensionContribution = m_gross * m_params->insuranceContribs.pensionContribEmployee / 100;
    } else {
        m_pensionContribution = std::max(((m_params->insuranceContribs.limit - m_grossCumulative) + m_gross) * m_params->insuranceContribs.pensionContribEmployee / 100, 0.);
    }

}
