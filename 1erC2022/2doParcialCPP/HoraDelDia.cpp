#include <iostream>
#include <windows.h>
#include "HoraDelDia.h"
#include "HoraDelDiaExc.h"

using namespace std;

HoraDelDia::HoraDelDia()
{
    this->hora=0;
    this->minutos=0;
    this->segundos=0;
}
HoraDelDia::HoraDelDia(int h,int m,int s)
{
    setHora(h,m,s);
}
istream& operator>>(istream &ent,HoraDelDia &obj)
{
    int h,m,s;
    ent>>h;
    ent>>m;
    ent>>s;
    obj.setHora(h,m,s);
    return ent;
}
ostream& operator<<(ostream &sal,const HoraDelDia &obj)
{
    sal<<obj.hora<<":"<<obj.minutos<<":"<<obj.segundos;
    return sal;
}

bool HoraDelDia::operator!=(const HoraDelDia &aux)const
{
   HoraDelDia obj;
   obj.setHora(10,10,10);
   return hora!=aux.hora || minutos!=aux.minutos || segundos!=aux.segundos;
}

HoraDelDia HoraDelDia::operator++(int a)
{
   HoraDelDia aux(hora,minutos,segundos);
   setHora(hora,minutos,segundos+1);
   return aux;
}
void HoraDelDia::setHora(int h,int m,int s)
{
    try
    {
        if(h<0 || m<0 || s<0)
        {
            throw new HoraDelDiaExc;
        }
    }
    catch(exception *e)
    {
        cout<<"hora invalida"<<endl;
        cout<<e->what()<<endl;

        exit(1);
    }
    if(s>=60)
    {
        s=(s%60);
        m+=(s/60);
    }
    if(m>=60)
    {
        m=(m%60);
        h+=(m/60);
    }
    if(h>=24)
    {
        h=(h%24);
    }
    hora=h;
    minutos=m;
    segundos=s;
}
