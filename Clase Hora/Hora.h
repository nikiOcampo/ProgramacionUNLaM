#ifndef HORA_H
#define HORA_H
#include <iostream>
using namespace std;

class Hora
{
    private:
        int horas;
        int minutos;
        int segundos;
    public:
        Hora();
        Hora(int h,int m,int s);

        friend ostream& operator <<(ostream& os, const Hora& hora);
        friend istream& operator >>(istream& is, Hora& hora);
        Hora& operator ++();//Preincremento
        Hora operator ++(int);//Postincremento
        Hora& operator  --(); //predecremento
        Hora operator --(int);//postdecremento
        Hora& operator +=(const Hora hora);
        Hora& operator -=(const Hora hora);
        Hora& operator+(const int seg);
        Hora& operator-(const int seg);
        bool inline operator ==(const Hora hora){return(this->horas==hora.horas && this->minutos==hora.minutos && this->segundos==hora.segundos);};
        bool inline operator !=(const Hora hora){return(this->horas!=hora.horas || this->minutos!=hora.minutos || this->segundos!=hora.segundos);};
        bool operator>(const Hora hora);
        bool operator<(const Hora hora);
        bool operator>=(const Hora hora);
        bool operator<=(const Hora hora);

};

#endif // HORA_H
