#include "Arme.h"

using namespace std;

//ce constructeur equivaut au suivant car
//dans le prototypage des valeurs par defauts sont données aux arguments
//Arme::Arme() : m_nom("Epée rouillée"), m_degat(10)
//{
//    
//}

Arme::Arme(string name, int degat) : m_nom(name), m_degat(degat)
{
    
}

void Arme::changer(string newName, int newDegats)
{
    m_nom = newName;
    m_degat = newDegats;
}

int Arme::getDegats() const
{
    return m_degat;
}

void Arme::affichage() const
{
    cout << "\t Arme : " << endl;
    cout << "\t\t nom : " << m_nom << endl;
    cout << "\t\t degats : " << m_degat << endl;
}