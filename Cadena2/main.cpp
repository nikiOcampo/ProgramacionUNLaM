#include <iostream>
#include "Cadena.h"

using namespace std;

int main()
{
    Cadena c1, c2("Esta es la segunda cadena."), c3;
    c1 = "Esta es la primer cadena.";
    cout << "Cadena 1: " << c1 << endl;
    cout << "Cadena 2: " << c2 << endl;
    c3 = c1 + c2;
    cout << "Cadena 3 (c1 + c2): " << c3 << endl;
    if (c1 == "Esta es la primer cadena.")
    {
        cout << "c1 es igual a \"Esta es la primer cadena.\"" << endl;
    }
    if (c1 != c2)
    {
        cout << "c1 es distinto a c2" << endl;
    }
    cout << "Ingrese una cadena: ";
    cin >> c3;
    c3 += " <- Ingresado por el usuario.";
    cout << c3 << endl;
    c3 = "La cadena 1 a la derecha -> " + c1;
    cout << c3;
    return 0;
}
