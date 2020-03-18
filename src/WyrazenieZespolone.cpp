#include "WyrazenieZespolone.hh"


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
    const char ZnakOp[] = "+-*/";
    return wyjscie << ZnakOp[Op];
}

bool operator == (Operator &Oper, char wejscie)
{
    const char ZnakOp[] = "+-*/";
    if(ZnakOp[Oper] == wejscie)
    {return true;}

    return false;
}

std::istream &operator >>(std::istream &wejscie, Wyra_zespolone &wyrazenie)
{
    wejscie >> wyrazenie.Arg1 >> wyrazenie.oper >> wyrazenie.Arg2;
    return wejscie;
}

std::ostream &operator << (std::ostream &wyjscie, const Wyra_zespolone &wyrazenie)
{
    return wyjscie << wyrazenie.Arg1 << wyrazenie.oper << wyrazenie.Arg2;
}

LZespolona Wyra_zespolone::oblicz_wyrazenie(Wyra_zespolone &wyrazenie)
{
    LZespolona wynik;

    if(wyrazenie.oper == '+')
        {wynik = wyrazenie.Arg1 + wyrazenie.Arg2;}
    if(wyrazenie.oper == '-')
       {wynik = wyrazenie.Arg1 - wyrazenie.Arg2;}
    if(wyrazenie.oper == '*')
        {wynik = wyrazenie.Arg1 * wyrazenie.Arg2;}
    if(wyrazenie.oper == '/')
        {wynik = wyrazenie.Arg1 / wyrazenie.Arg2;}
    
    return wynik;
}
