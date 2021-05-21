#ifndef MONTH_HPP
#define MONTH_HPP

class Parameters;

class Month
{
    public:
        explicit Month(Parameters* params, Month* monthBefore, double gross);

        double gross() const;
        double grossCumulative() const;
        double pensionContribution() const;

        void recalculate();
    private:
        Parameters* m_params;
        Month* m_monthBefore;
        double m_gross;
        double m_grossCumulative;
        double m_pensionContribution;
};

#endif // MONTH_HPP
