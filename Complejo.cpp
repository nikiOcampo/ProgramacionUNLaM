#include "Complejo.h"

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


ostream& operator <<(ostream& os, Complejo &complejo)
{
    os<<complejo.real << ',' <<complejo.imaginaria;
    return os;
}


Complejo& Complejo::operator+(const Complejo complejo)
{
    this->real+=complejo.real;
    this->imaginaria+=complejo.imaginaria;

    return *this;
}

Complejo& Complejo::operator-(const Complejo complejo)
{
    this->real-=complejo.real;
    this->imaginaria-=complejo.imaginaria;

    return *this;
}

 Complejo& Complejo::operator*(const Complejo complejo)
 {
     this->real*=complejo.real;
     this->imaginaria*=complejo.imaginaria;

     return *this;
 }

istream& operator >>(istream& is, Complejo &complejo)
{
    char coma;
    is>> complejo.real >> coma >> complejo.imaginaria;
    return is;
}
