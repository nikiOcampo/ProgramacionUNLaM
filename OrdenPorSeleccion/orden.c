#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "orden.h"

void ordenPorSeleccion(tlista *pl, int (*cmp)(const void *, const void *))
{
    tlista *men;
    while(*pl && (*pl)->sig)
    {
        men=buscarMenor(pl,cmp);
        if(men!=pl)
            intercambiar((*pl)->info, (*men)->info, (*pl)->tam);
        pl=&(*pl)->sig;
    }
}

tlista* buscarMenor(tlista *pl, int(*cmp)(const void*,const void*))
{
    tlista *men=pl;
    pl=&(*pl)->sig;
    while(*pl)
    {
        if((cmp((*pl)->info,(*men)->info))>0)
            men=pl;
        pl=&(*pl)->sig;
    }

    return men;
}

int cmp(const void *a, const void *b)
{
    const unsigned* v1= (const unsigned*)a;
    const unsigned *v2= (const unsigned*)b;
    return *v1-*v2;
}

void intercambiar(void* v1, void*v2, unsigned tam)
{
    void *aux=malloc(tam);
    memcpy(aux,v1,tam);
    memcpy(v1,v2,tam);
    memcpy(v2,aux,tam);
    if(!aux) exit(1);
    free(aux);
}
