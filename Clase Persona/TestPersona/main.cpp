#include <iostream>
#include "C:\Users\Usuario\Desktop\NICOLE OCAMPO\00 UNLaM\16 programación\TCP\Ejercicio 6.9\Persona.h"

using namespace std;

int main()
{
    Persona persona1();
    t_fecha nac={15,10,2002};
    Persona persona2("Ocampo","Nicole","Calle1","Localidad1",nac,44451238,'F');
    cout<< "***********PERSONA 2*************: "<<endl;
    cout<< persona2<< endl;

    return 0;
}
