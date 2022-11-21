#include <iostream>
#include "C:\Users\Usuario\Desktop\NICOLE OCAMPO\00 UNLaM\16 programación\TCP\Fecha\Fecha.h"

using namespace std;

int main()
{
//    Fecha fDefault;
//    Fecha f(20,8,2022);
//
//    Fecha fSuma= f.sumarDias(180);
//
//    int difDias= f.diferenciaDias(fSuma);
//
//    cout << "Diferencia de dias:" <<difDias <<endl;
//
//    //Fecha fDefSuma= fDefault.sumarDias(200);
//    //mostrar fecha
//    int dia,mes,anio;
//    fSuma.getDma(dia,mes,anio);
//
//    cout <<"Fecha: "<< dia << "/" << mes <<"/" <<anio << endl; //le suma 180 dias a la fecha original

    Fecha fDefault;
    Fecha f(20, 8, 2022);
    const Fecha f2(10, 9, 2022);

    Fecha fSuma = f + 180;
    cout << "fSuma: " << fSuma << endl; // 22/8/2022
    //Fecha fSuma = Fecha(20, 8, 2022) + 180; // Objeto temporal.


    Fecha f3 = f++; // Postincremento.
    Fecha f4 = ++f; // Preincremento.
    cout << "f: " << f << endl; // 22/8/2022
    cout << "f3: " << f3 << endl; // 20/8/2022
    cout << "f4: " << f4 << endl; // 22/8/2022


    int difDias = f - f2;

    cout << "Diferencia de dias: " << difDias << endl;

    Fecha fResta;
    fResta = f - 180;

//    try
//    {
//        fResta = f - 180;
//    }
//    catch(const FechaInvalidaException& e)
//    {
//        cerr << e.getMensaje() << endl;
//        return FECHA_INVALIDA;
//    }
//




    cout << "Fecha resta: " << fResta << endl;
    cout << "Fecha: " << f << endl;

    int d, m, a;
    char barra;
    cout << "ingrese una fecha (D/M/A):" << endl;
    cin >> d >> barra >> m >> barra >> a;
    cout << "Fecha ingresada: " << d << "/" << m << "/" << a << endl;

/*
    cout << "ingrese una fecha (D/M/A):" << endl;
    cin >> f;
    cout << "Fecha ingresada: " << f << endl;
*/

    return 0;
}
