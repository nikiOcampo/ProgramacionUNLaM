#include <stdio.h>
#include <stdlib.h>
#include "elimrep.h"


void eliminarRepetidos(tlista *pl, int(*cmp)(const void*, const void*))
{
    tNodo *elim;
    if(*pl)
        pl=&(*pl);
    while( *pl && (*pl)->sig)
    {
        if((cmp((*pl)->info, (*pl)->sig))==0)
        {
            elim=*pl;
            *pl=elim->sig;
            free(elim->info);
            free(elim);
        }
    }
}

int cmp(const void *a, const void *b)
{
    const unsigned* v1= (const unsigned*)a;
    const unsigned *v2= (const unsigned*)b;
    return *v1-*v2;
}
