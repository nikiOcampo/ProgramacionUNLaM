#include <tipos.h>
#include <stdio.h>
#include <stdlib.h>
#include <arbol.h>
#include "utilitarias.h"

void crearArbolBinBusq(tArbolBinBusq *p)
{
    *p=NULL;
}


void vaciarArbolBin(tArbolBinBusq *p)
{
    if(!*p) return;
    vaciarArbolBin(&(*p)->izq);
    vaciarArbolBin(&(*p)->der);
    free((*p)->info);
    free(*p);
    *p=NULL;
}

int cargarDesdeArchivoPreOrdenArbol(tArbolBinBusq * p, const char * path, unsigned tamInfo,int (*cmp)(const void *, const void *))
{
    void* dato=malloc(tamInfo);
    FILE *pf=fopen(path,"rb");
    if(!pf) return 0;
    fread(dato, tamInfo,1,pf);
    while(!feof(pf))
    {
        insertarRecArbolBinBusq(p,dato,tamInfo,cmp);
        //insertarArbolBinBusq_res(p,dato,tamInfo,cmp);
//        if(!r)
//        {
//            free(dato);
//            fclose(pf);
//            return 0;
//        }
        fread(dato, tamInfo,1,pf);
    }
    fclose(pf);
    free(dato);

    return TODO_OK;
}


int cargarArchivoBinOrdenadoArbolBinBusq(tArbolBinBusq * p, const char * path,unsigned tamInfo)
{
    int r, ls;
    FILE *pf= fopen(path,"rb");
    if(!pf) return 0;
    fseek(pf,0L,SEEK_END);
    ls=ftell(pf)/tamInfo;
    r=cargarDesdeDatorOrdenadosRec(p,pf,tamInfo,0,ls-1);
    fclose(pf);
    return r;
}

int cargarDesdeDatorOrdenadosRec(tArbolBinBusq *p, FILE *pf, unsigned tamInfo, int li, int ls)
{
    int m=(li+ls)/2,r;
    if(li>ls) return 1;
    *p=(tNodoArbol*)malloc(sizeof(tNodoArbol));
    if(!p || ((*p)->info=malloc(tamInfo))==NULL)
    {
        free(*p);
        return 0;
    }
    (*p)->izq=(*p)->der=NULL;

    (*p)->tamInfo=tamInfo;
    fseek(pf,(long)m*tamInfo,SEEK_SET);
    fread((*p)->info,tamInfo,1,pf);

    r=cargarDesdeDatorOrdenadosRec(&(*p)->izq,pf,tamInfo,li,m-1);
    if(r!=TODO_OK) return r;
    return cargarDesdeDatorOrdenadosRec(&(*p)->der,pf,tamInfo,m+1,ls);

}

int insertarRecArbolBinBusq(tArbolBinBusq *p, const void *d, unsigned tam,int (*cmp)(const void *, const void *))
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

    return TODO_OK;

}

int grabarEnArchivoOrdenadoArbolBin(tArbolBinBusq *p, const char *path)
{
    FILE *pf= fopen(path,"wb");
    if(!pf) return 0;
    recorrerEnOrdenSimpleArbolBinBusq_res(p,pf,escribir_archivo);
    fclose(pf);

    return TODO_OK;

}


int grabarEnArchivoPreOrdenadoArbolBin(tArbolBinBusq *p, const char * path)
{
    FILE *pf=fopen(path,"wb");
    if(!pf) return 0;
    recorrerPreOrdenSimpleArbolBinBusq_res(p,pf,escribir_archivo);
    fclose(pf);
    return TODO_OK;
}


int eliminarElemArbolBinBusq(tArbolBinBusq *p, void *d, unsigned tam,int (*cmp)(const void *, const void *))
{
    if(!(p=buscarRecNodoArbolBinBusq(p,d,cmp))) return NO_EXISTE;
    memcpy(d, (*p)->info, MINIMO(tam, (*p)->tamInfo));
    return eliminarRaizArbolBinBusq(p);
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
        return TODO_OK;
    }

    remp=alturaArbolBin(&(*p)->izq)>alturaArbolBin(&(*p)->der)?
        mayorRecNodoArbolBinBusq(&(*p)->izq): menorRecNodoArbolBinBusq(&(*p)->der);

    elim=*remp;
    (*p)->info= elim->info;
    (*p)->tamInfo=elim->tamInfo;

    *remp=elim->izq? elim->izq: elim->der;
    free(elim);

    return TODO_OK;
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



int buscarElemArbolBinBusq(const tArbolBinBusq *p, void *d, unsigned tam, int(*cmp)(const void*, const void*))
{
    if(!(p=buscarRecNodoArbolBinBusq(p,d,cmp))) return 0;///No existe
    memcpy(d, (*p)->info, MINIMO(tam, (*p)->tamInfo));
    return 1;
};


void arbolGrafico(const tArbolBinBusq *p, void(*mostrar)(const void *))
{
    recorrerEnOrdenInversoArbolBinBusq(p,NULL,mostrar);
}

void recorrerEnOrdenInversoArbolBinBusq(const tArbolBinBusq *p, void *params, void(*accion)(const void*))
{
    recorrerEnOrdenInversoRecArbolBinBusq(p,0,params,accion);
}

void recorrerEnOrdenInversoRecArbolBinBusq(const tArbolBinBusq *p, unsigned n, void *params, void (*accion)(const void*))
{
    if(!*p)
        return;
    int h=alturaArbolBin(p);
    recorrerEnOrdenInversoRecArbolBinBusq(&(*p)->der,n+1,params,accion);
    printf("\n%*s",(h-5)*3," ");
    accion((*p)->info);
    recorrerEnOrdenInversoRecArbolBinBusq(&(*p)->izq,n+1,params,accion);
}



