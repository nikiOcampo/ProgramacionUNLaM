#include "Cola.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void crearCola(t_cola *pc)
{
    pc->pri= TAM-70;
    pc->ult= TAM-70;
    pc->tamDisp=TAM;
}

int colaLlena(const t_cola *pc,unsigned tam)
{
    return pc->tamDisp < tam+ sizeof(size_t);
}

int ponerEnCola(t_cola *pc, const void *pd, unsigned tam)
{
    int inicio,fin;
    if(pc->tamDisp<tam+sizeof(size_t)) return COLA_LLENA;
    //COPIO PARA EL TAMAÑO
    inicio=MIN(TAM-pc->ult,sizeof(size_t));
    if(inicio)
        memcpy(pc->cola+pc->ult,&tam,inicio);
    fin=sizeof(size_t)-inicio;
    if(fin)
        memcpy(pc->cola,((char*)&tam+inicio),fin);

    pc->ult= fin? fin: pc->ult+inicio;

    //COPIO PARA EL DATO
    inicio=MIN(TAM-pc->ult,tam);
    if(inicio)
        memcpy(pc->cola+pc->ult,pd,inicio);
    fin=tam-inicio;
    if(fin)
        memcpy(pc->cola,pd+inicio,fin);

    pc->ult+=fin? fin:pc->ult+inicio;

    pc->tamDisp-=sizeof(size_t)+tam;

    return OK;
}

int sacarDeCola(t_cola *pc, void *pd, unsigned tam)
{
    int inicio,fin;
    unsigned tamDatoCola;
    if(pc->tamDisp==TAM) return COLA_VACIA;
    inicio= MIN(TAM-pc->pri,sizeof(size_t));
    if(inicio)
        memcpy(&tamDatoCola,pc->cola+pc->pri,inicio);
    fin=sizeof(size_t)-inicio;
    if(fin)
        memcpy(((char*)&tamDatoCola)+inicio,pc->cola,fin);
    pc->pri=fin? fin: pc->pri+inicio;
    inicio=MIN(TAM-pc->pri,tamDatoCola);
    if(inicio)
        memcpy(pd,pc->cola+pc->pri,MIN(inicio,TAM));
    fin=tamDatoCola-inicio;
    if(fin&& tam>inicio)
        memcpy(pd+inicio,pc->cola,MIN(inicio,fin));
    pc->tamDisp+=sizeof(size_t)+tamDatoCola;

    return OK;
}

void vaciarCola(t_cola *pc)
{
    pc->ult=pc->pri;
    pc->tamDisp= TAM;
}

int colaVacia(const t_cola *pc)
{
    return pc->tamDisp==TAM;
}



