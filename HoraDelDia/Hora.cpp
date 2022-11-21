#include "Hora.h"
#include "HoraException.h"
#include <iostream>

using namespace std;
//
//Hora::Hora()
//{
//    //ctor
//}

Hora::Hora(int horas, int minutos,int segundos)
{
//    this->horas=horas;
//    this->minutos=minutos;
//    this->segundos=segundos;
    setHora(horas,minutos,segundos);
}


ostream& operator <<(ostream& os, const Hora& hora)
{
    os << hora.horas <<':'<< hora.minutos << ':' << hora.segundos ;
    return os;
}

istream& operator >>(istream& is, Hora& hora)
{
    int h,m,s;
    is>>h;
    is>>m;
    is>>s;
    hora.setHora(h,m,s);
    return is;
}

//istream& operator >>(istream& is, Hora& hora)
//{
//    int dosPuntos;
//    is>> hora.horas >> dosPuntos >> hora.minutos >> dosPuntos >> hora.segundos ;
//    return is;
//}

void Hora::setHora(int h,int m,int s)
{
    try
    {
        if(h<0 || m<0 || s<0)
        {
            throw new HoraException;
        }
    }
    catch(exception *e)
    {
        cout<<"hora invalida"<<endl;
        cout<<e->what()<<endl;

        exit(1);
    }
    if(s>=60)
    {
        s=(s%60);
        m+=(s/60);
    }
    if(m>=60)
    {
        m=(m%60);
        h+=(m/60);
    }
    if(h>=24)
    {
        h=(h%24);
    }
    horas=h;
    minutos=m;
    segundos=s;
}

//Hora& Hora::operator ++()//Preincremento
//{
//    if(this->segundos == 59)
//    {
//        if(this->minutos!=59)
//        {
//            ++this->minutos;
//            this->segundos=0;
//        }
//        else
//        {
//            ++this->horas;
//            this->minutos=0;
//            this->segundos=0;
//        }
//    }
//    else
//    {
//        ++this->segundos;
//    }
//    return *this;
//}

Hora Hora::operator ++(int)//Postincremento
{
    Hora horaAnterior(*this);
    if(this->segundos == 59)
    {
        if(this->minutos!=59)
        {
            ++this->minutos;
            this->segundos=0;
        }
        else
        {
            if(this->horas!=23)
            {
                ++this->horas;
                this->minutos=0;
                this->segundos=0;
            }else{
                this->horas=0;
                this->minutos=0;
                this->segundos=0;
            }
        }
    }
    else
    {
        ++this->segundos;
    }
    return horaAnterior;
}


Hora& Hora::operator+(const Hora hora)
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

Hora& Hora::operator+=(const int seg)
{
    Hora horaAux;
    horaAux.horas=seg/3600;
    horaAux.minutos=(seg%3600)/60;
    horaAux.segundos=(seg%60);

    *this+=horaAux;
    return *this;
}

Hora operator+(int num, Hora hora)
{
    Hora res;
    hora+=num;
    res+=hora;

    return res;
}

Hora Hora::getHoraMaxima()
{
  return Hora(23,59,59);
}
