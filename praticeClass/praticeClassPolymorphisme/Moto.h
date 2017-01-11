#ifndef DEF_MOTO
#define DEF_MOTO

#include "Vehicule.h"

class Moto : public Vehicule{
private:
	int m_maxSpeed;
public:
	Moto(std::string name = "Moto", int power = 180, int nbWheels = 2, int price = 2500, int maxSpeed = 4);
	virtual ~Moto();
	void setMoto(std::string name, int power, int nbWheels, int price, int maxSpeed);
	virtual void info() const;	
	void presentate() const;
};

#endif