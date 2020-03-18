#include "Zespolona.hh"
using namespace std;

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
            return wejscie;
        }
        wejscie.putback(znak);
        wejscie >> Sk1.re >> znak; 
        if(znak == ')')
        {
            return wejscie;
        }else
        {
            wejscie >> znak1;
        }
        if((znak == '-' || znak == '+') && znak1 == 'i')
        {
            if(znak == '-')
            {   
                Sk1.im = -1;
            }if(znak == '+')
            {
                Sk1.im = 1;

            }
                wejscie >> znak;
                if(znak != ')')
                {wejscie.setstate(std::ios::failbit);}
                return wejscie;

        }
        if(znak == 'i' && wejscie.peek() == ')')
        {
            Sk1.im = Sk1.re; 
            Sk1.re = 0;
            wejscie >> znak; 
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
        return wejscie;
    }
        wejscie.setstate(std::ios::failbit);
        return wejscie;
}
