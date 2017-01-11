#ifndef DEF_PLAYER
#define DEF_PLAYER

#include <iostream>
#include "GL/glut.h"

class Player
{
    
private:
    int m_posX;
    int m_posY;
    
public:
    Player();
    Player(int posX = 0, int posY = 0);
    ~Player();
    int getPosX() const;
    int getPosY() const;
    void draw();
    void setPosX(int x);
    void setPosY(int y);
    void goLeft();
    void goRight();
    void goUp();
    void goDown();
};

#endif