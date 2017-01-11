#include "Personnage.h"

using namespace std;


//constructeur

//constructeur avec liste des attributs, précédé d'un " : " 
//toujours préférer cette method de constructor
Personnage::Personnage() : m_name("no name"), m_vie(100), m_mana(100)
{
    m_arme = new Arme("Mains nues", 5);
}
//constructeur avec surcharge 
Personnage::Personnage(string name, string nomArme, int degatsArme) : m_name(name), m_vie(100), m_mana(100)
{
    //declaration dynamique
    m_arme = new Arme(nomArme, degatsArme);
}

//constructeur de copie
Personnage::Personnage(Personnage const & persoCoping) : m_name(persoCoping.m_name),  m_vie(persoCoping.m_vie), m_mana(persoCoping.m_mana)
{
    //persoCoping.m_arme est un pointeur
    //hors on veut l'objet avec ses attributs et ses methodes
    //on rajoute donc une "*" pour avoir l'objet
    m_arme = new Arme( * (persoCoping.m_arme));
}
//qui dit constructeur de copie 
//dit surcharge operator d'égalité
Personnage& Personnage::operator =(Personnage const & persoCoping)
{
    if(this != &persoCoping)
    {
        m_vie = persoCoping.m_vie;
        m_mana = persoCoping.m_mana;
        m_name = persoCoping.m_name;
        delete m_arme;
        m_arme = new Arme( *(persoCoping.m_arme));
    }
    return *this;
}


//destructeur
Personnage::~Personnage()
{
    //desalocation du pointeur arme
    delete m_arme;
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
    cible.subirDegats(m_arme->getDegats());
    cout << cible.getName() << " perd " << m_arme->getDegats() << " points de vies " << endl;
}

void Personnage::changerArme(string nomNewArme, int degatNewArme)
{
        cout << m_name << " trouve une nouvelle arme !!! " << endl;
        cout << "Description nouvelle arme : " << endl;
        cout << "\t Nom : " << nomNewArme <<  ", degats : " << degatNewArme << endl;
        m_arme->changer(nomNewArme, degatNewArme);
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
    m_arme->affichage();
}

Personnage* Personnage::getAdress()
{
    //retour adresse memoire de personnage
    //car this désigne l'objet lui même
    //en pointeur
    return this;    
}