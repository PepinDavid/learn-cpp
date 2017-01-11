#ifndef DEF_ARME
#define DEF_ARME

#include <iostream>
#include <string>

class Arme
{
private:
    std::string m_nom;
    int m_degat;
public:
//    Arme();
    Arme(std::string nom = "Mains nues", int degat = 5);
    void changer(std::string newName, int newDegats);
    int getDegats() const;
    void affichage() const;
};

#endif