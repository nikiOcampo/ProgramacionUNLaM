#ifndef ARRAYS_H_INCLUDED
#define ARRAYS_H_INCLUDED

int insertarEnArreglo(int pos, int num, int vect[],int cantElem);
void mostrarVector(const int *vect,int ce);
//void mostrarVector(int vect[],int ce);
void ordenar(int vect[]);
int insertaSinDesordenar(int num, int vect[],int ce);
void eliminarDetPos(int pos, int vect[],int cantElem);
void elminarDetElem(int elem, int vect[], int ce);
int eliminarTotElem(int elem, int vect[],int ce);
int esPalindromo(char *palabra, int cantletras);
void eliminaEspacios(char *palabra, char *palabraSinEspacios,int cl);
int deStringAInt(char *palabra, int cl);



#endif // ARRAYS_H_INCLUDED
