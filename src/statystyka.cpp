#include "statystyka.hh"

statystyka::statystyka()
{
    this->ilosc_pytan = 0;
    this->poprawne = 0;
}

statystyka::~statystyka()
{

}
/*
*   Funkcja liczaca ile jest pytan w tescie
*/

void statystyka::licz_pytania()
{
    this->ilosc_pytan++;
}
/*
*   Funkcja liczaca ile pytan zostalo udzielonych poprawnie
*/

void statystyka::licz_poprawne()
{
    this->poprawne++;
}
/*
*   Funkcja, ktora zwraca ilosc poprawnych odpowiedzi
*/
int statystyka::getPoprawne()
{
    return this->poprawne;
}
/*
*   Funckja zwracaja ilosc pytan
*/

int statystyka::getLpytan()
{
    return this->ilosc_pytan;
}
/*
*   Funckja najpierw liczy ilosc nieporawnych pytan odejmujach od wszystkich pytan te na ktore zostala udzielona odpowiedz poprawna
*Zwraca
*   ilosc pytan, na ktore zostala udzielona niepoprwana odpowiedz
*/

int statystyka::getNiepoprawne()
{
    return this->ilosc_pytan - this->poprawne;
}

/*
*   Funckja liczaca jaki procent to sa pytania poprwane
*Przyjmuje
*   ilosc odpowiedzi poprawnych
*   ilosc pytan
*Zwraca iloraz odpowidzi poprwanych przez ilosc pytan 
*/
double statystyka::procent()
{   
    double poprawne, ilosc_pytan;
    poprawne = this->poprawne;
    ilosc_pytan = this->ilosc_pytan;
    if(ilosc_pytan == 0)
    {return 0;}
    else
    {return (poprawne/ilosc_pytan) * 100;}
}

