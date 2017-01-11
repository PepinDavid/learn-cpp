#ifndef DEF_MONSTERGREEN
#define DEF_MONSTERGREEN

#include "Monster.h"
#include "GL/glut.h"

class MonsterGreen : public Monster
{
public:
    MonsterGreen(int x = 10, int y = 8);
    virtual ~MonsterGreen();
    void draw();
    
};

#endif