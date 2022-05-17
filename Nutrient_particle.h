#pragma once
#include <cstdlib>
#include<cstdio>
#include<cassert>
#include "Objects.h"


	class Nutrient_particle: public Object
	{
	private:
		int f; // питательность
		int st = 1; //статус частицы: 0 - съедена, 1 - нет.

	public:
		friend class Growth_medium;
		Nutrient_particle(float x = 1, float y = 5, int f = 6)
		 : Object (x, y) {
			this->x = x;
			this->y = y;
			this->f = f;
		}
		inline float get_x() const {
			assert(x >= 0);
			return x;
		}
		float get_y() const {
			assert(y >= 0);
			return y;
		}
		virtual int get_status() const {
			return 2;
		}
		int get_st() const {
			return st;
		}
		int get_f() const {
			assert(f >0);
			return f;
		}
		void print() const;
		//virtual ~Nutrient_particle();
	};


