#ifndef FECHA_H
#define FECHA_H
#include <iostream>

///La fecha base es 1/1/1601
#define ANIO_BASE 1601
#define Bisiesto(X)(((X)%4==0 && (X)%100!=0)||(X)%400==0)


using namespace std;

class Fecha
{
    public:
        Fecha();
        Fecha(int dia, int mes, int anio);
        friend ostream& operator <<(ostream& os, const Fecha& fecha);
        bool esBisiesto();
        bool pasoUnAnio(Fecha &fecha);
        int cantidadDias(Fecha& fecha);
        int operator -(const Fecha& fecha) const;
        void operator +=(int dias);
        bool antes(Fecha fecha) const;
        bool despues(Fecha fecha) const;

    private:
        int dia,mes,anio;

    static inline bool esFechaValida(int dia,int mes,int anio){return anio>= ANIO_BASE && mes>=1 && mes<=12 && dia>=1 && dia<=cantDiasMes(mes,anio);};
    static int cantDiasMes(int mes, int anio);
};

#endif // FECHA_H
