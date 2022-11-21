#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"


/*Desarrollar una función para que, dada una matriz cuadrada de reales de orden N, obtenga la
sumatoria de los elementos que están por encima de la diagonal princi -
pal (excluida ésta). Lo mismo para la diagonal secundaria. Lo mismo incluyendo la diagonal.
 Lo mismo, con los que están por debajo de la diagonal.*/


void mostrar_matriz(int m[][TAM], int f,int c)
{
    int i,j;
    printf("\n Matriz: \n");
    for(i=0;i<f;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%3d", m[i][j]);
        }
        printf("\n");
    }
}

void encima_diag_ppal(int m[][TAM], int orden) //orden=filas
{
    int i,j;
    printf("\nElementos por encima de la diagonal principal: \n");
    for(i=0; i<orden; i++)
    {
        printf("%*s",(i+1)*3, " ");
        for(j=i+1;j<orden; j++)
        {
            printf("%3d", m[i][j]);
        }
        printf("\n");
    }
}

void encima_diag_secundaria(int m[][TAM], int orden)
{
    int i,j;
    printf("\nElementos por encima de la diagonal secundaria: \n");
    for(i=0;i<orden-1;i++)
    {
        for(j=0;j<orden-i-1;j++)
        {
             printf("%3d", m[i][j]);
        }
        printf("\n");
    }
}

void encima_dppalIncluida(int m[][TAM], int orden)
{
    int i,j;
    printf("\nElementos por encima de la diagonal principal incluida la diagonal: \n");
    for(i=0;i<=orden;i++)
    {
        printf("%*s",(i+1)*3, " ");
        for(j=i;j<orden;j++)
        {
            printf("%3d", m[i][j]);
        }
        printf("\n");
    }
}

void encima_dsecu_incluida(int m[][TAM], int orden)
{
    int i,j;
    printf("\nElementos por encima de la diagonal secundaria con la diagonal incluida: \n");
    for(i=0;i<=orden-1;i++)
    {
        for(j=0;j<orden-i;j++)
        {
             printf("%3d", m[i][j]);
        }
        printf("\n");
    }
}

void debajo_diag_ppal(int m[][TAM], int orden) //orden=filas
{
    int i,j;
    printf("\nElementos por debajo de la diagonal principal: \n");
    for(i=0; i<orden; i++)
    {
        for(j=0;j<i; j++)
        {
            printf("%3d", m[i][j]);
        }
        printf("\n");
    }
}

void debajo_diag_secundaria(int m[][TAM], int orden)
{
    int i,j;
    printf("\nElementos por debajo de la diagonal secundaria: \n");
    for(i=1;i<orden;i++)
    {
        for(j=orden-i;j<orden;j++)
        {
            printf("%3d", m[i][j]);
        }
        printf("\n");
    }
}

void debajo_dsecu_Incluida(int m[][TAM], int orden)
{
    int i,j;
    printf("\nElementos por debajo de la diagonal secundaria incluida la diagonal: \n");
     for(i=0;i<orden;i++)
    {
        for(j=orden-i-1;j<orden;j++)
        {
            printf("%3d", m[i][j]);
        }
        printf("\n");
    }
}


/*Desarrollar una función para que, dada una matriz cuadrada de enteros de orden N, obtenga la traza de la misma
(sumatoria de los elementos de la diagonal principal). Lo mismo, pero con la diagonal secundaria.*/

int sumatoriaDiagonalPpal(int m[][TAM], int orden)
{
    int i,suma=0;
    for(i=orden-1;i>=0;i--)
    {
        suma+=m[i][i];
    }
    return suma;
}

int sumatoriaDiagonalSecu(int m[][TAM], int orden)
{
    int i,j,suma=0;
    for(i=0;i<orden;i++)
    {
        j=orden-i-1;
        suma+=m[i][j];
    }
    return suma;
}


/*Desarrollar una función que determine
si una matriz cuadrada de enteros de orden N es matriz diagonal (ceros en todos sus elementos excepto en la diagonal principal).*/

int esMatrizDiagonal(int m[][TAM], int orden)
{
    int i,j,cont=0,cont2=0;
    for(i=0;i<orden;i++)
    {
        for(j=0;j<orden;j++)
        {
            if(m[i][j]==0 && i!=j)
            {
                cont++;
            }
            if(i==j && m[i][j]!=0)
            {
                cont2++;
            }
        }
    }
    if(cont==(orden*orden)-orden && cont2==orden)
        return 1;
    else
        return 0;
}

//Desarrollar una función que determine si una matriz cuadrada de enteros de orden N es matriz
//identidad (matriz diagonal, con unos en la diagonal principal y ceros en los restantes).

int esMatrizIdentidad(int m[][TAM], int orden)
{
    int i,j,cont=0,cont2=0;
    for(i=0;i<orden;i++)
    {
        for(j=0;j<orden;j++)
        {
            if(m[i][j]==0 && i!=j)
            {
                cont++;
            }
            if(i==j && m[i][j]==1)
            {
                cont2++;
            }
        }
    }
    if(cont==(orden*orden)-orden && cont2==orden)
        return 1;
    else
        return 0;
}


/*Desarrollar una función que determine si una matriz cuadrada de enteros de orden N es simétrica.*/
int esMatrizSimetrica (int m[][TAM], int orden)
{
    int i,j;
    for(i=0;i<orden;i++)
    {
        for(j=i+1;j<orden;j++)
        {
            if(i!=j && m[i][j]!=m[j][i])
            {
                return 0;
            }
        }
    }
    return 1;
}

//Desarrollar una función para trasponer, in situ, una matriz cuadrada
void TranspuestaMcuadrada(int m[][TAM], int orden)
{
    int aux,i,j;
    for(i=0;i<orden;i++)
    {
        for(j=i+1;j<orden;j++)
        {
            if(i!=j)
            {
                aux=m[i][j];
                m[i][j]=m[j][i];
                m[j][i]=aux;
            }
        }
    }
    printf("La matriz transpuesta es:\n ");
    mostrar_matriz(m,orden,orden);
}

//Desarrollar una función para obtener la traspuesta de una matriz dada
void transpuestaMatriz(int m[][TAM],int f, int c)
{
    int aux,i,j;
    for(i=0;i<c;i++)
    {
        for(j=i+1;j<f;j++)
        {
            if(i!=j)
            {
                aux=m[i][j];
                m[i][j]=m[j][i];
                m[j][i]=aux;
            }
        }
    }
    printf("La matriz transpuesta es:\n ");
    mostrar_matriz(m,c,f);
}

//Desarrollar una función para obtener la matriz producto entre dos matrices de enteros.

void multiplicacionDeMatrices(int m1[][TAM], int m2[][TAM],int f1,int c1, int f2,int c2)
{
    int m[f1][TAM];
    inicializarMatriz(m,f1,c2);
    //mostrar_matriz(m,f1,c2);
    int cont=0;
    if(c1!=f2)
    {
        printf("La multiplicacion entre estas matrices no se puede realizar");
    }
    else
    {
        for(int i=0;i<f1;i++)
        {
            for(int j=0;j<c2;j++)
            {
                cont=0;
                while(cont<c1)
                {

                    m[i][j]+=m1[i][cont]*m2[cont][j];
                    cont++;
                }
            }
        }
        printf("La multiplicacion de las matrices es de: ");
        mostrar_matriz(m,f1,c2);
    }
}

void inicializarMatriz (int m[][TAM], int f,int c)
{
    int i,j;
    for(i=0;i<f;i++)
    {
        for(j=0;j<c;j++)
        {
            m[i][j]=0;
        }
    }
}


/*Se dispone de una matriz cuadrada de enteros de orden N, donde cada elemento [i][j]
 representa la cantidad de puntos que obtuvo el equipo i frente al equipo j al fin de un torneo de
 fútbol (partidos de ida y vuelta) en el que participaron N equipos. El sistema de puntuación es:
 3 puntos para el ganador del partido y ninguno para el perdedor; 1 punto para cada equipo en caso de empate.
Desarrollar una función que determine si la matriz está correctamente generada.
Desarrollar una función que genere un arreglo de N elementos tal que cada ele-
mento V[k] contenga la cantidad de puntos obtenidos por el equipo k.*/

int cantidadDePuntosPorEquipo(int m[][TAM],int orden)
{
    int puntos[orden]={0};
    int i,j,k=0;
    for(i=0;i<orden;i++)
    {
        for(j=0;j<orden;j++)
        {
            puntos[k]+=m[k][j];
        }
    }
}


