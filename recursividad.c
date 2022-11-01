#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "recursividad.h"

void ejercicio1A(char *cad)
{
    if(*cad=='\0')
        return;
    else
    {
        printf("%c", *cad);
        cad++;
        ejercicio1A(cad);
    }
}

void ejercicio1B(char *cad)
{
    if(*cad=='\0')
        return;
    else
    {
        cad++;
        ejercicio1B(cad);
    }
    printf("%c", *(cad-1));

}

void ejercicio1C(char *cad)
{
    ejercicio1A(cad);
    ejercicio1B(cad);
}


void ejercicio1D(char *cad)
{
    if(*cad=='\0')
        return;
    else
    {
        printf("%c", *cad);
        ejercicio1D(cad+1);
    }
    printf("%c", *(cad-1));
}


void ejercicio1E(char *cad)
{
    if(*cad=='\0')
        return;
    printf("%c", *cad);//abcd
    cad++;
    ejercicio1E(cad);

}


void ejercicio2A(int num)
{
    if(!num)
        return;
    ejercicio2A(num/10);
    printf("%d", num%10);
}

void ejercicio2B(int num)
{
    if(!num)
        return;
    printf("%d", num%10);
    ejercicio2A(num/10);
}

void ejercicio2D(int num,int div)
{
    if(!num) return;
    printf("\n%d",num);
    ejercicio2D(num % (int)pow(10,div),div-1);
}

void ejercicio2E(int num,int div)
{
    if(!num) return;
    ejercicio2E(num % (int)pow(10,div),div-1);
    printf("\n%d",num);
}

void ejercicio2G(int num)
{
    if(!num) return;
    ejercicio2G(num/10);
    printf("\n%d", num);
}


void ejercicio2H(int num)
{
    if(!num) return;
    printf("\n%d", num);
    ejercicio2H(num/10);
}

int ejercicio3MCD(int num1,int num2)
{
    int resultado;
    if(!num1) resultado=num2;
    if(!num2) resultado=num1;
    if(!num1 || !num2 ) return resultado;
    ejercicio3MCD(num2, num1%num2);
}

void ejercicio4Fibonacci(int a, int b)
{
    if(a==21)
        return;
    printf("-%d-",a);
    ejercicio4Fibonacci(b,a+b);
}

int ejercicio6Palindromo(char *cad,int ce)
{
    int esPalindromo=0;
    if(*cad!=*(cad+ce-1))
        esPalindromo=0;
    else
    {
        ejercicio6Palindromo(cad+1,ce-1);
        esPalindromo=1;
    }
    return esPalindromo;
}


