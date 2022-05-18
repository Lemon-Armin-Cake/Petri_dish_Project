#include"Bacterium.h"
#include "Growth_medium.h"
#include "Nutrient_particle.h"  
#include "Objects.h"
#include <exception>
#include<cstdio>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>



float Growth_medium::get_a() const {
	//assert(a > 0);
	try
	{
		if (a > 0)
		{
			return a;
		}
		else
			throw (a);
	}
	catch (float& number)
		//(const std::exception& err)
	{
		printf("Error!");
		number = 20;

	} 
		//"The parametr is incorrect! It will be replace to a = 20";
	return a;
}
float Growth_medium::get_b() const {
	assert(b > 0);
	return b;
}
int Growth_medium::get_p() const {
	assert(p > 0);
	return p;
}

int comp(Object** a, Object** b)
{
	Object* p = *a;
	Object* t = *b;
	if ((p->get_x()) - (t->get_x()) > 0) return 1;
	if ((p->get_x()) - (t->get_x()) < 0) return -1;
	if ((p->get_x()) - (t->get_x()) == 0) return 0;
}


void Growth_medium::print_GM() const
{
    //static int k = 0;
    printf("\nGrowth_medium was created with the next parametres:\n");
    printf("a = %f \n", (this->a));
    printf("b = %f \n", (this->b));
    printf("p = %d \n\n", (this->p));
}

void Growth_medium::around(float x, float y, float dist)
{
    int i;
    printf("\n OOO we are mmm \n");
    std::list <Object*> listok;
    for (i = 0; i < 42; i++)
    {
        if (sqrt((( massive[i]->x - x) * ((massive[i]->x - x))) + ((massive[i]->y - y) * ((massive[i]->y - y)))) < dist)
        {
            listok.push_back(massive[i]);
            printf("\n we are here \n");
        }
    }
    for (auto iter = listok.begin(); iter != listok.end(); iter++)
        (*iter)->print();
}

void Growth_medium::particle_distribution_new (float a, float b, int p, Object** massive, Nutrient_particle* kartt)
{
	int y_width, p1, t, i, h, m = 0;
	float d, w_m, ran, step_x, step_y;
	t = 2; // ����� ������ � ����� ������ �� ��� y
	//������� �������� ������������� ������ �� ���������� x
	//��� ����� �������� ������ �� ������������ ���� �� ������� ������ ����� 
	step_x = a / 8;// ����� ������� �� ��� X, ������� ������������� ������������ ����� ������
	step_y = b / p;
	double el_z[36];
	p1 = 1; //����� ������ � ������ �������
	y_width = t; //����� ������ ��� ������� ������� �� ��� y
	//������ ��� �������������� ����������, ������� � ������ ������ ��������������� ������������ ������:
	d = (2 * p / 8 - 2 * p1) / 7;
	//�������� ������ �������� ��������� ��� z
	for (i = 0; i < 36; i += 2)
	{
		el_z[i] = i * step_y + ((double)(rand()) / (RAND_MAX / step_y));
		el_z[i + 1] = i * step_y + ((double)(rand()) / (RAND_MAX / step_y));
	}
	printf("\Steps x, y = %f   %f\n", step_x, step_y);


	for (i = 0; i < 8; i++)
	{
		ran = ((double)(rand()) / (RAND_MAX * p));

		for (h = p1; h <= p1 + i * d; h += d)
		{
			w_m = i * step_x + m * ran;
			//kartt[m].get_x();
			kartt[m].x = w_m;
			kartt[m].y = el_z[m];
			kartt[m].f = rand() % 9 + 1;
			m++;

		}

	}
}

void Growth_medium::start()
{
	Nutrient_particle kartt[36];
	//������� �����
	int i, j, p;
	print_GM();
	//������� ���� ������. ����� ������ �������� � ������� �����!
		particle_distribution_new(get_a(), get_b(), get_p(), massive, kartt);
		//throw "The parametr is incorrect! It will be replace to a = 20";
	//������� ���� ��������. ����� ������ �������� � ������� �����!
	Bacterium array[6];
	for (i = 0; i < 6; i++)
	{
		array[i].bacterium_creating(get_a(), get_b());
		massive[36 + i] = &(array[i]);
	}
	for (i = 0; i < 36; i++)
	{
		massive[i] = &(kartt[i]);
	}
	//��������� ������, ������ ������������ ���:
	qsort(massive, 42, sizeof(*massive), (int(*)(const void*, const void*))comp);
	//G1.around(1, 1, 3);
	float eat_x[36]; //������� ������� � ������������ ��������� ������
	float eat_y[36]; // ��� ���������� ��� �������� ����� ������
	int eaten_particles[36];
	int eat_amt = 0;// ���������� ��������� ������
	int AMT = 3; //���������� ������ - ����� ����� ���������� �������������
	for (p = 0; p < AMT; p++)
	{
		eat_amt = 0; //����� ��������� �� �������� ������
		//for (i = 0; i < 42; i++)   //���� �� ������� � �������, ��� �������� ������ ������.
		for (i = 0; i < 10; i++)   //����� ���� �� ����� - ��� ��������, �� ����� ����� ���������� ������ �������������
		{
			if ((massive[i]->get_status()) == 1) //��������� �������� - ��������, ��������� ���������� ����������
			{ 
				printf("\n\n Object %d is a Bacterium\n", i);
				massive[i]->print();
				((Bacterium*)massive[i])->x_last = ((Bacterium*)massive[i])->x;
				((Bacterium*)massive[i])->y_last = ((Bacterium*)massive[i])->y;
				((Bacterium*)massive[i])->brownian_motion();
				((Bacterium*)massive[i])->one_active_step();
			}
			if ((massive[i]->get_status()) == 2) //��������� ������� - �������, �������� �� ��������, ������� � �����
			{
				printf("\n\n Object %d is a Particle\n", i);
				massive[i]->print();
				for (j = i + 1; j < 42; j++)  //���� ������ - ��������� ������� ����������
				{
					if (((massive[j]->get_status()) == 1))
					{
						if (((Bacterium*)massive[j])->size >= sqrt((massive[i]->get_x() - massive[j]->get_x()) * (massive[i]->get_x() - massive[j]->get_x()) + (massive[i]->get_y() - massive[j]->get_y()) * (massive[i]->get_y() - massive[j]->get_y())))
						{
							printf("\n AAAA the particle %d was eaten by Bacterium %d\n", i, j);
							((Nutrient_particle*)massive[i])->st = 0; //������ ������ ������� �� "�������"
							((Bacterium*)massive[j])->food += ((Nutrient_particle*)massive[i])->f; //��������� �������� �������������
							massive[j]->print();
							break;
						}
					}
				}

				for (j = i - 1; j >= 0; j--)  //���� ����� - ��������� ������� ������ ���������
				{
					if (((Nutrient_particle*)massive[i])->st == 0) //��� ������ ����������, ���� ������� �������
						break;
					if (((massive[j]->get_status()) == 1))
					{
						if ((((Bacterium*)massive[j])->size >= fabs(massive[i]->get_x() - ((Bacterium*)massive[j])->get_x_last())) && (((Bacterium*)massive[j])->size >= sqrt((((Bacterium*)massive[j])->get_x_last() - massive[i]->get_x()) * (((Bacterium*)massive[j])->get_x_last() - massive[i]->get_x()) + (((Bacterium*)massive[j])->get_y_last() - massive[i]->get_y()) * (((Bacterium*)massive[j])->get_y_last() - massive[i]->get_y()))))
						{
							printf("\n AAAA the particle %d was eaten by Bacteria %d\n", i, j);
							((Nutrient_particle*)massive[i])->st = 0; //������ ������ ������� �� "�������"
							break;
						}
					}
				}
				//���� � ����� ������� ������� - ����������� ����� ��������� �� 1, ��������� ����������
				if (((Nutrient_particle*)massive[i])->st == 0)
				{
					eat_x[eat_amt] = ((Nutrient_particle*)massive[i])->get_x();
					eat_y[eat_amt] = ((Nutrient_particle*)massive[i])->get_y();
					eaten_particles[eat_amt] = i;
					printf("\n Particle %d is no more \n", i);
					eat_amt++;
				}
				else printf("\n the particle %d is alive\n", i);
			}

		}
		//����� ��������� ����� �������, ����� ������
		// ��� ������, �.�. ��������� ������� ������������� � ��������� ��������� �������� � �������
		// �.�. ���������� x � y ����������, ���������� ������� � ������������ ��������� ������ � ������� �� ������
		// ������ ��������� ��� ��������� ������
		printf("\n Print the massive of eaten particles\n");
		printf("\n %d particles was eaten \n", eat_amt);
		std::random_shuffle(eat_x, eat_x + eat_amt);
		std::random_shuffle(eat_y, eat_y + eat_amt);
		for (j = 0; j < eat_amt; j++)
		{
			i = eaten_particles[j];
			((Nutrient_particle*)massive[i])->x = eat_x[j];
			((Nutrient_particle*)massive[i])->y = eat_y[j];
			((Nutrient_particle*)massive[i])->f = rand() % 9 + 1;
			((Nutrient_particle*)massive[i])->st = 1;
		}
		//������������ ������
		qsort(massive, 42, sizeof(*massive), (int(*)(const void*, const void*))comp);
		printf("\n ___________________The iteration %d finished________________________ \n", p);
	}
}

extern "C"
{

	__declspec(dllexport) Growth_medium* generate_medium(float a, float b, int p) {
		return new Growth_medium(a, b, p);
	}
	__declspec(dllexport) float get_a(Growth_medium* G) {
		return G->get_a();
	}
	__declspec(dllexport) float get_b(Growth_medium* G) {
		return G->get_b();
	}
	__declspec(dllexport) int get_p(Growth_medium* G) {
		return G->get_p();
	}
	__declspec(dllexport) void dispose_Growth_medium(Growth_medium* G) {
		delete G;
	}
	__declspec(dllexport) void Start_G(Growth_medium* G) {
		G->start();
		printf("I'm here. It's so strange");
	}

}
