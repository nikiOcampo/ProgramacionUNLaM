#include <stdio.h>
#include <string.h>
#include "archivos.h"

int crea_textoF()
{
    FILE *ptxt;
    t_dato vdatos[] = {
                        {32691574,"Pepe Galleta1",{18,10,1986},'M'},
                        {354,"Pepita Galletita2",{11,12,90},'F'}
                      };

    ptxt = fopen("archivo_textoFijo.txt","wb");

    if(!ptxt)
    {
        printf("Error de creacion de archivo binario\n");
        return 1;
    }
    for(int i=0;i<2;i++)
        fprintf(ptxt, "%-8ld%-39s%2d%2d%4d%c\n", vdatos[i].dni, vdatos[i].apyn, vdatos[i].fecha_nac.dia,vdatos[i].fecha_nac.mes,vdatos[i].fecha_nac.anio, vdatos[i].sexo);

    /*  long dni;
    char apyn[40];
    t_fecha fecha_nac;
    char sexo;*/

    fclose(ptxt);

    return 0;
}


void textoFijoABinario(FILE *ptxt,FILE *pbin)
{
    t_dato dato;

    printf("\nESTA CONVIRTIENDO ARCHIVO FIJO A BINARIO\n");
    while(fscanf(ptxt,"%8ld%39[^\n]%2d%2d%4d%c\n", &dato.dni,&dato.apyn,&dato.fecha_nac.dia,&dato.fecha_nac.mes,&dato.fecha_nac.anio,&dato.sexo)==6)
    {
        /// Conversión de Texto Fijo a Binario
        fwrite(&dato,sizeof(t_dato),1,pbin);
    }
    fclose(pbin);
    fclose(ptxt);
}




/*****************************************************************************/
int muestra_textoF()
{
    t_dato dato;
    FILE *ptxt = fopen("archivo_textoFijo.txt","rb");

    if(!ptxt)
    {
        printf("Error de apertura\n");
        return 1;
    }

    printf("\n MUESTRA ARCHIVO TEXTO LONGITUD FIJA  \n \n");
    while(fscanf(ptxt,"%8ld%39[^\n]%2d%2d%4d%c\n", &dato.dni,&dato.apyn,&dato.fecha_nac.dia,&dato.fecha_nac.mes,&dato.fecha_nac.anio,&dato.sexo)==6)
        printf("%8ld%39s%2d%2d%4d%c\n", dato.dni,dato.apyn,dato.fecha_nac.dia,dato.fecha_nac.mes,dato.fecha_nac.anio,dato.sexo);


    fclose(ptxt);

    return 0;
}
