#include "Personnage.h"

using namespace std;


//constructeur

//  //constructeur avec initialisation des attributs dans le corps
//  //de la fonction
//Personnage::Personnage()
//{
//    m_vie = 100;
//    m_mana = 100;
//    m_nomArme = "Épée rouillée";
//    m_degatsArme = 10;
//}

//constructeur avec liste des attributs, précédé d'un " : " 
//toujours préférer cette method de constructor
//Personnage::Personnage() : m_name("no name"), m_vie(100), m_mana(100), m_arme("Mains nues", 5)
//{
//    
//}
//constructeur avec surcharge 
Personnage::Personnage(string name, string nomArme, int degatsArme) : m_name(name), m_vie(100), m_mana(100), m_arme(nomArme, degatsArme)
{
    
}

//destructeur
Personnage::~Personnage()
{
    /* Rien à mettre ici car on ne fait pas d'allocation dynamique
    dans la classe Personnage. Le destructeur est donc inutile mais
    je le mets pour montrer à quoi cela ressemble.
    En temps normal, un destructeur fait souvent des delete et quelques
    autres vérifications si nécessaire avant la destruction de l'objet. */
}

void Personnage::subirDegats(int nbDegats)
{
    if(this->estVivant())
    {
        m_vie -= nbDegats;
        
        if(m_vie < 0)
        {
            m_vie = 0;
        }        
    }
    else
    {
        cout << "Le personnage : " << m_name << " est game over !!! " << endl;
    }
}

void Personnage::attaquer(Personnage &cible)
{
    cout << m_name << " attaque " << cible.getName() << endl;
    cible.subirDegats(m_arme.getDegats());
    cout << cible.getName() << " perd " << m_arme.getDegats() << " points de vies " << endl;
}

void Personnage::changerArme(string nomNewArme, int degatNewArme)
{
        cout << m_name << " trouve une nouvelle arme !!! " << endl;
        cout << "Description nouvelle arme : " << endl;
        cout << "\t Nom : " << nomNewArme <<  ", degats : " << degatNewArme << endl;
        m_arme.changer(nomNewArme, degatNewArme);
}

void Personnage::prendrePotionVie(int qtyPotion)
{
    m_vie += qtyPotion;
    
    if(m_vie >= 100)
    {
        m_vie = 100;
    }
}

//methode constante, sont des methodes qui renvoye le plus souvent des informations
//sur l'objet sans modifié l'objet en lui meme
bool Personnage::estVivant() const
{
    return m_vie > 0;
}

string Personnage::getName() const
{
    return m_name;
}
void Personnage::affichage() const
{
    cout << "Nom : " << m_name << endl;
    cout << "Points de vie " << m_vie << endl;
    cout << "Points de mana " << m_mana << endl;
    m_arme.affichage();
}