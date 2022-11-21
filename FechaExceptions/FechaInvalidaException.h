#ifndef FECHAINVALIDAEXCEPTION_H
#define FECHAINVALIDAEXCEPTION_H

#include <exception>
using namespace std;

class FechaInvalidaException : public exception
{
public:
    FechaInvalidaException():exception(){}
    const char *what() throw()
    {
        return "Error. Fecha Invalida";
    }

};

#endif // FECHAINVALIDAEXCEPTION_H
