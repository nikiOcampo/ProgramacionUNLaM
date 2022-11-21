#ifndef CADENA_H
#define CADENA_H


#include <iostream>

using namespace std;


class Cadena
{
    private:
        char* cadenaC;


    public:
        Cadena();
        ~Cadena();
        Cadena(const char* cadenaC);
        friend ostream& operator <<(ostream& os, const Cadena& cadena);
        friend istream& operator >>(istream& is, Cadena& cadena);
        //friend Cadena operator +(const Cadena& cad1, const Cadena& cad2);
        Cadena operator +(const Cadena& cad1) const;
        bool operator ==(const Cadena& cadena) const;
        bool operator !=(const Cadena& cadena) const;
        Cadena operator+=(const Cadena &cadena) const;
        friend Cadena operator +(const char* cad1, const Cadena& cad2);

};

#endif // CADENA_H
