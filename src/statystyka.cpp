#include "statystyka.hh"

statystyka::statystyka()
{
    this->ilosc_pytan = 0;
    this->poprawne = 0;
}

statystyka::~statystyka()
{

}

void statystyka::licz_pytania()
{
    this->ilosc_pytan++;
}

void statystyka::licz_poprawne()
{
    this->poprawne++;
}
int statystyka::getPoprawne()
{
    return this->poprawne;
}
int statystyka::getLpytan()
{
    return this->ilosc_pytan;
}

int statystyka::getNiepoprawne()
{
    return this->ilosc_pytan - this->poprawne;
}

double statystyka::procent()
{   
    double poprawne, ilosc_pytan;
    poprawne = this->poprawne;
    ilosc_pytan = this->ilosc_pytan;
    if(ilosc_pytan == 0)
    {return 0;}
    else
    {return (poprawne/ilosc_pytan) * 100;}
}

