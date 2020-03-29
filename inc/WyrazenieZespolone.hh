#ifndef _WYRAZENIEZESPOLONE_HH
#define _WYRAZENIEZESPOLONE_HH

#include "Zespolona.hh"

/*!
 * Modeluje zbior operatorow arytmetycznych.
 */

enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };

/*
*   Klasa ktora modeluje pojecie dwuargumentowego wyrazenia zespolonego   
*
*/

class Wyra_zespolone
{
    LZespolona Arg1;
    Operator oper;
    LZespolona Arg2;
public:
    Wyra_zespolone(){};
    ~Wyra_zespolone(){};
    LZespolona get_Arg1() const;
    LZespolona get_Arg2() const;
    Operator get_oper() const;
    void set_Arg1(LZespolona);
    void set_Arg2(LZespolona);
    void set_oper(Operator);
    LZespolona oblicz_wyrazenie(Wyra_zespolone &);
};

std::istream &operator >> (std::istream &StrWe, Operator &WczytSym );
std::ostream &operator << (std::ostream &wyjscie, const Operator &Op);
std::istream &operator >>(std::istream &wejscie, Wyra_zespolone &wyrazenie);
std::ostream &operator << (std::ostream &wyjscie, const Wyra_zespolone &wyrazenie);

#endif