#include "Cadena.h"
#include <iostream>
#include <string.h>

using namespace std;

Cadena::Cadena()
{
    this->cadenaC = new char[1];
    cadenaC[0] = '\0';
}

Cadena::~Cadena()
{
    //dtor
}

Cadena::Cadena(const char* cadenaC)
{
    this->cadenaC = new char[strlen(cadenaC) + 1];
    strcpy(this->cadenaC, cadenaC);
}

ostream& operator <<(ostream& os, const Cadena& cadena)
{
    os<< cadena.cadenaC;
    return os;
}

istream& operator >> (istream& input, Cadena& objCadena)
{
    char cadIngreso[100];
    input.getline(cadIngreso, 100);
    objCadena.cadenaC = new char [strlen(cadIngreso) + 1];
    strcpy(objCadena.cadenaC, cadIngreso);
    return input;
}

Cadena Cadena::operator +(const Cadena& cad1) const
{
    char* cadenaConcat = new char[strlen(cad1.cadenaC) + strlen(this->cadenaC) + 1];
    strcpy(cadenaConcat, cad1.cadenaC);
    strcat(cadenaConcat, this->cadenaC);
    return Cadena(cadenaConcat);
}

bool Cadena::operator ==(const Cadena& cadena) const
{
    if(strcmpi(this->cadenaC,cadena.cadenaC)==0)
        return true;
    else
        return false;
}

bool Cadena::operator !=(const Cadena& cadena) const
{
    if(strcmpi(this->cadenaC,cadena.cadenaC)!=0)
        return true;
    else
        return false;
}

Cadena Cadena::operator+=(const Cadena &cadena) const
{
    strcat(this->cadenaC, cadena.cadenaC);
    return *this;
}

Cadena operator +(const char* cad1, const Cadena& cad2)
{
    char* cadenaConcat = new char[strlen(cad1) + strlen(cad2.cadenaC) + 1];
    strcpy(cadenaConcat, cad1);
    strcat(cadenaConcat, cad2.cadenaC);
    return Cadena(cadenaConcat);
}


