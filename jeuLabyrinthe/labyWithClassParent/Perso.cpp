#include "Perso.h"

using namespace std;
//variables global dans main.cpp
extern int nbColumns, nbLines;
extern char ** matrice;
Perso::Perso()
{
    m_posX = 0;
    m_posY = 0;
}

Perso::Perso(int posX, int posY) : m_posX(posX), m_posY(posY)
{
    cout << "Perso créé" << endl;
}

Perso::~Perso()
{
    
}

int Perso::getPosX() const
{
    return m_posX;
}

int Perso::getPosY() const
{
    return m_posY;
}

void Perso::setPosX(int x)
{
    m_posX = x;
}

void Perso::setPosY(int y)
{
    m_posY = y;
}

void Perso::goLeft()
{
    if(m_posX > 0 && matrice[m_posX-1][m_posY] != '0')
    {
        m_posX--;
    }
}
void Perso::goRight()
{
    if(m_posX < nbColumns - 1 && matrice[m_posX+1][m_posY] != '0')
    {
        m_posX++;
    }
}
void Perso::goUp()
{
    if(m_posY > 0 && matrice[m_posX][m_posY-1] != '0')
    {
        m_posY--;
    }
}
void Perso::goDown()
{
    if(m_posY < nbLines-1 && matrice[m_posX][m_posY+1] != '0')
    {
        m_posY++;
    }
}