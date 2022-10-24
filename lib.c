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

int myStrlen(const char *s)
{
    int cont=0;
    while(*s)
    {
        cont++;
        s++;
    }
    return cont;
}

/*char *myStrcpy(const char *s1, char *s2)
{
    char *aux= s2;
    while(*s1)
    {
        *s2= *s1;
        s1++;
        s2++;
    }
    *s2= '/0';
    return aux;
}*/

char *myStrchr(char *s, int c)
{
    while(*s)
    {
        if(*s==c)
        {
            return s;
        }
        s++;
    }
    return NULL;

}






