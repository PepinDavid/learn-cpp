#include <stdio.h>
#include <string>
#include "Personnage.h"
#include "Arme.h"

using namespace std;


int main(int argc, char **argv)
{
    Personnage david("david"), goliath("goliath");
    david.affichage();
    goliath.affichage();
    david.attaquer(goliath);
    goliath.changerArme("Epée rouillée", 10);
    goliath.attaquer(david);
    david.changerArme("Epée de la mort qui tue", 70);
    david.attaquer(goliath);
    david.affichage();
    goliath.affichage();
	return 0;
}
