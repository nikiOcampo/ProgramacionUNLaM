#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modelo.h"
//
//typedef struct
//{
//    char nroPedido[6];
//    char codProd[7];
//    int cantPedida;
//}t_pedidos;

//typedef struct
//{
//    char codProd[7];
//    char descrpcion[22];
//    int stock;
//}t_stock;

int crearArchivoStock(FILE *archivo)
{
    int crear;
    t_stock productos[]= {
            {1,"martillo",10},
            {3,"tornillo",20},
            {4,"pala",10},
            {5,"destornillador",30},
            {6,"clavo",5},
            {8,"tuerca",6},
            {9,"llave",3},
            {10,"caja",2},
            {11,"pinza",10},
            {12,"cinta",10},
            {13,"alicate",10},
            {14,"cuter",10},
            {15,"sierra",10}
    };
    archivo=fopen("productos.dat", "wb");
    if(!archivo)
        crear=0;
    else
        crear=1;
    fwrite(&productos,sizeof(t_stock),14,archivo);
    fclose(archivo);
    return crear;

}



int leerArchivoPedidos(FILE *arch_pedidos,t_pedidos *pedido)
{
    int leer=0;
    leer=fscanf(arch_pedidos,"%3d%8[^\n]%d",&pedido->nroPedido, &pedido->codProd, &pedido->cantPedida);
    return leer;
}


void crearCola(tCola *pc)
{
    pc->pri=pc->ult=NULL;
}

int ponerEnCola(tCola *pc, void *pd, unsigned tam)
{
    tNodo *nue;
    nue=(tNodo*)malloc(sizeof(tNodo));
    if(!nue) return 0; // sin memoria
    nue->info=malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return 0;
    }
    nue->tam=tam;
    memcpy(nue->info,pd,tam);
    nue->sig=NULL;
    if(pc->ult)
        pc->ult->sig=nue;
    else
        pc->pri=nue;
    pc->ult=nue;

    return 1;
}

int sacarDeCola(tCola *pc, void *pd, unsigned tam)
{
    tNodo *elim=pc->pri;
    if(!elim) return 0; //cola vacia
    memcpy(pd, elim->info,MINIMO(tam, elim->tam));
    pc->pri=elim->sig;
    if(!pc->pri)
        pc->ult=NULL;
    free(elim->info);
    free(elim);
    return 1;
}


