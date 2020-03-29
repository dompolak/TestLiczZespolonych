#include "WyrazenieZespolone.hh"

void Wyra_zespolone::set_Arg1(LZespolona Arg1)
{
    this->Arg1 = Arg1;
}

void Wyra_zespolone::set_Arg2(LZespolona Arg2)
{
    this->Arg2 = Arg2;
}

void Wyra_zespolone::set_oper(Operator oper)
{
    this->oper = oper;
}

LZespolona Wyra_zespolone::get_Arg1() const
{
    return this->Arg1;
}

LZespolona Wyra_zespolone::get_Arg2() const
{
    return this->Arg2;
}

Operator Wyra_zespolone::get_oper() const
{
    return this->oper;    
}

std::istream &operator >> (std::istream &StrWe, Operator &WczytSym )
{
    Operator TypOp[] = {Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel};
    const char SymOp[] = "+-*/", *wSymOp;
    char CzytSymOp;

    StrWe >> CzytSymOp;

    if((wSymOp = strchr(SymOp, CzytSymOp)) == nullptr)
     {   
         StrWe.setstate(std::ios::failbit);
     }
    else
    {
        WczytSym = TypOp[wSymOp - SymOp];
    }

        return StrWe;
}

std::ostream &operator << (std::ostream &wyjscie,const Operator &Op)
{
    switch(Op)
    {
        case Op_Dodaj:
            return wyjscie  << "+"; 
            break;
        case Op_Odejmij:
            return wyjscie  << "-";
            break;
        case Op_Mnoz:
            return wyjscie  << "*";
            break;
        case Op_Dziel:
            return wyjscie << "/";
            break;
    }

    return wyjscie;
}

std::istream &operator >>(std::istream &wejscie, Wyra_zespolone &wyrazenie)
{
    LZespolona z1, z2, z3(0, 0);
    Operator oper;
    wejscie >> z1 >> oper >> z2;

    if(oper == Op_Dziel && z2 == (z3))
       {wejscie.setstate(std::ios::failbit);}

    wyrazenie.set_Arg1(z1);
    wyrazenie.set_Arg2(z2);
    wyrazenie.set_oper(oper);
    return wejscie;
}

std::ostream &operator << (std::ostream &wyjscie, const Wyra_zespolone &wyrazenie)
{   
    return wyjscie << wyrazenie.get_Arg1() << wyrazenie.get_oper() << wyrazenie.get_Arg2();
}

LZespolona Wyra_zespolone::oblicz_wyrazenie(Wyra_zespolone &wyrazenie)
{
    LZespolona wynik;
    switch(wyrazenie.oper)
    {
        case Op_Dodaj:
            wynik = wyrazenie.Arg1 + wyrazenie.Arg2;
        break;
        case Op_Odejmij:
            wynik = wyrazenie.Arg1 - wyrazenie.Arg2;
        break;
        case Op_Mnoz:
            wynik = wyrazenie.Arg1 * wyrazenie.Arg2;
        break;
        case Op_Dziel:
            wynik = wyrazenie.Arg1 / wyrazenie.Arg2;
        break;

    }
    return wynik;
}