#include "Complejo.h"
#include <iostream>

using namespace std;

Complejo::Complejo()
{
    this->real=0;
    this->imaginaria=0;
}

Complejo::Complejo(int real, int imaginaria)
{
    this->real=real;
    this->imaginaria=imaginaria;
}


ostream& operator<<(ostream& os, Complejo& complejo)
{
    os<<'('<<complejo.real<<','<<complejo.imaginaria<<')';
    return os;
}

Complejo Complejo::operator+(const Complejo complejo) const
{
    Complejo caux;
    caux.real= this->real+ complejo.real;
    caux.imaginaria= this->imaginaria +complejo.imaginaria;

    return caux;
}

Complejo operator*(const int num, const Complejo complejo)
{
    Complejo caux;
    caux.real= num*complejo.real;
    caux.imaginaria=num*complejo.imaginaria;
    return caux;
}


Complejo Complejo::operator*(const Complejo complejo) const
{
    Complejo caux;
    caux.real= this->real * complejo.real;
    caux.imaginaria=this->imaginaria * complejo.imaginaria;

    return caux;
}


istream& operator>>(istream& is,Complejo& complejo)
{
    char parentesis='(' , coma=',', parentesis2=')';

    is>> parentesis >> complejo.real >>coma >> complejo.imaginaria >> parentesis2;

    return is;
}
