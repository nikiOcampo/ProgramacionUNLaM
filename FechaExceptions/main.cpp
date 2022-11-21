#include <iostream>
#include "Fecha.h"
#include "FechaInvalidaException.h"

using namespace std;

int main()
{
    Fecha valida(19, 06, 2021);
    Fecha otraFechaValida(15, 10, 2015);
//
    try
    {
        Fecha invalida(31, 02, 2021);
    }
    catch (FechaInvalidaException &error)
    {
        cout << "Fecha invalida" << endl;
    }

    cout << (valida.antes(otraFechaValida)? "Antes" : "Despues") << endl;
    cout << (valida.despues(otraFechaValida)? "Despues" : "Antes") << endl;
    cout << valida << (valida.esBisiesto()? " pertenece a un anio bisiesto" : " no pertenece a un anio bisiesto") << endl;
    cout << valida << (valida.pasoUnAnio(otraFechaValida)? " hace menos de un anio." : " hace mas de un anio.") << endl;
    cout << "Pasaron " << valida.cantidadDias(otraFechaValida) << "dias entre las fechas." << endl;
//
    cout << "Le agrego 5 dias a una fecha.";
    valida += 5;
    cout << valida;

    return 0;
}
