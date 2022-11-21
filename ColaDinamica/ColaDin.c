#include "ColaDin.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void crearCola(t_cola *pc)
{
    pc->pri=pc->ult=NULL;
}

int ponerEnCola(t_cola *pc, const void *pd, unsigned tam)
{
    tNodo *nue=(tNodo*) malloc(sizeof(tNodo));
    if(!nue) return COLA_LLENA;

    nue->info=malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return COLA_LLENA;
    }

    nue->tamInfo=tam;
    memcpy(nue->info,pd,tam);
    nue->sig=NULL;

    if(pc->ult)
        pc->ult->sig=nue;
    else
        pc->pri=nue;
    pc->ult=nue;

    return OK;
}

int sacarDeCola(t_cola *pc, void *pd, unsigned tam)
{
    tNodo *elim=pc->pri;
    if(!elim)
        return COLA_VACIA;
    memcpy(pd,elim->info,MIN(tam,elim->tamInfo));
    pc->pri=elim->sig;
    if(!pc->pri)
        pc->ult=NULL;

    free(elim->info);
    free(elim);

    return OK;
}

int frenteDeCola(t_cola *pc,void *pd, unsigned tam)
{
    tNodo *frente=pc->pri;
    if(!frente) return COLA_VACIA;
    memcpy(pd,frente->info, MIN(tam,frente->tamInfo));

    return OK;
}

int colaLlena(const t_cola *pc,unsigned tam)
{
    tNodo *nue=(tNodo*)malloc(sizeof(tNodo));
    if(pc->pri && !nue)
        return COLA_LLENA;
    nue->info=malloc(tam);
    free(nue->info);
    free(nue);

    return OK;
}

int colaVacia(const t_cola *pc)
{
    return !pc->pri;
}
