#ifndef DEF_PLAYER
#define DEF_PLAYER
#include <limits>
#include "Perso.h"

#include "GL/glut.h"

class Player : public Perso 
{
private:
    char * m_name;
public:
    //constructeur
    Player(int x = 0, int y = 0, bool question = false);
    
    //destructeur
    virtual ~Player();

    //dessiner
    void getName();
    void draw();
};

#endif