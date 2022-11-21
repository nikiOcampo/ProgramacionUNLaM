#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

#define TAM 10

void mostrar_matriz(int m[][TAM], int f,int c);
void encima_diag_ppal(int m[][TAM], int orden);
void encima_diag_secundaria(int m[][TAM], int orden);
void encima_dppalIncluida(int m[][TAM], int orden);
void encima_dsecu_incluida(int m[][TAM], int orden);
void debajo_diag_ppal(int m[][TAM], int orden);
void debajo_diag_secundaria(int m[][TAM], int orden);
void debajo_dsecu_Incluida(int m[][TAM], int orden);
int sumatoriaDiagonalPpal(int m[][TAM], int orden);
int sumatoriaDiagonalSecu(int m[][TAM], int orden);
int esMatrizDiagonal(int m[][TAM], int orden);
int esMatrizIdentidad(int m[][TAM], int orden);
int esMatrizSimetrica (int m[][TAM], int orden);
void TranspuestaMcuadrada(int m[][TAM], int orden);
void transpuestaMatriz(int m[][TAM],int f, int c);
void multiplicacionDeMatrices(int m1[][TAM], int m2[][TAM],int f1,int c1, int f2,int c2);
void inicializarMatriz (int m[][TAM], int f,int c);
#endif // MATRICES_H_INCLUDED
