#include "MonsterGreen.h"

using namespace std;

MonsterGreen::MonsterGreen(int x, int y) : Monster(x, y)
{ 
    cout << "MonsterGreen créé" << endl; 
}

MonsterGreen::~MonsterGreen() 
{
    
}

void MonsterGreen::draw()
{
    glPushMatrix();
    
    glTranslated(m_posX+0.5, m_posY+0.5, 0.0);
    //la tete
    glColor3d(0.0, 0.9, 0.0); //vert
    glutSolidSphere(0.3, 12, 12); // sphere de la tete
    //des cornes
    glPushMatrix();
    glTranslated(0.0, -0.13, 0.0);
    glScaled(1.0, 0.5, 1.0);
    glutSolidCube(0.5);
    glPopMatrix();
    //les yeux
    glTranslated(-0.3, -0.1, 0.0);
    glColor3d(1.0, 0.0, 0.0); //couleur rouge
    glutSolidSphere(0.05, 12, 12); //1ere oeil
    glTranslated(0.25, 0.0, 0.0);
    glutSolidSphere(0.05, 12, 12); //2eme oeil
    glTranslated(0.25, 0.0, 0.0);
    glutSolidSphere(0.05, 12, 12); //2eme oeil
    glPopMatrix();
}