#ifndef HORAEXCEPTION_H
#define HORAEXCEPTION_H
#include <exception>
using namespace std;

class HoraException : public exception
{
    public:
    HoraException():exception(){}
    const char *what() throw()
    {
        return "Error. Hora Invalida";
    }


};

#endif // HORAEXCEPTION_H
