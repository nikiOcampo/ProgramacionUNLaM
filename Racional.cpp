#include "Racional.h"
#include <iostream>

Racional::Racional()
{
    this->numerador=0;
    this->denominador=1;
}

Racional::Racional(int numerador,int denominador)
{
    this->numerador=numerador;
    this->denominador=denominador;
}

Racional::Racional(int numerador)
{
    this->numerador=numerador;
    this->denominador=1;
}

ostream& operator <<(ostream& os,Racional &racional)
{
    if(racional.denominador>1)
        os <<racional.numerador << '/' << racional.denominador;
    else
        os<<racional.numerador;
    return os;
}

Racional& Racional::operator+(Racional racional)
{
    this->numerador= this->numerador * racional.denominador + racional.numerador * this->denominador;
    this->denominador= this->denominador * racional.denominador;
    return *this;
}

istream& operator >>(istream& is, Racional &racional)
{
    char barra;
    is>> racional.numerador >> barra >>racional.denominador;
    while(racional.denominador==0)
    {
        cout<<"No se puede dividir por cero, vuelva a ingresar: "<<endl;
        is>> racional.numerador >> barra >>racional.denominador;
    }
    return is;
}

Racional operator+(int num,Racional racional)
{
    Racional res;
    res.numerador+= num*racional.denominador + racional.numerador;
    res.denominador= racional.denominador;

    return res;
}

bool Racional:: operator <(const Racional racional)
{
    if(this->numerador < racional.numerador)
        return 1;
    else if(this->numerador > racional.numerador)
        return 0;
    else
    {
        if(this->denominador > racional.denominador)
            return 1;
        else
            return 0;
    }
}

bool Racional::operator >(const Racional racional)
{
    if(this->numerador>racional.denominador)
        return 1;
    else if(this->numerador < racional.denominador )
        return 0;
    else
    {
        if(this->denominador < racional.denominador)
            return 1;
        else
            return 0;
    }
}


