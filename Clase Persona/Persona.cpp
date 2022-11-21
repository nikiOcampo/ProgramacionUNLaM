#include "Persona.h"
#include <string.h>

Persona::Persona()
{
    this->apellido= new char[1];
    apellido[0] = '\0';
    this->nombre=new char[1];
    nombre[0] = '\0';
    this->domicilio=new char[1];
    domicilio[0] = '\0';
    this->nacimiento.d=1;
    this->nacimiento.m=1;
    this->nacimiento.a=1601;
    this->dni=11111111;
    this->sexo='I';
}

Persona::~Persona()
{
    delete [] apellido;
    delete [] nombre;
    delete [] domicilio;
}

Persona::Persona(const char* apellido,const char* nombre,const char* domicilio,char localidad[20],t_fecha nacimiento,int dni,char sexo)
{
    this->apellido = new char[strlen(apellido) + 1];
    strcpy(this->apellido, apellido);
    this->nombre= new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
    this->domicilio= new char[strlen(domicilio)+1];
    strcpy(this->domicilio, domicilio);
    strcpy(this->localidad, localidad);
    this->nacimiento.a=nacimiento.a;
    this->nacimiento.m=nacimiento.m;
    this->nacimiento.d=nacimiento.d;
    this->dni=dni;
    this->sexo=sexo;
}

ostream& operator <<(ostream& os, const Persona& persona)
{
    os<< "Nombre y Apellido: " <<persona.nombre<< " " << persona.apellido<<"\n";
    os<< "Domicilio: " <<persona.domicilio<<"\n";
    os<< "Localidad: " <<persona.localidad<<"\n";
    os<< "Fecha de nacimiento: "<< persona.nacimiento.d <<"/"<<persona.nacimiento.m<<"/"<<persona.nacimiento.a<<"\n";
    os<< "DNI: " << persona.dni<<"\n";
    os<< "Sexo: "<< persona.sexo<<"\n";
    return os;
}


istream& operator >>(istream& is, Persona& persona)
{


    return is;
}
