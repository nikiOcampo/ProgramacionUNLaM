#include "Persona.h"
#include "string.h"


Persona::Persona()
{
    this->apellido= new char[1];
    apellido[0]='\0';
    this->nombre=new char[1];
    nombre[0]='\0';
    this->domicilio= new char[1];
    domicilio[0]='\0';
    strcpy(this->localidad," ");
    this->nacimiento.d=1;
    this->nacimiento.m=1;
    this->nacimiento.a=1;
    this->dni=11111111;
    this->sexo='X';
}

Persona::~Persona()
{
    delete [] apellido;
    delete [] nombre;
    delete [] domicilio;
}

Persona:: Persona(const char* apellido,const char* nombre,const char* domicilio, char localidad[20],t_fecha nacimiento,int dni, char sexo)
{
    this->apellido= new char [strlen(apellido)+1];
    strcpy(this->apellido, apellido);
    this->nombre=new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
    this->domicilio=new char[strlen(domicilio)+1];
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
    os<< "Nombre y Apellido: " << persona.nombre <<" "<< persona.apellido<<"\n";
    os<<"Domicilio: "<< persona.domicilio<<"\n";
    os<<"Localidad: "<< persona.localidad<<"\n";
    os<<"Fecha de Nacimiento: " <<persona.nacimiento.d<<"/"<<persona.nacimiento.m<<"/"<<persona.nacimiento.a<<"\n";
    os<<"DNI: "<<persona.dni<<"\n";
    os<<"Sexo: "<< persona.sexo<<"\n";

    return os;
}


istream& operator >>(istream& is, Persona& persona)
{
    return is;
}

void Persona::funciondeEntrada(Persona& persona)
{
    cout<<"Ingrese el nombre de la persona: "<<endl;
    cin>>persona.nombre;
    cout<<"Ingrese el apellido de la persona: "<<endl;
    cin>>persona.apellido;
    cout<<"Ingrese el domicilio de la persona: "<<endl;
    //cin.getline(persona.domicilio,19,'\n');
    cin>>persona.domicilio;
    cout<<"Ingrese el localidad de la persona: "<<endl;
    cin>>persona.localidad;
    cout<<"Ingrese la fecha de nacimiento de la persona: "<<endl;
    cout<<"Ingrese el dia:"<<endl;
    cin>>persona.nacimiento.d;
    cout<<"Ingrese el mes:"<<endl;
    cin>>persona.nacimiento.m;
    cout<<"Ingrese el anio:"<<endl;
    cin>>persona.nacimiento.a;
    cout<<"Ingrese el DNI:"<<endl;
    cin>>persona.dni;
    cout<<"Ingrese el sexo:"<<endl;
    cin>>persona.sexo;
}







