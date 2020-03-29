#include "Zespolona.hh"

LZespolona::LZespolona()
{
    this->re = 0;
    this->im = 0;
}

LZespolona::~LZespolona()
{

}
LZespolona::LZespolona(double re, double im)
{
    this->re = re;
    this->im = im;
}

void LZespolona::set_re (double re)
{
    this->re = re;
}

void LZespolona::set_im (double im)
{
    this->im = im;
}

double LZespolona::get_re() const
{
    return this->re;
}
double LZespolona::get_im() const
{
    return this->im;
}

std::ostream &operator << (std::ostream &wyjscie, const  LZespolona &Sk1)
 {  
     if(Sk1.get_re() == 0 && (Sk1.get_im() == 1 || Sk1.get_im() == -1))
     {
         if(Sk1.get_im() == -1)
         {return wyjscie << "(-i)";}
         if(Sk1.get_im() == 1)
         {return wyjscie << "(i)";}
     }
     if(Sk1.get_im() == 1)
     {  
         return wyjscie << '(' << Sk1.get_re() <<"+i)"; 
     }
     if(Sk1.get_im() == 0)
     {
         return wyjscie << '(' << Sk1.get_re() << ')';
     }
     if(Sk1.get_im() == -1)
     {
        return wyjscie << '(' << Sk1.get_re() <<"-i)";
     } 
     if(Sk1.get_re() == 0)
     {
         return wyjscie << '(' << Sk1.get_im() << "i)";
     } 
     return wyjscie << '(' << Sk1.get_re() << std::showpos << Sk1.get_im() << std::noshowpos << "i)"; 
    
 }

std::istream &operator >> (std::istream &wejscie, LZespolona &Sk1)
{
    char znak, znak1;
    Sk1.set_re(0);   Sk1.set_im(0);
    double im, re;
    wejscie >> znak;
    if((znak == '(') && ((wejscie.peek() >= '0' && wejscie.peek() <= '9') || (wejscie.peek() == '-')))
    {   
        wejscie >> znak;
        if(znak == '-' && wejscie.peek() == 'i')
        {
            Sk1.set_im(-1);
            wejscie >> znak >> znak;
            if(znak != ')')
                {wejscie.setstate(std::ios::failbit);}
        }
        wejscie.putback(znak);
        wejscie >> re >> znak; 
        if(znak == ')')
            {Sk1.set_re(re);
            return wejscie;}
        else
            {Sk1.set_re(re);
            wejscie >> znak1;}
        if((znak == '-' || znak == '+') && znak1 == 'i')
        {
            if(znak == '-')
                {Sk1.set_im(-1);}
            if(znak == '+')
                {Sk1.set_im(1);}
            wejscie >> znak;
            if(znak != ')')
                {wejscie.setstate(std::ios::failbit);}
        }
        if(znak == 'i' && znak1 == ')')
        {
            Sk1.set_im(re); 
            Sk1.set_re(0);
            return wejscie;
        }
        wejscie.putback(znak1);
        wejscie.putback(znak);
        wejscie >> im >> znak >> znak1;
        if(znak == 'i' && znak1 == ')')
            {Sk1.set_im(im);
            return wejscie;}
    }if(wejscie.peek() == 'i' && znak == '(')
    {
        Sk1.set_im(1);
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

 LZespolona LZespolona::operator / (LZespolona Sk2) const
 {
    LZespolona wynik;
    wynik = (*this * Sk2.sprzezenie()) / (Sk2.modul() * Sk2.modul());
    return wynik;
 }

 LZespolona LZespolona::operator / (const double &liczba ) const
 {
     LZespolona wynik;
     if(liczba == 0)
     {   
         std::string wyjatek = "Dzielenie przez zero!";
         throw wyjatek;
     }
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

bool LZespolona::operator != (const LZespolona &Sk1) const
{
    if(!(*this == Sk1))
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
