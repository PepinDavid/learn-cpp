#ifndef DEF_MONSTER
#define DEF_MONSTER

#include "Perso.h"

class Monster : public Perso
{
public:
    Monster(int x = 0, int y = 0);
    virtual ~Monster();
};

#endif