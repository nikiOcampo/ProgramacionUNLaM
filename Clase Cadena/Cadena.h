#ifndef CADENA_H
#define CADENA_H
#include <iostream>
#include <string.h>

#define TAM_CAD 50
using namespace std;


class Cadena
{
    private:
        char* cadenaC;
    public:
        Cadena();
        ~Cadena();
        Cadena(const char* cadenaC);
        Cadena(char c);
        Cadena(const Cadena& cadena);
        friend ostream& operator <<(ostream& os, const Cadena& cadena);
        friend istream& operator >>(istream& is, Cadena& cadena);
        Cadena operator=(const Cadena &cadena);
        bool operator ==(const Cadena& cadena) const;
        bool operator !=(const Cadena& cadena) const;
        bool operator <(const Cadena& cadena) const;
        bool operator <=(const Cadena& cadena) const;
        bool operator >(const Cadena& cadena) const;
        bool operator >=(const Cadena& cadena) const;
        Cadena operator+=(const Cadena &cadena) const;
        friend Cadena operator +(const Cadena& cad1, const Cadena& cad2);



};

#endif // CADENA_H
