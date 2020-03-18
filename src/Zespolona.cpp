#include "Zespolona.hh"

LZespolona::LZespolona()
{
    this->re = 0;
    this->im = 0;
}

LZespolona::~LZespolona()
{

}

 std::ostream &operator << (std::ostream &wyjscie, const  LZespolona &Sk1)
 {  
     if(Sk1.re == 0 && (Sk1.im == 1 || Sk1.im == -1))
     {
         if(Sk1.im == -1)
         {return wyjscie << "(-i)";}
         if(Sk1.im == 1)
         {return wyjscie << "(i)";}
     }
     if(Sk1.im == 1)
     {  
         return wyjscie << '(' << Sk1.re <<"+i)"; 
     }
     if(Sk1.im == 0)
     {
         return wyjscie << '(' << Sk1.re << ')';
     }
     if(Sk1.im == -1)
     {
        return wyjscie << '(' << Sk1.re <<"-i)";
     } 
     if(Sk1.re == 0)
     {
         return wyjscie << '(' << Sk1.im << "i)";
     } 
     return wyjscie << '(' << Sk1.re << std::showpos << Sk1.im << std::noshowpos << "i)"; 
 }

 LZespolona operator + (const LZespolona &Sk1,const LZespolona &Sk2)
 {
     LZespolona wynik;
     wynik.re = Sk1.re + Sk2.re;
     wynik.im = Sk1.im + Sk2.im;
     return wynik;
 }

 LZespolona operator - (const LZespolona &Sk1,const LZespolona &Sk2)
 {
     LZespolona wynik;
     wynik.re = Sk1.re - Sk2.re;
     wynik.im = Sk1.im - Sk2.im;
     return wynik;
 }

  LZespolona operator * (const LZespolona &Sk1,const LZespolona &Sk2)
 {
     LZespolona wynik;
     wynik.re = Sk1.re * Sk2.re - Sk1.im * Sk2.im;
     wynik.im = Sk1.re * Sk2.im + Sk1.im * Sk2.re;
     return wynik;
 }

 LZespolona operator / (const LZespolona &Sk1,LZespolona &Sk2)
 {
    LZespolona wynik;
    wynik = (Sk1 * Sk2.sprzezenie(Sk2)) / (Sk2.modul() * Sk2.modul());
    return wynik;
 }

 LZespolona operator / (const LZespolona &Sk1, const double liczba )
 {
     LZespolona wynik;
     wynik.re = Sk1.re / liczba;
     wynik.im = Sk1.im / liczba;
     return wynik;
 }

 bool operator == (const LZespolona &Sk1, const LZespolona &Sk2)
 {
     if((Sk1.re == Sk2.re) && (Sk1.im == Sk2.im))
     {
        return true;
     }
        
        return false;
 }

 double LZespolona::modul()
 {
     return sqrt(this->re * this->re + this->im * this->im);
 }

 LZespolona LZespolona::sprzezenie(LZespolona &Sk1)
 {
     LZespolona wynik;
     wynik.re = Sk1.re;
     wynik.im = Sk1.im * -1;
     return wynik;
 }

