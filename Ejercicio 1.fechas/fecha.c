#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"


void leeFecha(FECHA *f)
{
    printf("Ingrese fecha dd/mm/aaaa: ");
    scanf("%d/%d/%d", &f->d,&f->m,&f->a);

}

void mostrarFecha(const FECHA *f)
{
    printf("%d/%d/%d", f->d,f->m,f->a);
}




/*void cargarFecha(FECHA fecha)
{
    int r;
    do{
        printf("Ingrese un dia: ");
        scanf("%d",&fecha.d);
        printf("Ingrese un mes: ");
        scanf("%d",&fecha.m);
        printf("Ingrese un anio: ");
        scanf("%d",&fecha.a);
        r=esFechaCorrecta(fecha);
            if(r!=1)
                printf("\nLa fecha que usted esta ingresando es INCORRECTA, vuelva a intentarlo \n");
    }while(r!=1);

}*/

int esFechaCorrecta (const FECHA *fecha)
{
    int retorno, bisiesto, cantidaddiasmes;
    retorno = 0;
    if((fecha->a%4==0 && fecha->a %100!=0) || fecha->a %400==0)
        bisiesto=1;
    else
        bisiesto =0;
    if(fecha->m==4|| fecha->m ==6|| fecha->m ==9|| fecha->m ==11)
        cantidaddiasmes =30;
    else
    {
        if(fecha->m ==2)
            cantidaddiasmes =28+ bisiesto;
        else
            cantidaddiasmes =31;
    }
    if(fecha->a >=1950&& fecha->a<=2022 && fecha->m>=1&& fecha->m <=12&& fecha->d>=1&& fecha->d<= cantidaddiasmes )
        retorno =1;
    else
        retorno =0;
    return retorno;
}

int sumaanio(FECHA *f)
{
    int cant;
    if(f->m==1)
        cant=f->a+1;
    else
        cant=f->a;
    return cant;
}

int sumames(FECHA *f)
{
    int cant;
    if(f->d==1&&f->m==12)
        cant=1;
    else
    {
        cant=f->m+1;
    }
    if(f->d!=1)
        cant=f->m;
    return cant;
}

int sumadias(FECHA *f)
{
    int cant, num, cont, sen=0, ban=0, men=0;
    if(f->m==1||f->m==3||f->m==5||f->m==7||f->m==8||f->m==10||f->m==12)
        sen=1;
    if(sen==1)
    {
        if(f->d==31)
            cant=1;
        else
            cant=f->d+1;
    }
    if(f->m==4||f->m==6||f->m==9||f->m==11)
        ban=1;
    if(ban==1)
    {
        if(f->d==30)
            cont=1;
        else
            cont=f->d+1;
    }
    if(f->m==2)
        men=1;
    if(men==1)
    {
        if(f->d==28||f->d==29)
            num=1;
        else
            num=f->d+1;
    }
    if(sen==1)
    {
        return cant;
    }
    if(ban==1)
    {
        return cont;
    }
    if(men==1)
    {
        return num;
    }
}

int CantidadDias(int mes, int anio)
{
    switch(mes)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31; break;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30; break;
        case 2:
            if((anio%4==0&&anio%100!=0)||anio%400==0)
                return 29;
            else
                return 28;
            break;
        default: return 0;
    }
}

int valorAbsoluto(int numero)
{
    if (numero < 0)
    {
        numero*=-1;
    }
    return numero;
}

int sumarleNDias(FECHA *pf,int sumar)
{
    int validar,dia2;
    validar=CantidadDias(pf->m,pf->a); //cuantos dias tiene ese mes
    dia2=this->d+sumar; //a los dias ingresados le sumo la cantidad de dias que se les desea sumar
    // mientras que la cant de dias que tiene el mes sea menor que el dia nuevo calculado, queire decir q no exite ese dia en ese mes
    while(validar<dia2)
    {
        dia2-=validar;//a la cantidad de dias q exceden el mes le resto la cantidad de dias q tiene el mes para ver cuantos dias me sobran
        if(pf->m==12) //si justo es el ultimo mes, si me paso de los dias voy a tener q cambiar de anio
        {
            pf->m=1;// pongo el mes en uno=enero
            pf->a++;//aumento el anio
        }
        else
            pf->m++;//si el mes no era el 12 entonces solo aumento el mes
        validar=CantidadDias(pf->m,pf->a);//me vuelvo a fijar si me excedo de dias(por ejemplo si smo 100 dias son mas q un mes)
    }
    return dia2;
}

int restarleNDias(FECHA *pf,int restar)
{
    int validar,dia2;
    validar=CantidadDias(pf->m,pf->a);
    dia2=pf->d-restar;
    while(dia2<=0)
    {
        dia2+=validar;
        if(pf->m==1){
            pf->m=12;
            pf->a--;
        }else
            pf->m--;
        validar=CantidadDias(pf->m,pf->a);
    }
    return dia2;
}
