#include "Auto.h"

using namespace std;

Auto::Auto(string name, int power, int nbWheels, int price, int doors) : Vehicule(name, power, nbWheels, price){
	m_doors = doors;
}

Auto::~Auto(){
}

void Auto::setAuto(string name, int power, int nbWheels, int price, int doors) {
	Vehicule::setVehicule(name, power, nbWheels, price);
	m_doors = doors;
}

void Auto::info() const{
	cout << "je suis une voiture " << endl;
	cout << "name : " << m_name << endl;
	cout << "power : " << m_power << endl;
	cout << "number wheels : " << m_nbWheels << endl;
	cout << "price : " << m_price << endl;
	cout << "number doors : " << m_doors << endl;
}

void Auto::presentate() const{
	cout << "je suis une voiture " << endl;
	cout << "name : " << m_name << endl;
}