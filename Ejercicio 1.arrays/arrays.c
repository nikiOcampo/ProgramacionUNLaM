#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"
#include <string.h>
#include <math.h>

#define TAM 10

//Desarrollar una función que inserte un elemento en un arreglo de enteros, dada la posición de inserción.
int insertarEnArreglo(int pos, int num, int vect[],int cantElem)
{
    if(cantElem==TAM)
        return 0;
    if(pos>cantElem+1)
        return 0;
    while(cantElem>pos-1)
    {
        vect[cantElem]=vect[cantElem-1];
        cantElem--;
    }
    vect[cantElem]=num;
    return 1;
}

int insertaSinDesordenar(int num, int vect[],int ce)
{
    int i=0,r;
    while(num>vect[i])
    {
        i++;
    }
    r=insertarEnArreglo(i+1,num,vect,ce);
    if(r==1)
        return 1;
    else
        return 0;
}


void mostrarVector(const int *vect,int ce)
{
    int i;
    printf("\n\n");
    for(i=0;i<ce;i++)
    {
        printf("%d\t",*vect);
        vect++;
    }
}

//Desarrollar una función que elimine el elemento que ocupa una determinada po- sición de un arreglo de enteros.
void eliminarDetPos(int pos, int vect[],int cantElem) //4// //7
{
    int *p=vect;//guarda la primera direccion de memoria
    p+=pos-1;//guarda la direccion de memoria del elemento 4
    while(pos<cantElem)
    {
        *p=*(p+1);
        pos++;
        p++;
    }
    *p=0;
    //mostrarVector(vect,cantElem);
}

//Desarrollar una función que elimine la primera aparición de un elemento deter- minado de un arreglo de enteros.
void elminarDetElem(int elem, int vect[], int ce)
{
    int *p=vect,i=0;
    while(*p!=elem && i<TAM)
    {
        p++;
        i++;
    }
    i++;
    eliminarDetPos(i,vect,ce);
}

//Desarrollar una función que elimine todas las apariciones de un determinado elemento de un arreglo de enteros.
int eliminarTotElem(int elem, int vect[],int ce)
{
    int *p=vect,i;
    for(i=0;i<=ce;i++)
    {
        if(*p==elem){
            elminarDetElem(elem,vect,ce);
            ce--;
        }else{
            p++;
        }
    }
    return ce;
}


//Desarrollar una función que determine si una cadena de caracteres es un palín- dromo.
int esPalindromo(char *palabra, int cantletras)
{
    int i, ce=cantletras-1;
    for(i=0;i<cantletras;i++)
    {
        if(*(palabra+i) == *(palabra+ce))
        {
            ce--;
        }
        else
        {
            return 0;
            break;
        }
    }
    return 1;

}


void eliminaEspacios(char *palabra, char *palabraSinEspacios,int cl)
{
    int i;
    for(i=0;i<cl;i++)
    {
        if(*palabra!=' ')//SOMOS O NO SOMOS
        {
            *palabraSinEspacios=*palabra;
            palabraSinEspacios++;
        }
        palabra++;

    }

}

//Desarrollar una función que devuelva el valor numérico de una cadena de carac- teres (asumiendo que los caracteres representan dígitos).
int deStringAInt(char *palabra, int cl)
{
    int i,num=0;
    palabra+=cl-1; //se para en la ultima posicion
    for(i=0;i<cl;i++)
    {

        num+=((*palabra)-48)*pow(10,i);
        palabra--;
    }
    return num;
}




void ordenar(int vect[])
{
    int i, aux,j;
    int *p;
    p=vect;
    for (i=0;i<TAM;i++) {
        for (j=i+1;j<TAM;j++) {
            if (*(p+j) < *(p+i)) {
                aux= *(p+i);
                *(p+i)= *(p+j);
                *(p+j)=aux;
            }
        }
    }
    mostrarVector(vect,TAM);
}
