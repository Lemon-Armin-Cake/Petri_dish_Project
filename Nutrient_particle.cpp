#include<cstdio>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include "Growth_medium.h"
#include "Nutrient_particle.h"  


 
 void Nutrient_particle::print() const
 {
	 static int k = 0;
	 printf(" Particle # %d \n", k);
	 printf("the status is %d \n", (this->get_status()));
	 printf("w = %f \n", x);
	 printf("z = %f \n", y);
	 printf("f = %d \n", f);
	 k++;
 }

 