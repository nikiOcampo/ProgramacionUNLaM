#include <iostream>
#include "C:\Users\Usuario\Desktop\NICOLE OCAMPO\00 UNLaM\16 programación\TCP\Ejercicio 6.2\Hora.h"

using namespace std;

int main()
{
    Hora horaDefault;
    Hora hora1(10,30,10);

    cout << "horaDefault: "<< horaDefault <<endl;
    cout << "hora1: " << hora1 <<endl;

    horaDefault++;

    cout<< "HoraDefault incrementada: " << horaDefault<< endl;

    hora1--;

    cout<< "Hora1 decrementada: " <<hora1 << endl;

    Hora hora2(15,45,50);

    cout<< "Hora2: "<< hora2 <<endl;

    hora1+=hora2;

    cout<< "Hora1+= hora2 " <<hora1 <<endl;

    Hora hora3(10,15,30);
    //Hora hora4(12,30,10);
    Hora hora4(10,15,30);
    cout<<"\n"<<endl;

    hora3-=hora4;

    cout<< "Hora3-=hora4: " <<hora3<< endl;

    cout<<"Hora4: " << hora4<<endl;
    cout<<"Hora4 + 3950 seg: "<<hora4+3950<<endl;
    cout<<"Hora4 - 3950 seg: "<<hora4-3950<<endl;


    (hora3==hora4)? cout<<"\nSon iguales" : cout<<"\nNo son iguales"<<endl;

    (hora3!=hora4)? cout<<"\nSon DISTINTOS" : cout<<"\nNo son DISTINTOS"<<endl;
    (hora4>hora3)? cout <<"\nHora 4 mayor que hora 3" : cout<<"\nHora 4 menor o igual que hora 3"<< endl;
    (hora4<hora3)? cout <<"\nHora 4 menor que hora 3" : cout<<"\nHora 4 mayor o igual que hora 3"<< endl;
    (hora4>=hora3)? cout <<"\nHora 4 mayor o igual que hora 3" : cout<<"\nHora 4 menor que hora 3"<< endl;
    (hora4<=hora3)? cout <<"\nHora 4 menor o igual que hora 3" : cout<<"\nHora 4 mayor que hora 3"<< endl;
    return 0;
}
