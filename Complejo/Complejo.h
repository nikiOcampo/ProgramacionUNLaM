#ifndef COMPLEJO_H
#define COMPLEJO_H

#include <iostream>

using namespace std;

class Complejo
{
    private:
        int real;
        int imaginaria;


    public:
        Complejo();
        Complejo(int,int);
        Complejo& operator+(const Complejo complejo);
        Complejo& operator-(const Complejo complejo);
        Complejo& operator*(const Complejo complejo);

        friend istream& operator >>(istream& is, Complejo &complejo);
        friend ostream& operator <<(ostream& os, Complejo &complejo);

};

#endif // COMPLEJO_H
