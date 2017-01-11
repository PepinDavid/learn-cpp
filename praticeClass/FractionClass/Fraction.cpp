#include "Fraction.h"

using namespace std;

Fraction::Fraction(int num, int denum) : m_numerator(num), m_denominator(denum)
{
    this->format();
}

int Fraction::PGDC()
{
    int tempD(m_denominator), tempN(m_numerator), result(1);
    while(tempD != 0)
    {
        result = tempD;
        tempD = tempN % tempD;
        tempN = result;
    }
    return result;
}

void Fraction::reduce()
{
    int r = this->PGDC();
    m_numerator /= r;
    m_denominator /= r;
}

void Fraction::reverse()
{
    if(m_denominator < 0)
    {
        m_numerator = -m_numerator;
        m_denominator = -m_denominator;
    }
}

void Fraction::format()
{
    this->reverse();
    this->reduce();
}

void Fraction::affiche(ostream & flux) const
{
    flux << m_numerator << "/" << m_denominator;
}

int Fraction::getNumerator() const
{
    return m_numerator;
}

int Fraction::getDenominator() const
{
    return m_denominator;
}

double Fraction::nombreReel()
{
    return double(m_numerator / (double)m_denominator);//pour retourné deux int en double il faut casté explicitement l'un des int
}

Fraction Fraction::addition(Fraction const & b)
{
    int a_num,a_denum;
    a_num = m_numerator * b.m_denominator + b.m_numerator * m_denominator; //lorsqu'une fonction utilise deux Objets de meme Class
    //on peut accéder aux variables/fonctions membres/privées de l'Objet passé en arguments
    a_denum = m_denominator * b.m_denominator;
    return Fraction(a_num, a_denum);
}

Fraction Fraction::soustraction(Fraction const & b)
{
    int a_num,a_denum;
    a_num = m_numerator * b.m_denominator - b.m_numerator * m_denominator;
    a_denum = m_denominator * b.m_denominator;
    return Fraction(a_num, a_denum);
}

Fraction Fraction::operator+(Fraction const & b)
{
    Fraction result;
    result = this->addition(b);
    return result;
}

Fraction Fraction::operator-(Fraction const & b)
{
    Fraction result;
    result = this->soustraction(b);
    return result;
}

Fraction Fraction::operator*(Fraction const & b)
{
    Fraction result(m_numerator * b.m_numerator, m_denominator * b.m_denominator);
    return result;
}

Fraction Fraction::operator/(Fraction const & b)
{
    Fraction result(m_numerator * b.m_denominator, m_denominator * b.m_numerator);
    return result;
}

Fraction& Fraction::operator +=(Fraction const & b) //retourne l'objet Fraction& par reference
{
    m_numerator = m_numerator * b.m_denominator + b.m_numerator * m_denominator;
    m_denominator *= b.m_denominator;
    return *this ; //retourne le pointeur de l'objet Fraction& par reference
}

Fraction& Fraction::operator -=(Fraction const & b)
{
    m_numerator = m_numerator * b.m_denominator - b.m_numerator * m_denominator;
    m_denominator *= b.m_denominator;
    return *this ;
}
