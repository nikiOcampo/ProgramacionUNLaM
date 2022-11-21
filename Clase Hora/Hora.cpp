#include "Hora.h"

using namespace std;
#include <iostream>

Hora::Hora()
{
    this->horas=00;
    this->minutos=00;
    this->segundos=00;
}

Hora::Hora(int horas, int minutos,int segundos)
{
    this->horas=horas;
    this->minutos=minutos;
    this->segundos=segundos;
}

ostream& operator <<(ostream& os, const Hora& hora)
{
    os << hora.horas <<':'<< hora.minutos << ':' << hora.segundos ;
    return os;
}

istream& operator >>(istream& is, Hora& hora)
{
    int dosPuntos;
    is>> hora.horas >> dosPuntos >> hora.minutos >> dosPuntos >> hora.segundos ;
    return is;
}


Hora& Hora::operator ++()//Preincremento
{
    ++this->segundos;
    return *this;
}

Hora Hora::operator ++(int)//Postincremento
{
    Hora horaAnterior(*this);
    ++this->segundos;
    return horaAnterior;
}

Hora& Hora::operator --() //predecremento
{
    --this->segundos;
    return *this;
}

Hora Hora::operator --(int)//postdecremento
{
    Hora horaAnterior(*this);
    --this->segundos;
    return horaAnterior;
}

Hora& Hora::operator+=(const Hora hora)
{
    if(this->segundos + hora.segundos <= 60)
        this->segundos+=hora.segundos;
    else
    {
        this->segundos+=hora.segundos-60;
        this->minutos++;
    }
    if(this->minutos + hora.minutos <=60)
        this->minutos+=hora.minutos;
    else
    {
        this->minutos+=hora.minutos-60;
        this->horas++;
    }
    if(hora.horas + this->horas <=24 )
        this->horas+=hora.horas;
    else
        this->horas+=hora.horas-24;

    return *this;
}

Hora& Hora::operator -=(const Hora hora)
{
    if(this->segundos - hora.segundos >= 0)
        this->segundos-=hora.segundos;
    else
    {
        this->segundos=60 +(this->segundos - hora.segundos);
        this->minutos--;
    }
    if(this->minutos - hora.minutos>=0)
        this->minutos-=hora.minutos;
    else
    {
        this->minutos=60+(this->minutos - hora.minutos);
        this->horas--;
    }
    if(this->horas-hora.horas >= 0)
        this->horas-=hora.horas;
    else
        this->horas=24+(this->horas - hora.horas);

    return *this;

}

/*sumar/restar un entero que represente una cantidad (positiva o negativa) de segundos,*/
Hora& Hora::operator+(const int seg)
{
    Hora horaAux;
    horaAux.horas=seg/3600;
    horaAux.minutos=(seg%3600)/60;
    horaAux.segundos=(seg%60);

    *this+=horaAux;
    return *this;
}

Hora& Hora::operator-(const int seg)
{
    Hora horaAux;
    horaAux.horas=seg/3600;
    horaAux.minutos=(seg%3600)/60;
    horaAux.segundos=(seg%60);

    *this-=horaAux;
    return *this;
}

///relacionales (< > <= >=) entre horas y entre hora y tipo de dato hora.
bool Hora::operator >(const Hora hora)
{
    if (this->horas < hora.horas)
        return true;
    else
    {
        if(this->minutos < hora.minutos)
            return true;
        else
        {
            if(this->segundos < hora.segundos)
                return true;
            else
                return false;
        }
    }
}

bool Hora::operator<(const Hora hora)
{
    if (this->horas > hora.horas)
        return true;
    else
    {
        if(this->minutos > hora.minutos)
            return true;
        else
        {
            if(this->segundos > hora.segundos)
                return true;
            else
                return false;
        }
    }
}

bool Hora::operator >=(const Hora hora)
{
    if (this->horas <= hora.horas)
        return true;
    else
    {
        if(this->minutos <= hora.minutos)
            return true;
        else
        {
            if(this->segundos <= hora.segundos)
                return true;
            else
                return false;
        }
    }
}

bool Hora::operator<=(const Hora hora)
{
    if (this->horas >= hora.horas)
        return true;
    else
    {
        if(this->minutos >= hora.minutos)
            return true;
        else
        {
            if(this->segundos >= hora.segundos)
                return true;
            else
                return false;
        }
    }
}


