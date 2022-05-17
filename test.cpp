#include<cstdio>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<cassert>
#include <algorithm>
#include <functional>
#include <string>
#include<typeinfo>
#include"Bacterium.h"
#include "Growth_medium.h"
#include "Nutrient_particle.h"  
#include "Objects.h"

//srand(time(nullptr));





void test_Bacterium()
{
	int i;
	//создаем бактерию
	Bacterium B1(9, 3, -0.5, 0, 4, 1);
	assert(B1.get_x() == 9);
	assert(B1.get_y() == 3);
	assert(B1.get_q() == -0.5);
	assert(B1.get_n() == 0);
	assert(B1.get_s() == 4);
	assert(B1.get_v() == 1);
	//B1.print();
	
	// создаем бактерии с ошибкой. переменные, которые не могут быть отрицательными: x, y, n, s.
	// Также s != 0, x <= a, y <= b.
	Bacterium B2(-7, 6, 0.25, 0, 3, 2);
	assert(B2.get_x() == -7); //недопустимое значение
	assert(B2.get_y() == 6);
	assert(B2.get_q() == 0.25);
	assert(B2.get_n() == 0);
	assert(B2.get_s() == 3);
	assert(B2.get_v() == 2);
	//B2.print();

	Bacterium B3(9, -3, 0.25, 0, 1, 5);
	assert(B3.get_x() == 9);
	assert(B3.get_y() == -3); //недопустимое значение
	assert(B3.get_q() == 0.25);
	assert(B3.get_n() == 0);
	assert(B3.get_s() == 1);
	assert(B3.get_v() == 5);
	//B3.print();

	Bacterium B4(10, 23, 0.5, 0, 2, 3);
	assert(B4.get_x() == 10);
	assert(B4.get_y() == 23); //недопустимое значение (b = 20)
	assert(B4.get_q() == 0.5);
	assert(B4.get_n() == 0);
	assert(B4.get_s() == 2);
	assert(B4.get_v() == 3);
	//B4.print();


	Bacterium B5(12, 14, 0.25, 0, 7, 1);
	assert(B5.get_x() == 12); //недопустимое значение (a = 10)
	assert(B5.get_y() == 14);
	assert(B5.get_q() == 0.25);
	assert(B5.get_n() == 0);
	assert(B5.get_s() == 7);
	assert(B5.get_v() == 1);
	//B5.print();

	Bacterium B6(8, 10, 0.5, 0, -3, 2);
	assert(B6.get_x() == 8);
	assert(B6.get_y() == 10);
	assert(B6.get_q() == 0.5);
	assert(B6.get_n() == 0);
	assert(B6.get_s() == -3); //теперь - допустимое значение
	assert(B6.get_v() == 2);
	//B6.print();

	Bacterium B7(8, 10, 0.25, 0, 0, 2);
	assert(B7.get_x() == 8);
	assert(B7.get_y() == 10);
	assert(B7.get_q() == 0.25);
	assert(B7.get_n() == 0);
	assert(B7.get_s() == 0); //недопустимое значение
	assert(B7.get_v() == 2);
	//B7.print();

	//бактерия делает активный шаг
	bool step;
	for (i = 0; i <= 4; i++)
	{
		step = B1.one_active_step();
		assert(step);
		//printf("\nBacterium #%d, active step \n", i);
		//B1.print();
		step = B1.brownian_motion();
		assert(step);
		//printf("\nBacterium #%d, passive step \n", i);
		//B1.print();
	} 
	// неправильная бактерия пытается сделать активный шаг 
	step = B2.one_active_step();
	assert(!step);
	step = B3.one_active_step();
	assert(!step);
	step = B4.one_active_step();
	assert(!step);
	step = B5.one_active_step();
	assert(!step);
	step = B6.one_active_step();
	assert(step);
	step = B7.one_active_step();
	assert(!step);
	//бактерия делает шаг под действием броуновского движения
	step = B2.brownian_motion();
	assert(!step);
	step = B3.brownian_motion();
	assert(!step);
	step = B4.brownian_motion();
	assert(!step);
	step = B5.brownian_motion();
	assert(!step);
	step = B6.brownian_motion();
	assert(step);
	step = B7.brownian_motion();
	assert(!step);
}

void test_Nutrient_Particle()
{
	Nutrient_particle NP1(1, 4.5, 6);
	assert(NP1.get_x() == 1);
	assert(NP1.get_y() == 4.5);
	assert(NP1.get_f() == 6);
	assert(NP1.get_st() == 1);
	assert(NP1.get_status() == 2);

	// на случай появления недопустимых значений соответствующие функции assert прописаны в заголовочном файле
}

void test_GMandNP()
{
	Growth_medium G(5, 7, 100);
	assert(G.get_a() == 5);
	assert(G.get_b() == 7);
	assert(G.get_p() == 100);
	// на случай появления недопустимых значений соответствующие функции assert прописаны в заголовочном файле

}

int main() {
	test_Bacterium();
	test_Nutrient_Particle();
	test_GMandNP();
	Growth_medium G1(20, 10, 36);
	G1.start();
	return 0;
}
