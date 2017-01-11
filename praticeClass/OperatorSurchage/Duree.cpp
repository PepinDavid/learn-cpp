#include "Duree.h"

using namespace std;

//methodes
Duree::Duree(int h, int min, int sec) : m_heures(h), m_minutes(min), m_secondes(sec)
{
    this->format();
}

Duree::~Duree()
{
    
}

void Duree::format()
{
    int tempM(0), tempH(0);
    
    if(m_secondes > 60)
    {
        tempM = m_secondes / 60;
        m_secondes %= 60;
        m_minutes += tempM;
    }
    
    if(m_minutes > 60)
    {
        tempH = m_minutes / 60;
        m_minutes %= 60;
        m_heures += tempH;
    }
}

void Duree::affichage()
{
	cout << this << endl; //affiche l'adresse memoire de l'objet, this est le pointeur de l'objet
    cout << m_heures << " : " << m_minutes << " : " << m_secondes << endl; 
}


//fonction servant a la surchage d'operator

bool Duree::estEgal(Duree const& b) const
{
    return (m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes == b.m_secondes);
}

bool Duree::estPlusPetit(Duree const& b) const
{
	if(m_heures < b.m_heures)
		return true;
	else if(m_heures == b.m_heures && m_minutes < b.m_minutes)
		return true;
	else if(m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes < b.m_secondes)
		return true;
		
	return false;
}

bool Duree::estPlusGrand(Duree const& b) const
{
	if(m_heures > b.m_heures)
		return true;
	else if(m_heures == b.m_heures && m_minutes > b.m_minutes)
		return true;
	else if(m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes > b.m_secondes)
		return true;
		
	return false;
}

Duree Duree::addition(Duree const& b) const
{
	int h(0);
	int m(0);
	int s(0);
	
	h = m_heures + b.m_heures;
	m = m_minutes + b.m_minutes;
	s = m_secondes + b.m_secondes;
	return Duree(h,m,s);
}

Duree Duree::soustraction(Duree const& b) const
{
	int h(0);
	int m(0);
	int s(0);
	
	h = m_heures - b.m_heures;
	m = m_minutes - b.m_minutes;
	s = m_secondes - b.m_secondes;
	return Duree(h,m,s);
}

//surcharge operator
void Duree::affiche(ostream & flux) const
{
	flux << m_heures << "h" << m_minutes << "m" << m_secondes << "s";
}

bool Duree::operator==(Duree const& b) const
{
    return this->estEgal(b);
}

bool Duree::operator!=(Duree const& b) const
{
    return !(this->estEgal(b));
}


bool Duree::operator<(Duree const& b) const
{
	return (this->estPlusPetit(b));
}

bool Duree::operator>(Duree const& b) const
{
	return (this->estPlusGrand(b));
}

Duree Duree::operator+(Duree const& b)
{
	Duree resultat;
	resultat = this->addition(b);
	return resultat;	
}

Duree Duree::operator-(Duree const& b)
{
	Duree resultat;
	resultat = this->soustraction(b);
	return resultat;	
}

Duree& Duree::operator+=(Duree const& b)
{
	m_secondes += b.m_secondes;
	
	if(m_secondes > 60)
	{
		m_minutes += m_secondes / 60;
		m_secondes %= 60;
	}
	
	m_minutes += b.m_minutes;
	
	if(m_minutes > 60)
	{
		m_heures += m_minutes / 60;
		m_minutes %= 60;
	}
	
	m_heures += b.m_heures;
	return *this;	
}