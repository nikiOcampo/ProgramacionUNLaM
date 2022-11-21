#ifndef RACIONAL_H
#define RACIONAL_H

#include <iostream>
#include <string.h>

using namespace std;


class Racional
{
    private:
        int numerador;
        int denominador;
        friend istream& operator >>(istream& is, Racional &racional);
        friend ostream& operator <<(ostream& os, Racional &racional);
    public:
        Racional();
        Racional(int numerador,int denominador);
        Racional(int numerador);
        Racional& operator+(Racional racional);
        friend Racional operator+( int num,Racional racional);
        bool operator <(const Racional racional);
        bool operator >(const Racional racional);


};

#endif // RACIONAL_H
