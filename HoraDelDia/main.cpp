#include <iostream>
#include <windows.h>

#include "Hora.h"
#include "HoraException.h"

using namespace std;


int main()
{
    try
    {
        Hora inicio, fin(0,0,20);             ///Horas, Minutos, Segundos
        Hora horaMio(23,55,55);
        cout << "Ingrese el horario de inicio: ";   ///En formato hr:min:seg
        cin >> inicio;
        cout << "Ingrese el horario de fin: ";
        cin >> fin;
        while(inicio != fin)
        {
            system("CLS");
            cout << "Actual: " << inicio++ << endl << "Fin: " << fin << endl;   ///++ incrementea en 1 segundo la hora
            //Sleep(1000);
        }
        cout << "FIN" << endl;
    }
    catch(HoraException &error)
    {
        cout << error.what() << endl;
    }
    try
    {
        Hora h1(22,54,21), h2(1,20,55), h3;   ///La hora nunca debe ser mayor a las 23:59:59
        h3 = h1 + h2;
        cout<<h3<< endl;
        h3 += 2;                                    ///Segundos
        cout<< h3 << endl;
        h3 = 3 + h3;                                ///Segundos
        cout << h3 << endl;
        h3 = Hora::getHoraMaxima();           ///Devuelve una hora a las 23:59:59
        cout << h3 << endl;
    }
    catch(HoraException &error)
    {
        cout << error.what() << endl;
    }
    return 0;
}

