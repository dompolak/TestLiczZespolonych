#ifndef _STATYSTYKA_HH
#define _STATYSTYKA_HH

#include<iostream>

class statystyka
{
    int ilosc_pytan;
    int poprawne;
public:
    statystyka();
    ~statystyka();
    void licz_pytania();
    void licz_poprawne();
    int getPoprawne();
    int getLpytan();
    int getNiepoprawne();
    double procent();
};


#endif