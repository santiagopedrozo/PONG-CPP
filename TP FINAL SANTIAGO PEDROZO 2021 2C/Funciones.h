#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdlib.h>
#include <ctime>

float Random(int ma, int mi)
{
    return mi + (rand()%(ma-mi));
}


#endif // FUNCIONES_H_INCLUDED
