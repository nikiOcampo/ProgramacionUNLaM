#include <iostream>
#include "Racional.h"

using namespace std;

int main()
{
    Racional r1; //por defecto te lo pone en 0
    Racional r2(2,4),r3(5),r4,r5;
    cout<< "r1: "<<r1 <<endl;
    cout << " r2: "<<r2<<endl;//2/4
    cout << " r3: "<<r3<<endl;
    cout << " r4: "<<r4<<endl;
    r1=3;
    cout<< "r1: "<<r1 <<endl;
    r3=r1+r2;// r3 a partir de aca es 14/4= 3 + 2/4
    cout <<"r3:"<<r3<<endl;
    r4 = 2+r3; //2+14/4=22/4
    cout << " r4: "<<r4<<endl;

    cout << "\nIngrese la fraccion (num/den): ";
    cin>>r5;
    cout<<"r5: "<<r5<<endl;
    (r5<r3)? cout<<"r5 menor que r3" : cout<<"r5 es mayor que r3 "<<endl;
    (r2>r5)? cout<<"\nr2 mayor que r2" : cout<<"\nr2 es menor que r5 "<<endl;

    return 0;
}
