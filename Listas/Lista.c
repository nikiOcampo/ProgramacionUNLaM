#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void crearLista(t_lista *pl)
{
    *pl= NULL;
}

int listaLlena(const t_lista *pl,unsigned tam)
{
    tNodo *aux = (tNodo*)malloc(sizeof(tNodo));
    void *info= malloc(tam);
    // Liberar memoria alojada temporalmente
    free(aux);
    free(info);
    // En caso de que haya podido asignarse memoria, las variables aux y info
    // tendran una dirección de memoria en ellas. Por lo tanto, el retorno será
    // negativo. En cambio, si alguna de ellas no pudo se "allocada" tendrá en
    // si una dirección NULL, devolviendo un positivo.
    return (!aux || !info);
}

void vaciarLista(t_lista *pl)
{
    while(*pl)
    {
        tNodo *aux= *pl;
        *pl=aux->sig;
        free(aux->info);
        free(aux);
    }
}

int ponerAlComienzo(t_lista *pl, void *pd, unsigned tam)
{
    tNodo *nue= (tNodo*) malloc (sizeof(tNodo));
    if(!nue)
        return 0;
    nue->info= malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return 0;
    }
    nue->tamInfo= tam;
    nue->sig= *pl;
    memcpy(nue->info, pd, tam);
    *pl=nue;
    return OK;
}

int ponerAlUltimo(t_lista *pl, void *pd, unsigned tam)
{
    tNodo *nue;
    while(*pl)
    {
        pl=&(*pl)->sig;
    }
    nue= (tNodo*) malloc (sizeof(tNodo));
    if(!nue)
        return 0;
    nue->info= malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return 0;
    }
    nue->tamInfo= tam;
    nue->sig= *pl;
    memcpy(nue->info, pd, tam);
    *pl=nue;
    return OK;
}

int ponerEnPosicion(t_lista *pl, void *pd, unsigned tam, int pos)
{
    tNodo *nue;
    while(*pl && pos)
    {
        pl=&(*pl)->sig;
        pos--;
    }
    nue= (tNodo*) malloc (sizeof(tNodo));
    if(!nue)
        return 0;
    nue->info= malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return 0;
    }
    nue->tamInfo= tam;
    nue->sig= *pl;
    memcpy(nue->info, pd, tam);
    *pl=nue;
    return OK;
}

int ponerOrdenado(t_lista *pl, const void *pd, unsigned tam, int((*cmp)(const void *, const void*)))
{
    tNodo *nue;
    int comp=1;
    while(*pl && (comp=(cmp(pd,(*pl)->info)))>0)
    {
        pl=&(*pl)->sig;
    }
    if(!comp)
        return 0; //duplicado
    nue= (tNodo*) malloc (sizeof(tNodo));
    if(!nue)
        return 0;
    nue->info= malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return 0;
    }
    nue->tamInfo= tam;
    nue->sig= *pl;
    memcpy(nue->info, pd, tam);
    *pl=nue;
    return OK;
}


int sacarPrimero(t_lista *pl, void *pd, unsigned tam)
{
    tNodo *elim= *pl;
    if(!*pl)
    {
        return 0;
    }
    memcpy(pd,elim->info,MINIMO(elim->tamInfo,tam));
    *pl= elim->sig;
    free(elim->info);
    free(elim);

    return OK;
}

int sacarUltimo(t_lista *pl, void *pd, unsigned tam)
{
    tNodo *elim;
    while(*pl && (*pl)->sig)
    {
         pl=&(*pl)->sig;
    }
    elim= *pl;
    if(!*pl)
    {
        return 0;
    }
    memcpy(pd,elim->info,MINIMO(elim->tamInfo,tam));
    *pl= elim->sig;
    free(elim->info);
    free(elim);

    return OK;
}

int sacarDePosicion(t_lista *pl, const void *pd, unsigned tam, int((*cmp)(const void *, const void*)))
{
    tNodo *elim;
    int comp;
     while(*pl && (comp=(cmp(pd,(*pl)->info)))>0)
    {
        pl=&(*pl)->sig;
    }
    if(!pl || !comp)
        return 0;//no existe
    while(*pl && (*pl)->sig)
        pl=&(*pl)->sig;
    elim= *pl;
    if(!*pl)
    {
        return 0;
    }
    memcpy(pd,elim->info,MINIMO(elim->tamInfo,tam));
    *pl= elim->sig;
    free(elim->info);
    free(elim);
    return OK;
}

int cmp(const void* a, const void* b)
{
   return (const unsigned*)a - (const unsigned *)b;
}


int ponerYActualizar(t_lista *pl, const void *pd, unsigned tam, int(*cmp)(const void*, const void*),void (*actualizar)(void * ,const void*))
{
    tNodo *nue;
    int comp=1;
    while(*pl && (comp=cmp((*pl)->info, pd))<0)
        pl=&(*pl)->sig;
    if(!comp)
    {
        actualizar((*pl)->info, pd);
        return OK;
    }
    if(!(nue=(tNodo*)malloc(sizeof(tNodo)))|| !(nue->info =malloc(tam)))
    {
        free(nue);
        return 0;//SIN MEMORIA
    }
    nue->tamInfo=tam;
    memcpy(nue->info, pd, tam);
    nue->sig=*pl;
    *pl=nue;

    return OK;
}


void actualizar(void* ve, const void *vn)
{

}
