#ifndef MONTH_HPP
#define MONTH_HPP

class IInputData;

class Month
{
    public:
        explicit Month(IInputData* params, Month* monthBefore, double gross);

        double gross() const;
        double grossCumulative() const;
        double pensionContribution() const;
        double disabilityContribution() const;
        double accidentContribution() const;
        double sicknessContribution() const;
        double healthCareContribution() const;
        double taxBase() const;
        double taxBaseCumulative() const;
        double tax() const;
        double net() const;

        void recalculate();
    private:
        IInputData* m_params;
        Month* m_monthBefore;
        double m_gross;
        double m_grossCumulative;
        double m_pensionContribution;
        double m_disabilityContribution;
        double m_accidentContribution;
        double m_sicknessContribution;
        double m_healthCareContribution;
        double m_taxBase;
        double m_taxBaseCumulative;
        double m_tax;
        double m_net;
};

#endif // MONTH_HPP
