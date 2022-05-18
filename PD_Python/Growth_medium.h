#pragma once
#include <cstdlib>
#include <iostream>
#include<cstdio>
#include<cassert>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <functional>
#include <string>
#include<typeinfo>
#include "Objects.h"
#include "Nutrient_particle.h"  


class Growth_medium
{
public:
	friend class Nutrient_particle;
	friend class Objects;
	float a; // размер среды вдоль оси X
	float b; // размер среды вдоль оси Y
	int p; // число частиц
	Object * massive [42];



	Growth_medium(float a, float b, int p)
			:a(a), b(b), p(p) {
	}
	float get_a() const;
	float get_b() const;
	int get_p() const;
		void print_GM() const;
		void around(float x, float y, float dist);
		void particle_distribution_new(float a, float b, int p, Object** massive, Nutrient_particle* kartt);
		void start();
	};

