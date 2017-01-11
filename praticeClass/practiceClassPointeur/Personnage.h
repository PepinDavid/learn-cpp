#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <iostream>
#include <string>
#include "Arme.h"

//fichier.h sert a declarrer la classe avec ses attributs et les prototypes des methodes
class Personnage
{
private:
    //les attributs s'initialisent dans un constructeur !!!
    std::string m_name;
    int         m_vie; //m devant le nom signifie 'membre'
    int         m_mana; //attribut de la class
    Arme        * m_arme; //l'objet Arme n'appartient pas la class personnage
    //du fait de l'utilisation d'un pointeur
        
public:
    //constructeur sans surcharge
    Personnage();
    //pour evité que la cope d'un personnage utilise le meme pointeur arme
    //on doit ecrire le constructeur de copie
    Personnage(Personnage const & personnageCoping);
    Personnage& operator=(Personnage const & personnageCoping);
    //constructeur avec surcharge permettant de déclaré un Perso avec meilleur arme
    Personnage(std::string nom = "no name", std::string nomArme = "Mains nues", int degatArme = 5);
    //destructeur permet de desalloués la memoire qui a ete allouée dynamiquement
    //faire des delete sur des pointeurs par exemple
    ~Personnage();
    void subirDegats(int nbDegats);
    void attaquer(Personnage &cible);
    void prendrePotionVie(int qtyPotion);
    void changerArme(std::string nomNewArme, int degatNewArme);
    //methode constante, sont des methodes qui renvoye le plus souvent des informations
    //sur l'objet sans modifié l'objet en lui meme
    bool estVivant() const;
    std::string getName() const;
    void affichage() const;
    Personnage* getAdress();
};

#endif