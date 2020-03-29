#ifndef _ZESPOLONA_HH
#define _ZESPOLONA_HH

#include<iostream>
#include<string>
#include<math.h>
#include<cstring>
#include<fstream>
#include<cfloat>


class LZespolona
{
    double re;
    double im;
public:
    LZespolona();
    explicit LZespolona(double, double);
    ~LZespolona();
    void set_re(double);
    void set_im(double);
    double get_re() const;
    double get_im() const;
    LZespolona operator + (const LZespolona &Sk1) const;
    LZespolona operator - (const LZespolona &Sk1) const;
    LZespolona operator * (const LZespolona &Sk1) const;
    LZespolona operator / (LZespolona) const;
    LZespolona operator / (const double &liczba) const;
    bool operator == (const LZespolona &Sk1) const;
    bool operator != (const LZespolona &Sk1) const;
    double modul();
    LZespolona sprzezenie();
};

std::ostream &operator << (std::ostream &wyjscie, const  LZespolona &Sk1);
std::istream &operator >> (std::istream &wejscie, LZespolona &Sk1);

#endif
