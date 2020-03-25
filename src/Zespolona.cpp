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

std::istream &operator >> (std::istream &wejscie, LZespolona &Sk1)
{
    char znak, znak1;
    Sk1.re = 0; Sk1.im = 0;
    wejscie >> znak;
    if((znak == '(') && ((wejscie.peek() >= '0' && wejscie.peek() <= '9') || (wejscie.peek() == '-')))
    {   
        wejscie >> znak;
        if(znak == '-' && wejscie.peek() == 'i')
        {
            Sk1.im = -1;
            wejscie >> znak >> znak;
            if(znak != ')')
                {wejscie.setstate(std::ios::failbit);}
        }
        wejscie.putback(znak);
        wejscie >> Sk1.re >> znak; 
        if(znak == ')')
            {return wejscie;}
        else
            {wejscie >> znak1;}
        if((znak == '-' || znak == '+') && znak1 == 'i')
        {
            if(znak == '-')
                {Sk1.im = -1;}
            if(znak == '+')
                {Sk1.im = 1;}
            wejscie >> znak;
            if(znak != ')')
                {wejscie.setstate(std::ios::failbit);}
        }
        if(znak == 'i' && znak1 == ')')
        {
            Sk1.im = Sk1.re; 
            Sk1.re = 0;
            return wejscie;
        }
        wejscie.putback(znak1);
        wejscie.putback(znak);
        wejscie >> Sk1.im >> znak >> znak1;
        if(znak == 'i' && znak1 == ')')
            {return wejscie;}
    }if(wejscie.peek() == 'i' && znak == '(')
    {
        Sk1.im = 1;
        wejscie >> znak >> znak;
        if(znak != ')')
            {wejscie.setstate(std::ios::failbit);}
    }
        wejscie.setstate(std::ios::failbit);
        return wejscie;
}

 LZespolona LZespolona::operator + (const LZespolona &Sk1) const
 {
     LZespolona wynik;
     wynik.re = this->re + Sk1.re;
     wynik.im = this->im + Sk1.im;
     return wynik;
 }

 LZespolona LZespolona::operator - (const LZespolona &Sk1) const
 {
     LZespolona wynik;
     wynik.re = this->re - Sk1.re;
     wynik.im = this->im - Sk1.im;
     return wynik;
 }

  LZespolona LZespolona::operator * (const LZespolona &Sk1) const
 {
     LZespolona wynik;
     wynik.re = this->re * Sk1.re - this->im * Sk1.im;
     wynik.im = this->re * Sk1.im + this->im * Sk1.re;
     return wynik;
 }

 LZespolona operator / (const LZespolona &Sk1,LZespolona Sk2)
 {
    LZespolona wynik;
    wynik = (Sk1*  Sk2.sprzezenie()) / (Sk2.modul() * Sk2.modul());
    return wynik;
 }

 LZespolona LZespolona::operator / (const double &liczba ) const
 {
     LZespolona wynik;
     if(liczba == 0)
     {}
     else 
     {
     wynik.re = this->re / liczba;
     wynik.im = this->im/ liczba;
     }
    return wynik;
 }

 bool LZespolona::operator == (const LZespolona &Sk1) const
 {
    if(fabs(this->re - Sk1.re) <= FLT_EPSILON)       /* FLT_EPSILON 1E-5*/
       {
            if(fabs(this->im - Sk1.im) <= FLT_EPSILON)
            {return true;}
       }
        return false;
 }

bool operator != (const LZespolona &Sk1, const LZespolona &Sk2)
{
    if(!(Sk1 == Sk2))
        {return true;}

    return false;
}

 double LZespolona::modul()
 {
     return sqrt(this->re * this->re + this->im * this->im);
 }

 LZespolona LZespolona::sprzezenie()
 {
     LZespolona wynik;
     wynik.re = this->re;
     wynik.im = this->im * -1;
     return wynik;
 }

