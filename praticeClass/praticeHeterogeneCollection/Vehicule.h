#ifndef DEF_VEHICULE
#define DEF_VEHICULE

#include <iostream>
#include <string>

class Vehicule{
protected:
	std::string m_name;
	int m_power;
	int m_nbWheels;
	int m_price;
public:
	Vehicule(std::string name = "Véhicule", int power = 0, int nbWheels = 1, int price = 1000);
	virtual ~Vehicule();
	void setVehicule(std::string name, int power, int nbWheels, int price);
	virtual void info() const;
	void presentate() const;
};

#endif