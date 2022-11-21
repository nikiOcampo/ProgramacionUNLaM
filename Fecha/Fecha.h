#ifndef FECHA_H
#define FECHA_H

///La fecha base es 1/1/1601
#define ANIO_BASE 1601
#define esBisiesto(X) (((X)%4==0 && (X)%100!=0)||(X)%400==0)
#define FECHA_INVALIDA 1

using namespace std;
#include <iostream>

class Fecha
{
private:
    int diaRel; //es la cantidad de dias que pasaron desde el 1/1/1900 hasta esa fecha (fecha de excel)

    static const int acumDiasMes[14];
    static const int acumDiasMesBisiesto[14];

    static inline bool esFechaValida(int dia,int mes,int anio){return anio>= ANIO_BASE && mes>=1 && mes<=12 && dia>=1 && dia<=cantDiasMes(mes,anio);};

    int dmaADiaRel(int dia,int mes,int anio);

    static int cantDiasMes(int mes, int anio);

    static inline int diaDelAnio(int dia, int mes, int anio){return (esBisiesto(anio) ? acumDiasMesBisiesto[mes] : acumDiasMes[mes]) + dia; };

    static void diaDelAnioADiaMes(int diaDelAnio, int anio, int* dia, int* mes);

public:
    Fecha();
    Fecha(int dia, int mes, int anio);
///ESTOS METODOS SE REEMPLAZARON CON SOBRECARGAS DE OPERADORES
//    Fecha sumarDias(int dias) const; ///no va a modificar al objeto
//    Fecha restarDias(int dias);
//    int diferenciaDias(Fecha fecha) const;
//    void incrementarDia();

    int diaDeLaSemana() const;

    Fecha operator +(int dias) const;
    Fecha& operator ++(); // Preincremento
    Fecha operator ++(int); // Posincremento
    int operator -(const Fecha& fecha) const;
    Fecha operator -(int dias) const;
    // TODO
    // Fecha& operator --(); // Predecremento
    // Fecha operator --(int); // Posdecremento
    // Fecha& operator +=(int dias);
    // Fecha& operator -=(int dias);
    // bool operator ==(const Fecha& fecha) const;
    // bool operator !=(const Fecha& fecha) const;
    // bool operator <(const Fecha& fecha) const;
    // bool operator <=(const Fecha& fecha) const;
    // bool operator >(const Fecha& fecha) const;
    // bool operator >=(const Fecha& fecha) const;

    void getDma(int& dia, int& mes, int& anio) const;
};


ostream& operator <<(ostream& os, const Fecha& fecha);
istream& operator >>(istream& is, Fecha& fecha);

#endif // FECHA_H
