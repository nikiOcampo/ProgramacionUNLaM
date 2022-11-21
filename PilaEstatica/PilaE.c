#include "PilaE.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void crearPila(t_Pila *pp)
{
    pp->tope=TAM;
}

int ponerEnPila(t_Pila *pp, const void *pd, unsigned tam)
{
    if(pp->tope<tam+sizeof(size_t)) return PILA_LLENA;
    pp->tope-=tam;
    memcpy(pp->vect + pp->tope,pd,tam);
    pp->tope-=sizeof(size_t);
    memcpy(pp->vect+pp->tope,&tam,sizeof(size_t));
    return OK;
}

int sacarDePila(t_Pila *pp, void *pd, unsigned tam)
{
    unsigned tamDatoPila;
    if(pp->tope==TAM) return 0;
    memcpy(&tamDatoPila,pp->vect+pp->tope,sizeof(size_t));
    pp->tope+=sizeof(size_t);
    memcpy(pd, pp->vect+pp->tope,MIN(tam,tamDatoPila));
    pp->tope+=tamDatoPila;
    return OK;
}

int verTopePila(t_Pila *pp, void *pd, unsigned tam)
{
    unsigned tamInfo;

    if(pp->tope == TAM) return 0;
    memcpy(&tamInfo,pp->vect+pp->tope,sizeof(size_t));
    memcpy(pd,pp->vect+pp->tope+sizeof(size_t), MIN(tam,tamInfo));
    return OK;
}

void vaciarPila(t_Pila *pp)
{
    pp->tope=TAM;
}


int pilaLlena(const t_Pila *pp, unsigned tam)
{
    return pp->tope < tam+sizeof(size_t);
}

int pila_vacia(t_Pila *pp)
{
    return pp->tope == TAM;
}

