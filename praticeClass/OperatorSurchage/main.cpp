#include <stdio.h>
#include "Duree.h"

using namespace std;

ostream& operator<<(ostream &flux, Duree const &duree)
{
	duree.affiche(flux);
	return flux;
}

int main(int argc, char **argv)
{
    Duree dureeA(4, 25, 0), dureeB(6, 40, 120), resultats;
	printf("hello world\n");
	cout << "DureeA" << endl;
	cout << dureeA << endl;
    dureeA.affichage();
	cout << "DureeB" << endl;
	dureeB.affichage();
	cout << "test d'égalité entre A et B " << endl;
    if(dureeB == dureeA)
        printf("c'est égal \n");
        
    if(dureeB != dureeA)
        printf("c'est pas égal \n");
    else
        printf("c'est toujours égal \n");
	
	cout << "addition de a et b" << endl;
	resultats = dureeA + dureeB;
	resultats.affichage();
	cout << "addition de b et resultats" << endl;
	dureeB += resultats;
	dureeB.affichage();
	
	cout << "addition de a et b et addition" << endl;
	resultats = resultats + dureeA + dureeB;
	resultats.affichage();	
	return 0;
}
