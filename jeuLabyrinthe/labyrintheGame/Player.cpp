#include "Player.h"

using namespace std;

extern int nbColumns, nbLines;
extern char ** matrice;

Player::Player() : m_posX(0), m_posY(0)
{
    
}

Player::Player(int posX, int posY) : m_posX(posX), m_posY(posY)
{
    
}

Player::~Player()
{
    
}

int Player::getPosX() const
{
    return m_posX;
}

int Player::getPosY() const
{
    return m_posY;
}

void Player::draw()
{
    glPushMatrix();
    
    glTranslated(m_posX+0.5, m_posY+0.5, 0.0);
    glColor3d(1.0, 1.0, 0.0); //jaune
    glutSolidSphere(0.3, 12, 12); // sphere de la ete
    
    glTranslated(0.1, -0.1, 0.0);
    glColor3d(0.0, 0.0, 0.0); //couleur noir
    glutSolidSphere(0.05, 12, 12); //1ere oeil
    glTranslated(-0.2, 0.0, 0.0);
    glutSolidSphere(0.05, 12, 12); //2eme oeil
    
    glPopMatrix();
}

void Player::setPosX(int x)
{
    m_posX = x;
}

void Player::setPosY(int y)
{
    m_posY = y;}

void Player::goDown()
{
    if(m_posY < nbLines-1 && matrice[m_posX][m_posY+1] != '0')
    {
        m_posY++;
    }
}

void Player::goUp()
{
    if(m_posY > 0 && matrice[m_posX][m_posY-1] != '0')
    {
        m_posY--;
    }
}

void Player::goLeft()
{
    if(m_posX > 0 && matrice[m_posX-1][m_posY] != '0')
    {
        m_posX--;
    }
}

void Player::goRight()
{
    if(m_posX < nbColumns - 1 && matrice[m_posX+1][m_posY] != '0')
    {
        m_posX++;
    }
}