#include <stdio.h>
#include <string>
#include <vector>
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
	vector<Vehicule> listVeh;
	vector<Vehicule*> listPtrVeh;
	
	listPtrVeh.push_back(new Auto("peugeot", 90, 4, 6000, 5));
	listPtrVeh.push_back(new Auto("lambo", 450, 4, 200000, 2));
	listPtrVeh.push_back(new Moto("honda", 160, 2, 10000, 290));
	listPtrVeh.push_back(new Moto("suzuki", 180, 2, 13000, 320));
	listVeh.push_back(Auto());
	listVeh.push_back(Auto("renaut", 50, 4, 2000, 3));
	listVeh.push_back(Auto("bmw", 280, 4, 16000, 3));
	listVeh.push_back(Moto("kawa", 140, 2, 8000, 270));
	
	for(int i = 0; i < listPtrVeh.size(); i++){
		listPtrVeh[i]->info();
	}
	for(int i = 0; i < listPtrVeh.size(); i++){
		listVeh[i].info();
	}
	for(int i = 0; i < listPtrVeh.size(); i++){
		delete listPtrVeh[i];
		listPtrVeh[i] = 0;
	}
	for(int i = 0; i < listPtrVeh.size(); i++){
		listVeh[i].info();
	}
	return 0;
}
