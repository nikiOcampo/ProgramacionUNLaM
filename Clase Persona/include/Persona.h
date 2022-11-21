#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <string.h>
using namespace std;


typedef struct
{
    int d,m,a;
}t_fecha;

class Persona
{
    private:
        char* apellido;
        char* nombre;
        char* domicilio;
        char localidad[20];
        t_fecha nacimiento;
        int dni;
        char sexo;
    public:
        Persona();
        ~Persona();
        Persona(const char* apellido,const char* nombre, const char* domicilio,char localidad[20],t_fecha nacimiento,
                int dni=0, char sexo='X');

        void funciondeEntrada(Persona& persona);
        friend ostream& operator <<(ostream& os, const Persona& persona);
        friend istream& operator >>(istream& is, Persona& persona);


};

#endif // PERSONA_H
