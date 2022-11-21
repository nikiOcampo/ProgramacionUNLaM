#ifndef HORADELDIAEXC_H_INCLUDED
#define HORADELDIAEXC_H_INCLUDED

#include "HoraDelDia.h"
#include <string>
#include <iostream>
#include <exception>

using namespace std;

class HoraDelDiaExc:public std::exception
{
public:
    const char *what() throw()
    {
        return "Algun valor es negativo";
    }


};


#endif // HORADELDIAEXC_H_INCLUDED
