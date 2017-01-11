#ifndef DEF_DUREE
#define DEF_DUREE

#include <iostream>
#include <string>

class Duree
{
private:
    int m_heures;
    int m_minutes;
    int m_secondes;
    void format();
    
public:
    //constructor
    Duree(int h = 0, int min = 0, int sec = 0);
    //destructor
    ~Duree();
    
    void affichage();
	void affiche(std::ostream & flux) const;
    bool estEgal(Duree const& b) const;
	bool estPlusPetit(Duree const& b) const;
	bool estPlusGrand(Duree const& b) const;
	Duree addition(Duree const& b) const;
	Duree soustraction(Duree const& b) const;
	//surcharge operator
	bool operator==(Duree const& b) const;
	bool operator!=(Duree const& b) const;
	bool operator<(Duree const& b) const;
	bool operator>(Duree const& b) const;
	//operation arithmetique
	Duree operator+(Duree const& b);
	Duree operator-(Duree const& b);
	Duree& operator+=(Duree const& b);
};

#endif