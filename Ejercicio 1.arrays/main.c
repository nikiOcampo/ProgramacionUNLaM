#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"
#include <string.h>

#define TAM 10

int main()
{
    //EJERCICIO 22
    //Desarrollar una función que inserte un elemento en un arreglo de enteros, dada la posición de inserción.
   /* int num, posicion, vector[TAM]={1,2,3,4,5}, r;
    printf("Ingrese el numero que desea guardar en el array: ");
    scanf("%d", &num);
    printf("Ingrese la posicion en la que desea guardar ese numero (entre 1 y 10): ");
    scanf("%d", &posicion);
    r=insertarEnArreglo(posicion,num,vector,5);
    if(r==0)
    {
      printf("\nNo se pudo agregar el numero solicitado en dicha posicion");
    }
    else
    {
        printf("\nEl numero se inserto con exito!!");
        mostrarVector(vector);
    }
*/

    //Desarrollar una función que inserte un elemento en un arreglo de enteros, orde- nado en forma ascendente, de forma de no alterar el orden.
    /*int num, vector[TAM]={1,5,7,12,15,20},r;
    printf("Ingrese el numero que quiere poner en el vector: ");
    scanf("%d", &num);
    r=insertaSinDesordenar(num,vector,6);
    if(r==0)
    {
      printf("\nNo se pudo agregar el numero solicitado en dicha posicion");
    }
    else
    {
        printf("\nEl numero se inserto con exito!!");
        mostrarVector(vector);
    }*/

    //EJERCICIO 24
    /*int pos, vect[TAM]={41,56,25,12,4,45,15};
    mostrarVector(vect);
    printf("\nIngrese la posicion del numero que desea borrar del vector: ");
    scanf("%d", &pos);
    eliminarDetPos(pos,vect,6);*/


    //EJERCICIO 25
   /* int num, vect[TAM]={10,15,25,78,69,35,20,15};
    mostrarVector(vect);
    printf("\nIngrese el numero que decia eliminar del vector: ");
    scanf("%d",&num);
    elminarDetElem(num,vect,8);*/

    //EJERCICIO 26
   /* int num, vect[TAM]={10,15,25,78,78,20,15,10,20},ce;
    mostrarVector(vect,9);
    printf("\nIngrese el elemento que desea eliminar del vector: ");
    scanf("%d",&num);
    ce=eliminarTotElem(num,vect,9);
    mostrarVector(vect,ce);
*/

    //EJERCICIO 27
    //Desarrollar una función que determine si una cadena de caracteres es un palín- dromo.

    char palabra[31],palabraSinEspacios[31]={};
    int palindromo;
    do{
        printf("Ingrese una palabra: ");
        fflush(stdin);
        gets(palabra);
    }while(strlen(palabra)<1||strlen(palabra)>30);
    eliminaEspacios(palabra,palabraSinEspacios,strlen(palabra));
    palindromo=esPalindromo(palabraSinEspacios,strlen(palabraSinEspacios));
    if(palindromo==1)
    {
        printf("La palabra ingresada es PALINDROMO");
    }
    else
    {
        printf("La palabra ingresada NO ES PALINDROMO");
    }


    //EJERCICIO 28
    /*char numero[6];
    int num;
    do{
        printf("Ingrese un numero: ");
        fflush(stdin);
        gets(numero);
    }while(strlen(numero)<1||strlen(numero)>30);
    num=deStringAInt(numero,strlen(numero));
    printf("El numero ingresado fue:" );
    printf("\n%d", num);*/
    return 0;
}
