#ifndef HORADELDIA_H_INCLUDED
#define HORADELDIA_H_INCLUDED

using namespace std;

class HoraDelDia
{
private:
    int hora;
    int minutos;
    int segundos;
    void setHora(int,int,int);

public:
    HoraDelDia();
    HoraDelDia(int h,int m,int s);


    bool operator!=(const HoraDelDia &)const;
    HoraDelDia operator++(int);


    friend istream& operator>>(istream &ent, HoraDelDia&obj);
    friend ostream& operator<<(ostream &sal,const HoraDelDia &obj);


};

#endif // HORADELDIA_H_INCLUDED
