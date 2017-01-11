#ifndef DEF_PERSO
#define DEF_PERSO

#include <iostream> // ce include sera herité a la class fille

//classe abstraite
class Perso
{
//private: //variable membre n'appartenant qu'a la classe

protected: // variable membre seront herité a class fille grace a protected
    int m_posX;
    int m_posY;
public: // utilisable partout dans le code et herité a la class fille egalement
    //constructeur
    Perso();
    Perso(int posX = 42, int posY = 42);
    //destructeur
    //une classe abstraite n'a pas besoin de destructeur car elle ne sera 
    //jamais instancié dans le main.cpp
    virtual ~Perso(); 
    //getteur
    int getPosX() const;
    int getPosY() const;
    //setteur
    void setPosX(int x);
    void setPosY(int y);
    //mouvements
    void goLeft();
    void goRight();
    void goUp();
    void goDown();
    //dessiner
    //le mot clef virtual sert a declaré une fonction
    //qui sera défini/redéfini dans les classes enfants
    virtual void draw() = 0;
};

#endif