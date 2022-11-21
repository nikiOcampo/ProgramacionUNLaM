#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"

#define TAM 10

int main()
{
   /* int m1[][TAM]={  {1,2},
                    {4,5},
                    {7,8}};
    int m2[][TAM]={ {1,2,3},
                    {0,5,2}};
    mostrar_matriz(m1,3,2);
    mostrar_matriz(m2,2,3);*/
    //mostrar_matriz(m,3,3);
//    encima_diag_ppal(m,3);
//    encima_diag_secundaria(m,3);
//    encima_dppalIncluida(m,3);
//    encima_dsecu_incluida(m,3);
//    debajo_diag_ppal(m,3);
//    debajo_diag_secundaria(m,3);
//    debajo_dsecu_Incluida(m,3);

//    printf("La sumatoria de los elementos de la diagonal principal es de: %d ", sumatoriaDiagonalPpal(m,3));
//    printf("\nLa sumatoria de los elementos de la diagonal secundaria es de: %d ", sumatoriaDiagonalSecu(m,3));

//    int retorno=esMatrizDiagonal(m,3);
//    (retorno==1)? printf("La matriz ingresada es una MATRIZ DIAGONAL"): printf("La matriz ingresada NO es una MATRIZ DIAGONAL");

//    int retorno=esMatrizIdentidad(m,3);
//    (retorno==1)? printf("La matriz es una MATRIZ IDENTIDAD") : printf("La matriz NO es MATRIZ IDENTIDAD");

//    int retorno= esMatrizSimetrica(m,3);
//    (retorno==1)? printf("Es matriz SIMETRICA"): printf("No es matriz simetrica");
//    TranspuestaMcuadrada(m,3);
//    transpuestaMatriz(m,4,3);
//    multiplicacionDeMatrices(m1,m2,3,2,2,3);

    int orden,i,j,r1,r2;
    printf("Ingrese la cantidad de gruposq ue participaran del sorteo: ");
    scanf("%d", &orden);
    int m[orden][TAM];
    inicializarMatriz(m,orden,orden);
    for(i=0;i<orden;i++)
    {
        for(j=0;j<orden;j++)
        {
            if(i!=j)
            {
                printf("\nIngrese los resultados del partido EQUIPO %d vs EQUIPO %d",i+1,j+1);
                scanf("%d %d",&r1, &r2);
                if(r1<r2)
                {
                    m[i][j]=3;
                }else
                {
                    if(r1==r2)
                    {
                        m[i][j]=1;
                    }
                }
            }
        }
        mostrar_matriz(m,orden,orden);
    }

    return 0;
}
