#ifndef _BAZATESTU_HH
#define _BAZATESTU_HH

#include"WyrazenieZespolone.hh"
class statystyka
{
    double ilosc_pytan;
    double poprawne;
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
void inicjalizuj_test(const std::string typ_testu);
void sprawdz(const LZespolona &z1, Wyra_zespolone &pytanie_tesowe, statystyka&);


#endif