#include "Moto.h"

using namespace std;

Moto::Moto(string name, int power, int nbWheels, int price, int maxSpeed) : Vehicule(name, power, nbWheels, price) {
	m_maxSpeed = maxSpeed;
}

Moto::~Moto(){
	
}

void Moto::setMoto(string name, int power, int nbWheels, int price, int maxSpeed){
	m_maxSpeed = maxSpeed;
	Vehicule::setVehicule(name, power, nbWheels, price);
}

void Moto::info() const{
	cout << "je suis une moto " << endl;
	cout << "power : " << m_power << endl;
	cout << "number wheels : " << m_nbWheels << endl;
	cout << "price : " << m_price << endl;
	cout << "max speed : " << m_maxSpeed << endl;
}

void Moto::presentate() const{
	cout << "je suis une moto " << endl;
}