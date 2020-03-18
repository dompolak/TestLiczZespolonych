#ifndef _WYRAZENIEZESPOLONE_HH
#define _WYRAZENIEZESPOLONE_HH

#include "Zespolona.hh"

enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };

class Wyra_zespolone
{
    LZespolona Arg1;
    Operator oper;
    LZespolona Arg2;
public:
    Wyra_zespolone(){};
    ~Wyra_zespolone(){};
    friend std::istream &operator >>(std::istream &wejscie, Wyra_zespolone &wyrazenie);
    friend std::ostream &operator << (std::ostream &wyjscie, const Wyra_zespolone &wyrazenie);
    LZespolona oblicz_wyrazenie(Wyra_zespolone &);
    

};
std::istream &operator >> (std::istream &StrWe, Operator &WczytSym );
std::ostream &operator << (std::ostream &wyjscie,const Operator &Op);
#endif