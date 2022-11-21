#include <iostream>
#include "complejo.h"

using namespace std;


int main()
{
    Complejo c1(1, 2);
    Complejo c2(2, 1);

    //cout<<c1<<endl;

    Complejo c3 = c1 + c2;

    cout << c3 << " = " << c1 << " + " << c2 << endl;
//
    Complejo c4 = 5 * c3; //(15,15)
//
    cout << c4 << " = " << 5 << " * " << c3 << endl;
//
    Complejo c5 = c3 * c4;
//
    cout << c5 << " = " << c3 << " * " << c4 << endl;

    cout<<"ingrese un numero complejo(x,y): "<<endl;
    cin>> c5;
    cout<< c5;

    return 0;
}
