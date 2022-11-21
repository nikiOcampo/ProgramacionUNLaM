#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

int main()
{
    ///prueba de primitivas del TDA ARBOL BINARIO DE BUSQUEDA

    tArbolBinBusq ar;
    int vec[]={10,25,50,60,75,100,110,125,150,175,200};
    //int vec[]={25,50,75,100,125,150,175};
    int dato;

    crearArbolBinBusq(&ar);

    cargarDesdeDatosOrdenadosArbolBinBusq(&ar,vec,sizeof(vec)/sizeof(int),leerDesdeVectorEnteros,NULL);

    ///eliminarRaizArbolBinBusq(&ar);

    printf("Impresion EN ORDEN:\n");
    recorrerEnOrdenArbolBinBusq(&ar,NULL,imprimir);
    printf("\n\n");
    printf("Impresion EN PRE ORDEN:\n");
    recorrerPreOrdenArbolBinBusq(&ar,NULL,imprimirConForma);
    printf("\n\n");
    printf("Impresion EN POS ORDEN:\n");
    recorrerPosOrdenArbolBinBusq(&ar,NULL,imprimir);
    printf("\n\n");
    printf("Impresion EN ORDEN INVERSO:\n");
    recorrerEnOrdenInversoArbolBinBusq(&ar,NULL,imprimir);

    printf("\n\n");
    if(esCompletoArbolBin(&ar))
        printf("\nEs completo");
    if(esBalanceadoArbolBin(&ar))
        printf("\nEs Balanceado");
    if(esAVLArbolBin(&ar))
        printf("\nEs AVL");

    printf("\n\n");
    if(esCompleto2ArbolBin(&ar))
        printf("\n2-Es completo");
    if(esBalanceado2ArbolBin(&ar))
        printf("\n2-Es Balanceado");
    if(esAVL2ArbolBin(&ar))
        printf("\n2-Es AVL");

    mayorElemNoClaveArbolBinBusq(&ar,&dato,sizeof(dato), cmp_ent);
    printf("\n\n Mayor No Clave: %d", dato);

    menorElemNoClaveArbolBinBusq(&ar,&dato,sizeof(dato), cmp_ent);
    printf("\n\n Menor No Clave: %d", dato);

    eliminarElemArbolBinBusq(&ar,&dato,sizeof(dato),cmp_ent);
     printf("\n\nImpresion EN ORDEN sin el menor:\n");
    recorrerEnOrdenArbolBinBusq(&ar,NULL,imprimir);

    return 0;
}
