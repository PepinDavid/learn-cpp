#ifndef DEF_FRACTION
#define DEF_FRACTION

#include <string>
#include <iostream>
class Fraction
{
    private:
    int m_numerator;
    int m_denominator;
    void reduce();
    void reverse();
    void format();
    int PGDC();
    
    public:
    Fraction(int num = 0, int denum = 1);
    void affiche(std::ostream & flux) const;
    int getNumerator() const;
    int getDenominator() const;
    double nombreReel();
    Fraction addition(Fraction const & b);
    Fraction soustraction(Fraction const & b);
    Fraction operator==(Fraction const & b) const;
    Fraction operator+(Fraction const & b);
    Fraction operator-(Fraction const & b);
    Fraction operator*(Fraction const & b);
    Fraction operator/(Fraction const & b);
    Fraction& operator+=(Fraction const & b);
    Fraction& operator-=(Fraction const & b);
};

#endif