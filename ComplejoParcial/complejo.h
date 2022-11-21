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
        Complejo(int real, int imaginaria);
        Complejo operator+(const Complejo complejo) const;
        Complejo operator*(const Complejo complejo) const;
        friend Complejo operator*(const int num,const Complejo complejo);
        friend ostream& operator<<(ostream& os, Complejo& complejo);
        friend istream& operator>>(istream& is,Complejo& complejo);



};

#endif // COMPLEJO_H
