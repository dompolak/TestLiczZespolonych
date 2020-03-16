#include "Bazatestu.hh"

void inicjalizuj_test(const std::string typ_testu)
{
    const std::string source_latwy = "C:\\Users\\Dominik\\Desktop\\nie\\c++_cwiczenia\\zespolona\\testy\\latwy.txt";
    const std::string source_trudny =  "C:\\Users\\Dominik\\Desktop\\nie\\c++_cwiczenia\\zespolona\\testy\\trudny.txt";
    LZespolona z1;
    statystyka stat;
    std::ifstream file;
    Wyra_zespolone pytanie_testowe;

    if(!typ_testu.compare("latwy"))
    {
        file.open(source_latwy);
    }else if(!typ_testu.compare("trudny"))
    {
        file.open(source_trudny);
    }else
    {
        std::cerr << "Inicjalizacja testu nie powiodla sie!" << std::endl;
    }

    if(file.fail())
    {
        std::cerr << "Inicjalizacja testu nie powiodla sie!" <<std:: endl;
    }else
    {   
        std::cout << "Start testu:" << std::endl;
        while(!file.eof())
        {   
            file >> pytanie_testowe;
            if(file.eof()) break;
            std::cout << "Podaj wynik operacji: " << pytanie_testowe << " = ";  
            std::cin >> z1;
            std::cout << "Twoja odpowiedz: " << z1 << std::endl;
            sprawdz(z1, pytanie_testowe, stat);
        }
        std::cout << "Ilosc dobrych odpowiedzi: " << stat.getPoprawne() << std::endl; 
        std::cout << "Ilosc blednych odpowiedzi: " << stat.getNiepoprawne() << std::endl;
        std::cout << "Procentowy wynik testu: " << stat.procent() << "%" << std::endl << std::endl;
        std::cout << "Koniec testu" << std::endl;

        file.close();
    }


}

void sprawdz(const LZespolona &z1, Wyra_zespolone &pytanie_testowe, statystyka &stat)
{
    LZespolona wynik;
    stat.licz_pytania();
    wynik = pytanie_testowe.oblicz_wyrazenie(pytanie_testowe);
    if(wynik == z1)
    {   
        stat.licz_poprawne();
        std::cout << "Odpowiedz poprawna" << std::endl;
    }else
    {
        std::cout << "Blad. Poprawnym wynikiem jest: " << wynik << std::endl;
    }
}


void statystyka::licz_pytania()
{
    this->ilosc_pytan++;
    std::cerr << "Dodano pytanie: ilsoc: " << this->ilosc_pytan << std::endl;
}

void statystyka::licz_poprawne()
{
    this->poprawne++;
}
int statystyka::getPoprawne()
{
    return this->poprawne;
}
int statystyka::getLpytan()
{
    return this->ilosc_pytan;
}

int statystyka::getNiepoprawne()
{
    return this->ilosc_pytan - this->poprawne;
}

double statystyka::procent()
{
    return (this->poprawne/this->ilosc_pytan) * 100;
    
}

statystyka::statystyka()
{
    this->ilosc_pytan = 0;
    this->poprawne = 0;
}

statystyka::~statystyka()
{

}