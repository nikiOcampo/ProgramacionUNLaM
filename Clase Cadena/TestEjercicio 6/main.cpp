#include <iostream>
#include "C:\Users\Usuario\Desktop\NICOLE OCAMPO\00 UNLaM\16 programación\TCP\Ejercicio 6.6\Cadena.h"
using namespace std;

int main()
{
    Cadena cDefault();
    Cadena c1('a');
    Cadena c2("Hola mundo");
    Cadena c3(c2);


    cout<<"c1: "<<c1<<endl;
    cout<<"c2: "<<c2<<endl;
    cout<<"c3: "<<c3<<endl;

    Cadena c4;

    cout<<"Ingrese una frase: "<<endl;
    cin>> c4;
    cout<<"Frase ingresada: "<< c4<< endl;
    cout<<"c4: "<<c4<<endl;
    (c4 == "hola")? cout <<"\nSon iguales" : cout<<"\nNo son iguales";
//
//    Cadena c5=c2;
//
//    cout<<c5<<endl;
//
//    (c3==c2)? cout<< "\nc3 igual a c2" : cout<<"\nc3 no es igual a c2"<<endl;
//    (c5!=c4)? cout<< "\nc5 distinto a c4" : cout<< "\nc5 igual a c4" <<endl;

//    (c4>c2)? cout<< "\nc4 es mayor que c2" : cout<<"\nc4 es menor o igual que c2";
//    (c4<c2)? cout<< "\nc4 es menor que c2" : cout<<"\nc4 es mayor o igual que c2";
//
//    (c4>=c2)? cout<< "\nc4 es mayor o igual que c2" : cout<<"\nc4 es menor c2";
//    (c4<=c2)? cout<< "\nc4 es menor o igual que c2" : cout<<"\nc4 es mayor c2";
//
//    c1+=c2;
//    cout<< c1<< endl;
//
//    Cadena c6= c3+c4;
//    cout<<"c6:"<< c6 <<endl;

    return 0;
}
