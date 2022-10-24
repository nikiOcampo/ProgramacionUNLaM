#include <stdio.h>
#include <stdlib.h>
#include "lib.h"


///Crear una función que concatene 2 cadenas de caracteres similar a strcat, pero con la particularidad de
///que, debiendo seguir concatenando en la cadena1, debe poner la cadena 2 por delante.
///Ej:
///cad1 = “mundo!” cad2 = “Hola ”
///strrcat_mio(cad1, cad2);
///Resultado: cad1 => “Hola mundo!”


char* strcat_mio(char * cad1,char *cad2)
{
    char *aux = cad2;

    while(*cad2 != '\0')
    {
        cad2++;
    }

    while(*cad1 != '\0')
    {
        *cad2 = *cad1;
        cad2++;
        cad1++;
    }

    *cad2= '\0';
    return aux;
}
