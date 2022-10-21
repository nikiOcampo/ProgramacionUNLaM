#include <stdio.h>
#include <string.h>
#include "archivos.h"


/******************************************************************************
//  Nombre:			binario_a_texto.
//  Descripción:	Arma un archivo de texto a partir de un archivo binario.
//  Parametros: 	ptxt: puntero a archivo de texto.
//                  pbin: puntero a archivo binario.
//  Retorno         No posee.
******************************************************************************/

                       /*{32691574,"Pepe Galleta1",{18,10,1986},'M'},
                         {354,"Pepita Galletita2",{11,12,90},'F'}*/

                       /*32691574,"Pepe Galleta1",{18,10,1986},'M'*/

/*  long dni;
    char apyn[40];
    t_fecha fecha_nac;
    char sexo;*/

void binario_a_texto(FILE *pbin,FILE *ptxt)
{
    t_dato dato;

    printf("\nESTA CONVIRTIENDO ARCHIVO BINARIO A TEXTO LONGITUD VARIABLE/FIJA\n");
    while(fread(&dato,sizeof(t_dato),1,pbin))
    {
        /// Conversión de Binario a Texto de Longitud Variable
        fprintf(ptxt,"%ld|%s|%d/%d/%d|%c\n",dato.dni,dato.apyn,dato.fecha_nac.dia,dato.fecha_nac.mes,dato.fecha_nac.anio,dato.sexo);

        /// Conversión de Binario a Texto de Longitud FIJA

        ///fprintf(ptxt, "%-8ld%-39s%2d%2d%4d%c\n",dato.dni,dato.apyn,dato.fecha_nac.dia,dato.fecha_nac.mes,dato.fecha_nac.anio,dato.sexo);


    /*long dni;
    char apyn[40];
    t_fecha fecha_nac;
    char sexo;
    */
    }
    fclose(pbin);
    fclose(ptxt);
}

/*****************************************************************************/
int crea_binario()
{
    FILE *pbin;
    t_dato vdatos[] = {
                        {32691574,"Pepe Galleta1",{18,10,1986},'M'},
                        {354,"Pepita Galletita2",{11,12,90},'F'}
                      };

    pbin = fopen("archivo_binario.bin","wb");

    if(!pbin)
    {
        printf("Error de creacion de archivo binario\n");
        return 1;
    }

    fwrite(&vdatos,sizeof(vdatos),1,pbin);

    fclose(pbin);

    return 0;
}

/*****************************************************************************/
int muestra_binario()
{
    t_dato dato;
    FILE *pbin = fopen("archivo_binario.bin","rb");

    if(!pbin)
    {
        printf("Error de apertura\n");
        return 1;
    }

    printf("\n MUESTRA ARCHIVO BINARIO  \n \n");
    while(fread(&dato,sizeof(t_dato),1,pbin))

        printf("%ld|%s|%d/%d/%d|%c\n",dato.dni,dato.apyn,dato.fecha_nac.dia,dato.fecha_nac.mes,dato.fecha_nac.anio,dato.sexo);

    fclose(pbin);

    return 0;
}
