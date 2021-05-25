#include "month.hpp"
#include "datamodel.hpp"

Month::Month(IInputData* params, Month *monthBefore, double gross):
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

double Month::disabilityContribution() const
{
    return m_disabilityContribution;
}

double Month::accidentContribution() const
{
    return m_accidentContribution;
}

double Month::sicknessContribution() const
{
    return m_sicknessContribution;
}

double Month::healthCareContribution() const
{
    return m_healthCareContribution;
}

double Month::taxBase() const
{
    return m_taxBase;
}

double Month::tax() const
{
    return m_tax;
}

void Month::recalculate()
{
    if (m_grossCumulative < m_params->insuranceLimit()) {
        m_pensionContribution = m_gross * m_params->pensionEmployee() / 100;
        m_disabilityContribution = m_gross * m_params->disabilityPensionEmployee() / 100;
    } else {
        m_pensionContribution = std::max(((m_params->insuranceLimit() - m_grossCumulative) + m_gross) * m_params->pensionEmployee() / 100, 0.);
        m_disabilityContribution = std::max(((m_params->insuranceLimit() - m_grossCumulative) + m_gross) * m_params->disabilityPensionEmployee() / 100, 0.);
    }

    m_accidentContribution = m_gross * m_params->accidentEmployee() / 100;
    m_sicknessContribution = m_gross * m_params->sicknessEmployee() / 100;

    m_healthCareContribution = (m_gross - (m_pensionContribution + m_disabilityContribution + m_sicknessContribution + m_accidentContribution)) * m_params->healthCareEmployee() / 100;

    m_taxBase = m_gross - (m_pensionContribution + m_disabilityContribution + m_sicknessContribution) - m_params->taxDeductibleCost() / 12;

    m_tax = // work in progress
}
