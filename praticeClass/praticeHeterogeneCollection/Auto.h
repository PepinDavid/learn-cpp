#ifndef DEF_AUTO
#define DEF_AUTO
#include "Vehicule.h"

class Auto : public Vehicule{
private:
	int m_doors;
public:
	Auto(std::string name = "Voiture", int power = 90, int nbWheels = 4, int price = 5000, int nbDoors = 4);
	virtual ~Auto();
	void setAuto(std::string name, int power, int nbWheels, int price, int nbDoors);
	virtual void info() const;	
	void presentate() const;
};

#endif