#ifndef OBJECT
#define OBJECT
#include <cstdlib>
#include<cstdio>
#include <cmath>

class Object
{
private:
	float x;  
	float y;
	friend class Growth_medium;
	friend class Bacterium;
	friend class Nutrient_particle;
	
public:
	Object(int x = 0, int y = 0, int status = 0) {
		this->x = x;
		this->y = y;
	}; //получение координаты x
	virtual float get_x() const {
		return x;
	}
	// получение координаты y
	virtual  float get_y() const {
		return y;
	}
	// проверка статуса - частица (2) или бактерия (1). 
	virtual  int get_status() const {
		return 0;
	}
	virtual void print() const;
	virtual ~Object() {}
};
#endif


