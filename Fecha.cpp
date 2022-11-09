#include "Fecha.h"
#include "FechaInvalidaException.h"

Fecha::Fecha()
{
    this->dia=1;
    this->mes=1;
    this->anio=1601;
}

Fecha::Fecha(int dia, int mes, int anio)
{
    if(!esFechaValida(dia,mes,anio))
        throw FechaInvalidaException();
    this->dia=dia;
    this->mes=mes;
    this->anio=anio;
}

int Fecha::cantDiasMes(int mes, int anio)
{
    static const int diasMes[13]={0,31,28,31,30,31,30,31,31,30,31,30,31}; //static en una variable solo se reserva en memoria una sola vez no cada vez q entre a la funcion
    if(mes==2 && Bisiesto(anio))
        return 29;
    else
        return diasMes[mes];
}


ostream& operator <<(ostream& os, const Fecha& fecha)
{
    os<< fecha.dia << '/' << fecha.mes << '/'<<fecha.anio;
    return os;
}

bool Fecha::esBisiesto()
{
    if(Bisiesto(this->anio))
        return 1;
    else
        return 0;
}

bool Fecha::pasoUnAnio(Fecha &fecha)
{
    if(fecha.anio < this->anio)
    {
        if(fecha.mes < this->mes)
        {
            if(fecha.dia < this->dia)
                return 1;
        }
    }
    return 0;

}

int Fecha::cantidadDias(Fecha& fecha)
{
   int dias=0,i;
    int anios=0;
    int meses=0;
    int cont=0;
    int vecanios[100]={0};
    static const int diasMes[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

    anios=this->anio-fecha.anio;
    for(i=0;i<anios;i++)
    {
        vecanios[i]=fecha.anio+i;
        if(Bisiesto(vecanios[i]))
            cont++;
    }


    dias+=anios*365+cont; //2190+2

    meses=this->mes-fecha.mes;
    if(meses<0) meses+=(-meses)*2;

    for(i=0;i<meses;i++)
    {
        if(fecha.mes+i+1>12)
        {
            fecha.mes=1;
        }
        dias-=diasMes[fecha.mes+i+1];

    }

    dias+=this->dia- fecha.dia;

    return dias;
}


void Fecha::operator +=(int dias)
{
    int validar;
    validar=cantDiasMes(this->mes,this->anio);
    this->dia+=dias;

    while(validar<this->dia)
    {
        this->dia-=validar;
        if(this->mes==12)
        {
            this->mes=1;
            this->anio++;
        }
        else
            this->mes++;
        validar=cantDiasMes(this->mes,this->anio);
    }
}

bool Fecha::antes(Fecha fecha) const
{
    if(this->anio<fecha.anio)
        return 1;
    else
    {
        if(this->anio>fecha.anio)
            return 0;
        else
        {
            if(this->mes<fecha.mes)
                return 1;
            else
            {
                if(this->mes>fecha.mes)
                    return 0;
                else
                {
                    if(this->dia< fecha.dia)
                        return 1;
                    else
                        return 0;
                }
            }
        }
    }
}


bool Fecha::despues(Fecha fecha) const
{
    return !this->antes(fecha);
}
