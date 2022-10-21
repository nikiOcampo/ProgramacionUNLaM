#include "Fecha.h"
#include <iostream>


const int Fecha::acumDiasMes[14] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

const int Fecha::acumDiasMesBisiesto[14] = {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};

Fecha::Fecha()
{
    diaRel=0;
}

Fecha::Fecha(int dia, int mes, int anio)
{
    diaRel= dmaADiaRel(dia,mes,anio);
}

Fecha Fecha::operator +(int dias) const
{
    Fecha fechaSuma(*this); //constructor de copia disponible por defecto, NO es necesario implementarlo. , se hace una copia de lo q apunta this
    fechaSuma.diaRel += dias;

    ///es lo mismo que, pero esto es menos optimo
//    Fecha fechaSuma;
//    fechaSuma.diaRel=this->diaRel + dias;

    return fechaSuma;
}


Fecha Fecha::operator -(int dias) const
{
    Fecha fechaResta(*this);
    fechaResta.diaRel -= dias;

    if(fechaResta.diaRel < 1)
        throw "Fecha inválida: Quiere restar más días de los permitidos.";

    return fechaResta;
}


int Fecha::operator -(const Fecha& fecha) const
{
    return this->diaRel - fecha.diaRel; //a mi fecha restale la fecha del parametro de entrada
}


Fecha& Fecha::operator ++() // Preincremento
{
    ++this->diaRel;
    return *this;
}


Fecha Fecha::operator ++(int) // Posincremento
{
    Fecha fechaAnterior(*this);
    ++this->diaRel;
    return fechaAnterior;
}



int Fecha::dmaADiaRel(int dia,int mes,int anio)
{
    if(!esFechaValida(dia,mes,anio))
        throw FECHA_INVALIDA;

    int cantAnios = anio - ANIO_BASE;
    int diasAniosCompl = cantAnios * 365 + cantAnios / 4 - cantAnios / 100 + cantAnios / 400;
    this->diaRel = diasAniosCompl + diaDelAnio(dia, mes, anio);
    return diaRel;
}


int Fecha::cantDiasMes(int mes, int anio)
{
    static const int diasMes[13]={0,31,28,31,30,31,30,31,31,30,31,30,31}; //static en una variable solo se reserva en memoria una sola vez no cada vez q entre a la funcion
    if(mes==2 && esBisiesto(anio))
        return 29;
    else
        return diasMes[mes];
}
///ESTE METODO SE ELIMINA Y SE UTILIZA UNA SOBRECARGA DEL +
//Fecha Fecha::sumarDias(int dias) const
//{
//    Fecha fsuma; //creo una fecha nueva
//    fsuma.diaRel=diaRel+dias;
//    return fsuma;
//}

//Fecha Fecha::restarDias(int dias)
//{
//    Fecha fresta;
//    fresta.diaRel=diaRel-dias;
//    return fresta;
//}


//lo q retorna, la clase a la q pertence, el nombre, parametros q recibe
//int Fecha::diferenciaDias(Fecha fecha) const
//{
//    return diaRel - fecha.diaRel;
//}
//dia de la semana, el primer dia es lunes y el ultimo es el domingo, la fecha base es 1/1/1601
int Fecha::diaDeLaSemana() const
{
    return (diaRel-1)%7;
}

void Fecha::getDma(int& dia, int& mes, int& anio) const
{
    int cantAniosComplCalc = this->diaRel / 365;

    int diasAniosComplCalc;

    diasAniosComplCalc =
        cantAniosComplCalc * 365 + cantAniosComplCalc / 4 - cantAniosComplCalc / 100 + cantAniosComplCalc / 400;

    while(diasAniosComplCalc >= this->diaRel)
    {
        cantAniosComplCalc--;
        diasAniosComplCalc =
            cantAniosComplCalc * 365 + cantAniosComplCalc / 4 - cantAniosComplCalc / 100 + cantAniosComplCalc / 400;
    }

    anio = cantAniosComplCalc + ANIO_BASE;

    int diaDelAnio = this->diaRel - diasAniosComplCalc;

    diaDelAnioADiaMes(diaDelAnio, anio, &dia, &mes);
}

void Fecha::diaDelAnioADiaMes(int diaDelAnio, int anio, int* dia, int* mes)
{
    const int* acumDiasMes = esBisiesto(anio) ? acumDiasMesBisiesto : Fecha::acumDiasMes;

    int m = 1;
    while(diaDelAnio > acumDiasMes[m])
        m++;

    m--;
    *mes = m;

    *dia = diaDelAnio - acumDiasMes[m];
}

ostream& operator <<(ostream& os, const Fecha& fecha)
{
    int dia, mes, anio;
    fecha.getDma(dia, mes, anio);
    os << dia << '/' << mes << '/' << anio;
    return os;
}

istream& operator >>(istream& is, Fecha& fecha)
{

}
