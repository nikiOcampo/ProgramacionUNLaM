#include <stdio.h>
#include <stdlib.h>
#include "recursividad.h"

int main()
{
    //char *cad="abcd";
    //ejercicio1A(cad);
    //ejercicio1B(cad);
    //ejercicio1C(cad);
    //ejercicio1D(cad);
    //ejercicio1E(cad);
//    int num=1234;
//    ejercicio2A(num);
//    ejercicio2B(num);
//    ejercicio2D(num,3);
//    ejercicio2E(num,3);
//    ejercicio2G(num);
//    ejercicio2H(num);

//    int mcd;
//    mcd=ejercicio3MCD(270,192);
//    printf("%d", mcd);

    //ejercicio4Fibonacci(0,1);

    char *cad="somos";
    int esPalindromo= ejercicio6Palindromo(cad,5);
    esPalindromo==1? printf("Es palindromo"): printf("No es palindromo");
    return 0;
}
