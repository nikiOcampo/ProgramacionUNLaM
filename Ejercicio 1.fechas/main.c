#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"




int main()
{
    //EJERCICIO 14
    //Desarrollar una función que determine si una fecha es formalmente correcta
   /* FECHA fecha;
    FECHA *pf;
    pf=&fecha;
    int r;
    leeFecha(pf);
    mostrarFecha(pf);
    r=esFechaCorrecta(pf);
    if(r==1)
        printf("\nLa fecha ingresada es CORRECTA");
    else
        printf("\nLa fecha ingresada es INCORRECTA");*/



    //EJERCICIO 15
    //Desarrollar una función que a partir de una fecha obtenga la correspondiente al día siguiente.
    /*FECHA fecha;
    FECHA *pf;
    pf=&fecha;
    int r;
    do{
        leeFecha(pf);
        r=esFechaCorrecta(pf);
        if(r!=1)
            printf("\nLa fecha que usted esta ingresando es INCORRECTA, vuelva a intentarlo \n");
    }while(r!=1);

    pf->d=sumadias(pf);
    pf->m=sumames(pf);
    pf->a=sumaanio(pf);
    printf("La Fecha incrementada en uno: %d/%d/%d",pf->d,pf->m,pf->a);*/



    //EJERCICIO 16
    //Desarrollar una función que a partir de una fecha obtenga la que resulte de su - marle N días.
    /*int r,sumar,dia2;
    FECHA fecha, *pf;
    pf=&fecha;
    do{
        leeFecha(pf);
        r=esFechaCorrecta(pf);
        if(r!=1)
            printf("\nLa fecha que usted esta ingresando es INCORRECTA, vuelva a intentarlo \n");
    }while(r!=1);
    printf("Ingrese la cantidad de dias que le quiere sumar a su fecha: ");
    scanf("%d",&sumar);
    dia2= sumarleNDias(pf,sumar);
    printf("La fecha nueva es: %d/%d/%d\n",dia2,fecha.m,fecha.a);*/

    //EJERCICIO 17
    /*int r,restar,dia2;
    FECHA fecha, *pf;
    pf=&fecha;
    do{
        leeFecha(pf);
        r=esFechaCorrecta(pf);
        if(r!=1)
            printf("\nLa fecha que usted esta ingresando es INCORRECTA, vuelva a intentarlo \n");
    }while(r!=1);
    printf("Ingrese la cantidad de dias que le quiere restar a su fecha: ");
    scanf("%d",&restar);
    dia2=restarleNDias(pf, restar);

    printf("La fecha nueva es: %d/%d/%d\n",dia2,fecha.m,fecha.a);*/

    //EJERCICIO 18
    //Desarrollar una función que a partir de dos fechas obtenga la cantidad de días que hay entre ellas.
    FECHA fecha1, fecha2,*pf1, *pf2;
    pf1=&fecha1;
    pf2=&fecha2;
    int cantDias=0,cantAnios,cantMeses,r;
    printf("Carga de la primera fecha: ");
    do{
        leeFecha(pf1);
        r=esFechaCorrecta(pf1);
            if(r!=1)
                printf("\nLa fecha que usted esta ingresando es INCORRECTA, vuelva a intentarlo \n");
    }while(r!=1);
    printf("Carga de la segunda fecha: ");
    do{
        leeFecha(pf2);
        r=esFechaCorrecta(pf2);
            if(r!=1)
                printf("\nLa fecha que usted esta ingresando es INCORRECTA, vuelva a intentarlo \n");
    }while(r!=1);
    cantAnios=valorAbsoluto(fecha1.a-fecha2.a);
    cantDias+=cantAnios*365;
    cantMeses=valorAbsoluto(fecha1.m-fecha2.m);
    cantDias+=cantMeses*30;
    cantDias+=valorAbsoluto(fecha1.d-fecha2.d);
    printf("La cantidad de dias que hay entre la fecha 1 la fecha 2 es de %d dias",cantDias);




    return 0;
}
