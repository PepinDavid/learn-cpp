#include "Vehicule.h"

using namespace std;

Vehicule::Vehicule(string name, int power, int nbWheels, int price){
	m_name = name;
	m_power = power;
	m_nbWheels = nbWheels;
	m_price = price;
}

Vehicule::~Vehicule(){
	
}

void Vehicule::setVehicule(string name, int power, int nbWheels, int price){
	m_name = name;
	m_power = power;
	m_nbWheels = nbWheels;
	m_price = price;
}

void Vehicule::info() const{
	cout << "je suis un vehicule " << endl;
	cout << "power : " << m_power << endl;
	cout << "number wheels : " << m_nbWheels << endl;
	cout << "price : " << m_price << endl;	
}
void Vehicule::presentate() const{
	cout << "je suis un vehicule " << endl;
}