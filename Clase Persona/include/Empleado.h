#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "Persona.h"

typedef struct
{
    int d,m,a;
}t_fecha;

class Empleado : public Persona
{
    private:
        char cargo[10];
        char* sector;
        t_fecha fechaIngreso;
        t_fecha fechaDeBaja;


    public:
        Empleado();
        ~Empleado();
        friend ostream& operator <<(ostream& os, const Empleado& empleado);
        friend istream& operator >>(istream& is, Empleado& empleado);

};

#endif // EMPLEADO_H
