#ifndef _BAZATESTU_HH
#define _BAZATESTU_HH

#include "statystyka.hh"
#include "WyrazenieZespolone.hh"

void inicjalizuj_test(const std::string typ_testu);
void sprawdz(const LZespolona &z1, Wyra_zespolone &pytanie_tesowe, statystyka&);
void test_arytmetyki(std::istream &, statystyka &);


#endif