#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"
#include <string.h>
#include <math.h>


void crearArbolBinBusq(tArbolBinBusq *p)
{
    *p=NULL;
}

///INSERTAR DE FORMA ITERATIVA
int insertarArbolBinBusq(tArbolBinBusq *p, const void *d, unsigned tam, int (*cmp)(const void *, const void *))
{
    tNodoArbol *nue;
    int rc;

    while(*p)
    {
        if((rc=cmp(d, (*p)->info))<0)
            p= &(*p)->izq;
        else if (rc>0)
            p= &(*p)->der;
        else
            return 0; //CLA_DUP
    }

    if(!reservarMemoriaNodo(nue,sizeof(tNodoArbol),nue->info,tam))
        return 0; /// sin Memoria
    nue->tamInfo=tam;
    memcpy(nue->info,d,tam);
    nue->der=nue->izq=NULL;
    *p=nue;

    return OK;
}


int cmp(const void* a, const void* b)
{
    const unsigned *v1=(const unsigned*)a;
    const unsigned *v2=(const unsigned*)b;

    return *v1-*v2;
}

///INSERTAR DE FORMA RECURSIVA
int insertarRecArbolBinBusq(tArbolBinBusq *p, const void *d, unsigned tam, int (*cmp)(const void *, const void *))
{
    tNodoArbol *nue;
    int rc;
    if(*p)
    {
        if((rc=cmp(d, (*p)->info))<0)
            return insertarRecArbolBinBusq(&(*p)->izq,d,tam,cmp);
        if(rc>0)
            return insertarRecArbolBinBusq(&(*p)->der,d,tam,cmp);
        return 0; ///cla duplicado
    }
     if(!reservarMemoriaNodo(nue,sizeof(tNodoArbol),nue->info,tam))
        return 0; /// sin Memoria
    nue->tamInfo=tam;
    memcpy(nue->info,d,tam);
    nue->der=NULL;
    nue->izq=NULL;
    *p=nue;

    return OK;
}
///**********************************************************************************
int cargarDesdeDatorOrdenadosRec(tArbolBinBusq *p, void *d, unsigned (*leer)(void **, void *, unsigned, void *params),
                                int li, int ls, void*params)
{
    int m=(li+ls)/2, r;
    if(li>ls)
        return OK;

    (*p)=(tNodoArbol*)malloc(sizeof(tNodoArbol));
    if(!*p || !((*p)->tamInfo=leer(&(*p)->info,d,m,params)))
    {
        free(*p);
        return 0; ///sin memoria
    }

    (*p)->izq=(*p)->der=NULL;

    if((r=cargarDesdeDatorOrdenadosRec(&(*p)->izq,d,leer,li,m-1,params))!= OK)
        return r;
    return cargarDesdeDatorOrdenadosRec(&(*p)->der,d,leer,m+1,ls,params);
}

int cargarArchivoBinOrdenadoAbiertoArbolBinBusq(tArbolBinBusq *p, FILE *pf, unsigned tamInfo)
{
    int cantReg;
    if(*p|| !pf) return 0;
    fseek(pf,0L,SEEK_END);
    cantReg= ftell(pf)/tamInfo;
    return cargarDesdeDatorOrdenadosRec(p,pf,leerDesdeArchivoBin,0,cantReg-1, &tamInfo);
}

int cargarArchivoBinOrdenandoArbolBinBusq(tArbolBinBusq *p, const char *path, unsigned tamInfo)
{
    int cantReg, r;
    FILE *pf;
    if(*p)
        return 0; ///sin inicializar
    if(!(pf=fopen(path, "rb")))
        return 0; ///ERROR ARCHIVO
    fseek(pf,0L, SEEK_END);
    cantReg=ftell(pf)/tamInfo;
    r=cargarDesdeDatorOrdenadosRec(p,pf,leerDesdeArchivoBin,0,cantReg-1,&tamInfo);
    fclose(pf);
    return r;
}

unsigned leerDesdeArchivoBin(void **d, void *pf, unsigned pos, void *params)
{
    unsigned tam= *((int*)params);
    *d=malloc(tam);
    if(!d)
        return 0;
    fseek((FILE*)pf, pos*tam, SEEK_SET);
    return fread(*d,tam,1,(FILE*)pf);
}

int cargarDesdeDatosOrdenadosArbolBinBusq(tArbolBinBusq *p, void *d, unsigned cantReg, unsigned (*leer)(void**,void*,unsigned,void *params), void *params)
{
    if(*p||!d)
        return 0;
    return cargarDesdeDatorOrdenadosRec(p,d,leer,0,cantReg-1,params);
}

///*****************************************************************

int eliminarRaizArbolBinBusq(tArbolBinBusq *p)
{
    tNodoArbol ** remp, *elim;
    if(!*p)
        return 0;///arbol vacio

    free((*p)->info);
    if(!(*p)->izq && !(*p)->der)
    {
        free(*p);
        *p=NULL;
        return OK;
    }

    remp=alturaArbolBin(&(*p)->izq)>alturaArbolBin(&(*p)->der)?
        mayorNodoArbolBinBusq(&(*p)->izq): mayorNodoArbolBinBusq(&(*p)->der);

    elim=*remp;
    (*p)->info= elim->info;
    (*p)->tamInfo=elim->tamInfo;

    *remp=elim->izq? elim->izq: elim->der;
    free(elim);

    return OK;
}

int eliminarElemArbolBinBusq(tArbolBinBusq *p, void *d, unsigned tam, int(*cmp)(const void*, const void*))
{
    if(!(p=buscarNodoArbolBinBusq(p,d,cmp))) return 0; ///NO EXISTE
    memcpy(d, (*p)->info, MINIMO(tam, (*p)->tamInfo));
    return eliminarRaizArbolBinBusq(p);
}

int buscarElemArbolBinBusq(const tArbolBinBusq *p, void *d, unsigned tam, int(*cmp)(const void*, const void*))
{
    if(!(p=buscarNodoArbolBinBusq(p,d,cmp))) return 0;///No existe
    memcpy(d, (*p)->info, MINIMO(tam, (*p)->tamInfo));
    return 1;
}

tNodoArbol ** buscarNodoArbolBinBusq(const tArbolBinBusq *p, const void *d, int(*cmp)(const void*, const void *))
{
    int rc;
    while(*p && (rc=cmp(d, (*p)->info)))
    {
        if(rc<0)
            p=&(*p)->izq;
        else
            p=&(*p)->der;
    }
    if(!*p) return NULL;
    return (tNodoArbol **)p;
}

tNodoArbol ** buscarRecNodoArbolBinBusq(const tArbolBinBusq *p, const void *d, int (*cmp)(const void*, const void*))
{
    int rc;
    if(!*p) return NULL;
    if(*p && (rc=cmp(d, (*p)->info)))
    {
        if(rc<0)
            return buscarRecNodoArbolBinBusq(&(*p)->izq,d,cmp);
        return buscarRecNodoArbolBinBusq(&(*p)->der,d,cmp);
    }

    return (tNodoArbol **)p;
}

tNodoArbol ** mayorNodoArbolBinBusq(const tArbolBinBusq *p)
{
    if(!*p)
        return NULL;
    while((*p)->der)
        p= &(*p)->der;
    return (tNodoArbol **)p;
}

tNodoArbol ** menorNodoArbolBinBusq(const tArbolBinBusq *p)
{
    if(!*p)
        return NULL;
    while((*p)->izq)
        p=&(*p)->izq;
    return (tNodoArbol **)p;
}

tNodoArbol ** mayorRecNodoArbolBinBusq(const tArbolBinBusq *p)
{
    if(!*p)
        return NULL;
    if(!(*p)->der)
        return (tNodoArbol **)p;
    return mayorRecNodoArbolBinBusq(&(*p)->der);
}

tNodoArbol ** menorRecNodoArbolBinBusq(const tArbolBinBusq *p)
{
    if(!*p)
        return NULL;
    if(!(*p)->izq)
        return (tNodoArbol **)p;
    return menorRecNodoArbolBinBusq(&(*p)->izq);
}

unsigned alturaArbolBin(const tArbolBinBusq *p)
{
    int hi,hd;
    if(!*p) return 0;
    hi=alturaArbolBin(&(*p)->izq);
    hd=alturaArbolBin(&(*p)->der);
    return (hi>hd? hi : hd)+1;
}

///******************************************************
void recorrerEnOrdenRecArbolBinBusq(const tArbolBinBusq *p, unsigned n, void *params, void(*accion)(void*,unsigned, unsigned,void*))
{
    if(!*p)
        return;
    recorrerEnOrdenRecArbolBinBusq(&(*p)->izq, n+1,params,accion);
    accion((*p)->info, (*p)->tamInfo, n, params);
    recorrerEnOrdenRecArbolBinBusq(&(*p)->der, n+1,params,accion);
}

void recorrerEnOrdenArbolBinBusq(const tArbolBinBusq *p, void *params, void(*accion)(void*, unsigned, unsigned, void*))
{
    recorrerEnOrdenRecArbolBinBusq(p,0,params,accion);
}

void recorrerEnOrdenInversoRecArbolBinBusq(const tArbolBinBusq *p, unsigned n, void *params, void (*accion)(void*,unsigned,unsigned,void *))
{
    if(!*p)
        return;
    recorrerEnOrdenInversoRecArbolBinBusq(&(*p)->der,n+1,params,accion);
    accion((*p)->info, (*p)->tamInfo, n, params);
    recorrerEnOrdenInversoRecArbolBinBusq(&(*p)->izq,n+1,params,accion);
}


void recorrerEnOrdenInversoArbolBinBusq(const tArbolBinBusq *p, void *params, void(*accion)(void*, unsigned, unsigned, void*))
{
    recorrerEnOrdenInversoRecArbolBinBusq(p,0,params,accion);
}

void recorrerPreOrdenRecArbolBinBusq(const tArbolBinBusq *p, unsigned n, void *params, void(*accion)(void*, unsigned,unsigned, void*))
{
    if(!*p) return;
    accion((*p)->info, (*p)->tamInfo, n, params);
    recorrerPreOrdenRecArbolBinBusq(&(*p)->izq, n+1,params,accion);
    recorrerPreOrdenRecArbolBinBusq(&(*p)->der, n+1,params,accion);
}

void recorrerPreOrdenArbolBinBusq(const tArbolBinBusq *p, void *params, void(*accion)(void*,unsigned,unsigned,void*))
{
    recorrerPreOrdenRecArbolBinBusq(p,0,params,accion);
}

void recorrerPosOrdenRecArbolBinBusq(const tArbolBinBusq *p, unsigned n, void* params,void(*accion)(void*, unsigned, unsigned, void*))
{
    if(!*p) return;
    recorrerPosOrdenRecArbolBinBusq(&(*p)->izq,n+1,params,accion);
    recorrerPosOrdenRecArbolBinBusq(&(*p)->der,n+1,params,accion);
    accion((*p)->info,(*p)->tamInfo, n, params);
}

void recorrerPosOrdenArbolBinBusq(const tArbolBinBusq *p, void* params, void(*accion)(void*, unsigned, unsigned, void*))
{
    recorrerPosOrdenRecArbolBinBusq(p,0,params,accion);
}

void recorrerEnOrdenSimpleArbolBinBusq(const tArbolBinBusq*p, void* params, void(*accion)(void*, unsigned, void*))
{
    if(!*p)
        return;
    recorrerEnOrdenSimpleArbolBinBusq(&(*p)->izq, params,accion);
    accion((*p)->info, (*p)->tamInfo, params);
    recorrerEnOrdenSimpleArbolBinBusq(&(*p)->der, params,accion);
}

void recorrerPreOrdenSimpleArbolBinBusq(const tArbolBinBusq*p, void* params, void(*accion)(void*, unsigned, void*))
{
    if(!*p)
        return;
    accion((*p)->info, (*p)->tamInfo, params);
    recorrerPreOrdenSimpleArbolBinBusq(&(*p)->izq, params,accion);
    recorrerPreOrdenSimpleArbolBinBusq(&(*p)->der, params,accion);
}


void recorrerPosOrdenSimpleArbolBinBusq(const tArbolBinBusq*p, void* params, void(*accion)(void*, unsigned, void*))
{
    if(!*p)
        return;
    recorrerPosOrdenSimpleArbolBinBusq(&(*p)->izq, params,accion);
    recorrerPosOrdenSimpleArbolBinBusq(&(*p)->der, params,accion);
    accion((*p)->info, (*p)->tamInfo, params);
}

///***********************************************************************

int mayorElemNoClaveArbolBinBusq(const tArbolBinBusq *p, void *d, unsigned tam, int(*cmp)(const void*, const void*))
{
    const tArbolBinBusq *mayor=p;
    if(!*p)
        return 0;
    mayor= mayorNodoNoClaveArbolBinBusq(&(*p)->izq, mayor,cmp);
    mayor= mayorNodoNoClaveArbolBinBusq(&(*p)->der, mayor,cmp);

    memcpy(d, (*mayor)->info, MINIMO(tam,(*mayor)->tamInfo));
    return 1;
}

const tArbolBinBusq * mayorNodoNoClaveArbolBinBusq(const tArbolBinBusq *p, const tArbolBinBusq *mayor, int (*cmp)(const void*,const void*))
{
    if(!*p) return mayor;
    if(cmp((*p)->info, (*mayor)->info)>0)
        mayor=p;
    mayor=mayorNodoNoClaveArbolBinBusq(&(*p)->izq,mayor,cmp);
    mayor=mayorNodoNoClaveArbolBinBusq(&(*p)->der,mayor,cmp);
    return mayor;
}

int menorElemNoClaveArbolBinBusq(const tArbolBinBusq *p, void *d, unsigned tam, int(*cmp)(const void*, const void*))
{
    const tArbolBinBusq *menor=p;
    if(!*p)
        return 0;
    menor= menorNodoNoClaveArbolBinBusq(&(*p)->izq, menor,cmp);
    menor= menorNodoNoClaveArbolBinBusq(&(*p)->der, menor,cmp);

    memcpy(d, (*menor)->info, MINIMO(tam,(*menor)->tamInfo));

    return 1;
}

const tArbolBinBusq * menorNodoNoClaveArbolBinBusq(const tArbolBinBusq *p, const tArbolBinBusq *menor, int (*cmp)(const void*,const void*))
{
    if(!*p) return menor;
    if(cmp((*p)->info, (*menor)->info)<0)
        menor=p;
    menor=menorNodoNoClaveArbolBinBusq(&(*p)->izq,menor,cmp);
    menor=menorNodoNoClaveArbolBinBusq(&(*p)->der,menor,cmp);
    return menor;
}

int buscarElemNoClaveArbolBinBusq(const tArbolBinBusq *p, void *d, unsigned tam, int (*cmp)(const void*, const void*))
{
    const tArbolBinBusq *busq= NULL;
    if(!*p) return 0;
    if(cmp((*p)->info,d)==0)
        busq=p;
    else if((busq = buscarNodoNoClaveArbolBinBusq(&(*p)->izq,d,cmp))==NULL)
    {
        busq=buscarNodoNoClaveArbolBinBusq(&(*p)->der,d, cmp);
    }
    if(busq==NULL) return 0;

    memcpy(d,(*busq)->info, MINIMO(tam, (*busq)->tamInfo));

    return 1;
}

const tArbolBinBusq* buscarNodoNoClaveArbolBinBusq( const tArbolBinBusq *p, const void* d, int (*cmp)(const void*, const void*))
{
    const tArbolBinBusq *busq=NULL;
    if(!*p) return NULL;
    if(cmp((*p)->info,d)<0)
        return p;
    if((busq=buscarNodoNoClaveArbolBinBusq(&(*p)->izq,busq,cmp)))
        return busq;
    return buscarNodoNoClaveArbolBinBusq(&(*p)->der,busq,cmp);
}


///**********************************************************************

unsigned cantNodosArbolBin(const tArbolBinBusq *p)
{
    if(!*p) return 0;
    return cantNodosArbolBin(&(*p)->izq) + cantNodosArbolBin(&(*p)->der) +1 ;
}


int mayorElemArbolBinBusq(const tArbolBinBusq *p, void *d, unsigned tam)
{
    if(!(p=mayorNodoArbolBinBusq(p)))
        return 0;
    memcpy(d, (*p)->info, MINIMO(tam,(*p)->tamInfo));
    return 1;
}

int menorElemArbolBinBusq(const tArbolBinBusq *p, void *d, unsigned tam)
{
     if(!(p=menorNodoArbolBinBusq(p)))
        return 0;
    memcpy(d, (*p)->info, MINIMO(tam,(*p)->tamInfo));
    return 1;
}

unsigned cantNodosHastaNivelArbonBin(const tArbolBinBusq *p, int n)
{
    if(!*p) return 0;
    if(n==0) return 1;
    return cantNodosHastaNivelArbonBin(&(*p)->izq, n-1) + cantNodosHastaNivelArbonBin(&(*p)->der, n-1) + 1;
}

int esCompletoHastaNivelArbolBin(const tArbolBinBusq *p, int n)
{
    if(!*p) return n<0;
    if(n==0) return 1;
    return esCompletoHastaNivelArbolBin(&(*p)->izq,n-1) && esCompletoHastaNivelArbolBin(&(*p)->der,n-1);
}

int esCompletoArbolBin(const tArbolBinBusq *p)
{
    return esCompletoHastaNivelArbolBin(p,alturaArbolBin(p)-1);
}

int esBalanceadoArbolBin(const tArbolBinBusq *p)
{
    return esCompletoHastaNivelArbolBin(p,alturaArbolBin(p)-2);
}

int esAVLArbolBin(const tArbolBinBusq *p)
{
    int hi,hd;
    if(!*p) return 1;
    hi=alturaArbolBin(&(*p)->izq);
    hd=alturaArbolBin(&(*p)->der);
    if(abs(hi-hd)>1)
        return 0;
    return esAVLArbolBin(&(*p)->izq) && esAVLArbolBin(&(*p)->der);
}

int esCompleto2ArbolBin(const tArbolBinBusq *p)
{
    int h=alturaArbolBin(p);
    return cantNodosArbolBin(p)== pow(2,h)-1;
}

int esBalanceado2ArbolBin(const tArbolBinBusq *p)
{
    int h=alturaArbolBin(p);
    return cantNodosHastaNivelArbonBin(p,h-2)== pow(2,h-1)-1;
}

int esAVL2CalculoArbolBin(const tArbolBinBusq *p)
{
    int hi, hd;
    if(!*p) return 0;
    hi=esAVL2CalculoArbolBin(&(*p)->izq);
    hd=esAVL2CalculoArbolBin(&(*p)->der);
    if(hi<0 || hd<0 || abs(hi-hd)>1)
        return -1;
    return (hi>hd? hi : hd)+1;
}

int esAVL2ArbolBin( const tArbolBinBusq *p)
{
    return esAVL2CalculoArbolBin(p)>=0;
}

void imprimirConForma(void * info, unsigned tam, unsigned n, void* params)
{
    int *i=(int*)info;
    printf("%*s-%3d-\n",n*3,"",*i);
}

void imprimir(void *info, unsigned tam, unsigned n, void* params)
{
    int *i=(int*) info;
    printf("-%d-", *i);
}

unsigned leerDesdeVectorEnteros(void** d, void *vec, unsigned pos, void * params)
{
    *d=malloc(sizeof(int));
    if(!*d) return 0;
    memcpy(*d, vec+(sizeof(int)*pos), sizeof(int));
    return sizeof(int);
}

int cmp_ent(const void *v1 , const void* v2)
{
    return *((int*)v1)- *((int*)v2);
}

