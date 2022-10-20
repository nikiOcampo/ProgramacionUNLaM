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
//          - 1: CORRECTO - La funci�n se ha ejecutado sin errores.
int ponerEnPila(t_Pila *pp, const void *pd, unsigned tam)
{
    // Declaraci�n del nuevo tope.
    tNodo *nue= (tNodo*) malloc (sizeof(tNodo));
    // En caso de que no se haya podido asignar memoria, salir de la funci�n.
    if(!nue)
        return PILA_LLENA;
    // Asignar un espacio de memoria espec�fico para el dato.
    nue->info= malloc(tam);

    // En caso de que no se haya podido asignar memoria, salir de la funci�n.
    if(!nue->info)
    {
        // Antes de salir, libero el nodo que cre� anteriormente.
        free(nue);
        return PILA_LLENA;
    }
    // Incorporaci�n de informaci�n
    nue->tamInfo= tam; // Asignar el tama�o a leer.
    nue->sig= *pp; // Asignar la D.R.O del �ltimo nodo.
    memcpy(nue->info, pd, tam);  // Copiar el dato.

    // Asignar al puntero "Tope de Pila" donde se encuentra el primer nodo
    *pp=nue;
    return OK;
}
// Retorna:
//          - 0: ERROR - Algo ha ocurrido durante el proceso.
//          - 1: CORRECTO - La funci�n se ha ejecutado sin errores.
int sacarDePila(t_Pila *pp, void *pd, unsigned tam)
{
    // Declaraci�n de un nodo temporal para permitir desasignar un elemento.
    tNodo *elem= *pp;
    // Si el "tope de la pila" contiene la direcci�n nula, no hay nada que
    // quitar.
    if(!*pp)
    {
        return PILA_LLENA;
    }
    // Asignar al dato pedido a la variable dada por par�metro.
    // Se utiliza la macro "MINIMO" para determinar el tama�o especifico a
    // tomar para no generar un estilo de "overflow" dentro de la memoria.
    memcpy(pd,elem->info,MINIMO(elem->tamInfo,tam));
    // Asignar la D.R.O del nodo anterior al que se eliminar�,
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
//          - 1: CORRECTO - La funci�n se ha ejecutado sin errores.
int verTopePila(t_Pila *pp, void *pd, unsigned tam)
{
    // Si el "tope de la pila" contiene la direcci�n nula, no hay nada que
    // mostrar.
    if(!*pp)
        return PILA_LLENA;
    // Se utiliza la macro "MINIMO" para determinar el tama�o especifico a
    // tomar para no generar un estilo de "overflow" dentro de la memoria.
    memcpy(pd,(*pp)->info, MINIMO((*pp)->tamInfo,tam));
    return OK;
}

void vaciarPila(t_Pila *pp)
{
     // Mientras que el "Tope de Pila" contenga una direcci�n de memoria no nula
    while(*pp)
    {
        // Se utilizar� un nodo auxiliar para asignar la D.R.O del siguiente
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
//          - 1: CORRECTO - La funci�n se ha ejecutado sin errores.
int pilaLlena(const t_Pila *pp, unsigned tam)
{
    void* vnodo = malloc(sizeof(tNodo));
    void * vinfo= malloc(tam);
    // Liberar memoria alojada temporalmente
    free(vnodo);
    free(vinfo);
    // En caso de que haya podido asignarse memoria, las variables vnodo y vinfo
    // tendran una direcci�n de memoria en ellas. Por lo tanto, el retorno ser�
    // negativo. En cambio, si alguna de ellas no pudo se "allocada" tendr� en
    // si una direcci�n NULL, devolviendo un positivo.
    return (!vnodo || !vinfo);
}

//Pila vac�a
// Retorna:
//          - 0: Si la pila aun contiene elementos dentro de si
//          - 1: Si la pila est� vac�a.
int pila_vacia(t_Pila *pp)
{
    return *pp == NULL;
}
