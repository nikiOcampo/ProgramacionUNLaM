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
        void setHora(int,int,int);

    public:
        Hora(int horas=0,int minutos=0, int segundos=0);
        friend ostream& operator <<(ostream& os, const Hora& hora);
        friend istream& operator >>(istream& is, Hora& hora);
        bool inline operator !=(const Hora hora){return(this->horas!=hora.horas || this->minutos!=hora.minutos || this->segundos!=hora.segundos);};
//        Hora& operator ++();//Preincremento
        Hora operator ++(int);//Postincremento
        Hora& operator+(const Hora hora) ;
        Hora& operator +=(const Hora hora);
        Hora& operator+=(const int seg);
        friend Hora operator+(int num, Hora hora);
        static Hora getHoraMaxima();


};

#endif // HORA_H
