#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

typedef struct
{
    int dia, mes, anio;
}t_fecha;

typedef struct
{
    long dni;
    char apyn[40];
    t_fecha fecha_nac;
    char sexo;
}t_dato;

int crea_textoF();
int muestra_textoF();
void textoFijoABinario(FILE *ptxt,FILE *pbin);



#endif // ARCHIVOS_H_INCLUDED
