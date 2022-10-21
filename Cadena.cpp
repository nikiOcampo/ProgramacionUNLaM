#include "Cadena.h"
#include <string.h>
#include <iostream>
#include <queue>
using namespace std;

Cadena::Cadena()
{
    this->cadenaC = new char[1];
    cadenaC[0] = '\0';
}

Cadena::~Cadena()
{
    //cout << "Ejecutando Destructor" << endl;
    delete[] cadenaC;
}

Cadena::Cadena(const char* cadenaC)
{
    this->cadenaC = new char[strlen(cadenaC) + 1];
    strcpy(this->cadenaC, cadenaC);
}


Cadena::Cadena(char c)
{
    this->cadenaC = new char[2];
    cadenaC[0] = c;
    cadenaC[1] = '\0';
}

Cadena::Cadena(const Cadena& otra)
{
    this->cadenaC = new char[strlen(otra.cadenaC) + 1];
    strcpy(this->cadenaC, otra.cadenaC);
}

ostream& operator <<(ostream& os, const Cadena& cadena)
{
    os<< cadena.cadenaC;
    return os;
}

//    is>> cadena.cadenaC;
istream& operator >>(istream& is, Cadena& cadena)
{
    queue<char> colaChars;
    char c;

    while((c = is.get()) != '\n' && c != EOF)
        colaChars.push(c);

    if(strlen(cadena.cadenaC) != colaChars.size())
    {
        delete [] cadena.cadenaC;
        cadena.cadenaC = new char[colaChars.size() + 1];
    }

   	int i = 0;
    while(!colaChars.empty())
    {
        cadena.cadenaC[i++] = colaChars.front();
        colaChars.pop();
    }

    cadena.cadenaC[i] = '\0';

    return is;
}

Cadena Cadena::operator=(const Cadena &cadena)
{
    if(this== &cadena)
        return *this;
    if(strlen(this->cadenaC) != strlen(cadena.cadenaC))
    {
        delete [] this->cadenaC;
        this->cadenaC = new char[strlen(cadena.cadenaC) + 1];
    }

    strcpy(this->cadenaC, cadena.cadenaC);

    return *this;
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

bool Cadena::operator <(const Cadena& cadena) const
{
    if(strcmp(this->cadenaC, cadena.cadenaC)<0)
        return true;
    else
        return false;
}

bool Cadena::operator >(const Cadena& cadena) const
{
    if(strcmp(this->cadenaC, cadena.cadenaC)>0)
        return true;
    else
        return false;
}

bool Cadena::operator <=(const Cadena& cadena) const
{
    if(strcmp(this->cadenaC, cadena.cadenaC)<=0)
        return true;
    else
        return false;
}

bool Cadena::operator >=(const Cadena& cadena) const
{
    if(strcmp(this->cadenaC, cadena.cadenaC)>=0)
        return true;
    else
        return false;
}

Cadena Cadena::operator+=(const Cadena &cadena) const
{
    strcat(this->cadenaC, cadena.cadenaC);
    strcat(this->cadenaC, cadena.cadenaC);
    return *this;
}

Cadena operator +(const Cadena& cad1, const Cadena& cad2)
{
    Cadena concat;
    delete [] concat.cadenaC;

    concat.cadenaC = new char[strlen(cad1.cadenaC) + strlen(cad2.cadenaC) + 1];
    strcpy(concat.cadenaC, cad1.cadenaC);
    strcat(concat.cadenaC, cad2.cadenaC);
    return concat;
}
