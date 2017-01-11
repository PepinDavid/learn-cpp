#include <stdio.h>
#include <string>

#include "Vehicule.h"
#include "Auto.h"
#include "Moto.h"

using namespace std;

void presentWithRef(Vehicule const& v){
	v.info();
}
void presentWithPtr(Vehicule * v){
	v->info();
}
void presentation(Vehicule const v){
	v.info();
}

void info(Vehicule const v){
	v.presentate();
}
void infoBis(Vehicule const& v){
	v.presentate();
}


int main(int argc, char **argv)
{
	/*Utilisation du polymorphisme avec les fonctions presentWithRef/Ptr presentation et info/infoBis
	 * Le polymorphisme fonctionne a condition que les fonctions des class utilisé dans les fonctions 
	 * du fichier main.cpp soit des fonctions virtual autrement et que ce soit le pointer ou la reference
	 * de l'instance de l'objet qui soit utilisé dans l'argument de la fonction
	 * */
	Vehicule v;
	Auto a;
	Moto m;
	cout << "UTILISATION METHODE VIRTUAL" << endl;
	cout << "sans ref " << endl;
	presentation(v); // ici, le polymorphisme ne fonctionne pas
	cout << "avec ref " << endl;
	presentWithRef(v); // ici, ça fonctionne
	cout << "avec pointeur" << endl;
	//presentWithPtr(&v); //ici, ça fonctionne
	
	cout << "UTILISATION METHODE VIRTUAL" << endl;
	cout << "sans ref " << endl;
	presentation(a);
	cout << "avec ref " << endl;
	presentWithRef(a);
	cout << "avec pointeur" << endl;
	//presentWithPtr(&a);
	
	cout << "UTILISATION METHODE VIRTUAL" << endl;
	cout << "sans ref " << endl;
	presentation(m);
	cout << "avec ref " << endl;
	presentWithRef(m);
	cout << "avec pointeur" << endl;
	//presentWithPtr(&m);
	
	//dans l'exemple suivant ça ne fonctionne pas du fait que la methode de l'objet n'est pas 
	//une fonction virtual
	cout << "UTILISATION METHODE" << endl;
	cout << "sans reference dans la fonction " << endl;
	info(v); 
	info(a);
	info(m);
	cout << "avec reference" << endl;
	infoBis(v);
	infoBis(a);
	info(m);
	return 0;
}
