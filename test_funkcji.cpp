#include "Zespolona.hh"

std::istream &operator >> (std::istream &wejscie, LZespolona &Sk1)
{
    char znak;
    Sk1.re = 0; Sk1.im = 0;
    wejscie >> znak;
    if((wejscie.peek() >= '0' && wejscie.peek() <= '9') || wejscie.peek() == '-')
    {   
        wejscie >> znak;
        if(znak == '-' && wejscie.peek() == 'i')
        {
            Sk1.im = -1;
            wejscie >> znak >> znak;
            return wejscie;
        }
        wejscie.putback(znak);
        wejscie >> Sk1.re >> znak;
        if((znak == '-' || znak == '+') && wejscie.peek() == 'i')
        {
            if(znak == '-')
            {   
                Sk1.im = -1;
                wejscie >> znak >> znak;
                return wejscie;
            }else
            {
                Sk1.im = 1;
                wejscie >> znak >> znak;
                return wejscie;
            }
        }
        if(znak == 'i')
        {
            Sk1.im = Sk1.re; 
            Sk1.re = 0;
            wejscie >> znak; 
            return wejscie;
        }
        if((znak == '-' || znak == '+') && (wejscie.peek() >= '0' && wejscie.peek() <= '9'))
        {
            wejscie.putback(znak);
            wejscie >> Sk1.im >> znak >> znak;
            return wejscie;
        }
    }   
    if(wejscie.peek() == 'i')
    {
        Sk1.im = 1;
        wejscie >> znak >> znak;
        return wejscie;
    }
    return wejscie;
}