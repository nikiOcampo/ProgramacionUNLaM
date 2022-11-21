#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "Pila.h"

void crearPila(t_Pila *pp)
{
    *pp= NULL;
}
// Retorna:
//          - 0: ERROR - Algo ha ocurrido durante el proceso.
//          - 1: CORRECTO - La función se ha ejecutado sin errores.
int ponerEnPila(t_Pila *pp, const void *pd, unsigned tam)
{
    // Declaración del nuevo tope.
    tNodo *nue= (tNodo*) malloc (sizeof(tNodo));
    // En caso de que no se haya podido asignar memoria, salir de la función.
    if(!nue)
        return PILA_LLENA;
    // Asignar un espacio de memoria específico para el dato.
    nue->info= malloc(tam);

    // En caso de que no se haya podido asignar memoria, salir de la función.
    if(!nue->info)
    {
        // Antes de salir, libero el nodo que creé anteriormente.
        free(nue);
        return PILA_LLENA;
    }
    // Incorporación de información
    nue->tamInfo= tam; // Asignar el tamaño a leer.
    nue->sig= *pp; // Asignar la D.R.O del último nodo.
    memcpy(nue->info, pd, tam);  // Copiar el dato.

    // Asignar al puntero "Tope de Pila" donde se encuentra el primer nodo
    *pp=nue;
    return OK;
}
// Retorna:
//          - 0: ERROR - Algo ha ocurrido durante el proceso.
//          - 1: CORRECTO - La función se ha ejecutado sin errores.
int sacarDePila(t_Pila *pp, void *pd, unsigned tam)
{
    // Declaración de un nodo temporal para permitir desasignar un elemento.
    tNodo *elem= *pp;
    // Si el "tope de la pila" contiene la dirección nula, no hay nada que
    // quitar.
    if(!*pp)
    {
        return PILA_LLENA;
    }
    // Asignar al dato pedido a la variable dada por parámetro.
    // Se utiliza la macro "MINIMO" para determinar el tamaño especifico a
    // tomar para no generar un estilo de "overflow" dentro de la memoria.
    memcpy(pd,elem->info,MINIMO(elem->tamInfo,tam));
    // Asignar la D.R.O del nodo anterior al que se eliminará,
    // al puntero "Tope de Pila".

    // De esta manera, no perdemos el "hilo conductor".
    *pp= elem->sig;
    // Liberar las memorias correspondientes.
    free(elem->info);
    free(elem);

    return OK;
}
// Retorna:
//          - 0: ERROR - Algo ha ocurrido durante el proceso.
//          - 1: CORRECTO - La función se ha ejecutado sin errores.
int verTopePila(t_Pila *pp, void *pd, unsigned tam)
{
    // Si el "tope de la pila" contiene la dirección nula, no hay nada que
    // mostrar.
    if(!*pp)
        return PILA_LLENA;
    // Se utiliza la macro "MINIMO" para determinar el tamaño especifico a
    // tomar para no generar un estilo de "overflow" dentro de la memoria.
    memcpy(pd,(*pp)->info, MINIMO((*pp)->tamInfo,tam));
    return OK;
}

void vaciarPila(t_Pila *pp)
{
     // Mientras que el "Tope de Pila" contenga una dirección de memoria no nula
    while(*pp)
    {
        // Se utilizará un nodo auxiliar para asignar la D.R.O del siguiente
        // elemento en el puntero "Tope de Pila".
        tNodo *aux=*pp;
        *pp=aux->sig;
        // Libera el espacio en memoria asignado para la variable auxiliar.
        free(aux->sig);
        free(aux);
    }
}

// Retorna:
//          - 0: ERROR - Algo ha ocurrido durante el proceso.
//          - 1: CORRECTO - La función se ha ejecutado sin errores.
int pilaLlena(const t_Pila *pp, unsigned tam)
{
    void* vnodo = malloc(sizeof(tNodo));
    void * vinfo= malloc(tam);
    // Liberar memoria alojada temporalmente
    free(vnodo);
    free(vinfo);
    // En caso de que haya podido asignarse memoria, las variables vnodo y vinfo
    // tendran una dirección de memoria en ellas. Por lo tanto, el retorno será
    // negativo. En cambio, si alguna de ellas no pudo se "allocada" tendrá en
    // si una dirección NULL, devolviendo un positivo.
    return (!vnodo || !vinfo);
}

//Pila vacía
// Retorna:
//          - 0: Si la pila aun contiene elementos dentro de si
//          - 1: Si la pila está vacía.
int pila_vacia(t_Pila *pp)
{
    return *pp == NULL;
}
