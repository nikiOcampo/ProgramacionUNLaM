#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int a;
    int m;
    int d;
}FECHA;

void leeFecha(FECHA *f);
void mostrarFecha(const FECHA *fecha);
int esFechaCorrecta (const FECHA *fecha);
int sumadias(FECHA *f);
int sumames(FECHA *f);
int sumaanio(FECHA *f);
int CantidadDias(int,int);
void cargarFecha(FECHA fecha);
int valorAbsoluto(int numero);
int sumarleNDias(FECHA *pf,int sumar);
int restarleNDias(FECHA *pf,int restar);


#endif // FECHA_H_INCLUDED
