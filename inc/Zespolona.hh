#ifndef _ZESPOLONA_HH
#define _ZESPOLONA_HH

#include<iostream>
#include<string>
#include<cstring>
#include<cassert>
#include<math.h>
#include<string>
#include<fstream>

class LZespolona
{
    double re;
    double im;
public:
    LZespolona();
    virtual ~LZespolona();
    friend std::ostream &operator << (std::ostream &wyjscie, const LZespolona &Sk1);
    friend std::istream &operator >> (std::istream &wejscie, LZespolona &Sk1);
    friend LZespolona operator + (const LZespolona &Sk1, const LZespolona &Sk2);
    friend LZespolona operator - (const LZespolona &Sk1, const LZespolona &Sk2);
    friend LZespolona operator * (const LZespolona &Sk1, const LZespolona &Sk2);
    friend LZespolona operator / (const LZespolona &Sk1, double liczba );
    friend LZespolona operator / (const LZespolona &Sk1, LZespolona &Sk2);
    friend bool operator == (const LZespolona &Sk1, const LZespolona &Sk2);
    double modul();
    LZespolona sprzezenie(LZespolona &);
};

#endif
