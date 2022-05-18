#include <cstdlib>
#include<cstdio>
#include "Objects.h"

void Object::print() const
{
    static int kb = 0;
    printf("Massive # %d \n", kb);
    printf("x = %f \n", (this->x));
    printf("y = %f \n", (this->y));
    kb++;
}