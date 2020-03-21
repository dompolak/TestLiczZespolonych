#include "Bazatestu.hh"

void inicjalizuj_test(const std::string typ_testu)
{
    const std::string source_latwy = ".\\testy\\latwy.txt";
    const std::string source_trudny =  ".\\testy\\trudny.txt";
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
        std::cout << "Inicjalizacja testu nie powiodla sie!" << std::endl;
        exit(1);
    }

    if(file.fail())
    {
        std::cout << "Inicjalizacja testu nie powiodla sie!" <<std:: endl;
        exit(1);
    }else
    {
        std::cout << "Start testu arytmetyki zespolonej! " << std::endl;
        std::cout << "Poziom: " << typ_testu << std::endl;
        test_arytmetyki(file, stat);
        std::cout << "Koniec testu." << std::endl;
        std::cout << "Ilosc dobrych odpowiedzi: " << stat.getPoprawne() << std::endl;
        std::cout << "Ilosc blednych odpowiedzi: " << stat.getNiepoprawne() << std::endl;
        std::cout << "wynik procentowy poprawnych odpowiedzi:  " <<  stat.procent() <<"%" <<std::endl;
        file.close();
    }


}

void sprawdz(const LZespolona &z1, Wyra_zespolone &pytanie_testowe, statystyka &stat)
{
    LZespolona wynik;
    stat.licz_pytania();
    wynik = pytanie_testowe.oblicz_wyrazenie(pytanie_testowe);

    std::cout << "Twoja odpowiedz: " << z1 << std::endl;

    if(wynik == z1)
    {
        stat.licz_poprawne();
        std::cout << "Odpowiedz poprawna" << std::endl << std::endl;
    }else
    {
        std::cout << "Blad. Poprawnym wynikiem jest: " << wynik << std::endl << std::endl;
    }
}


void statystyka::licz_pytania()
{
    this->ilosc_pytan++;
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
    if(ilosc_pytan == 0)
    {return 0;}
    else
    {return (this->poprawne/this->ilosc_pytan) * 100;}

}

statystyka::statystyka()
{
    this->ilosc_pytan = 0;
    this->poprawne = 0;
}

statystyka::~statystyka()
{

}

void test_arytmetyki(std::istream &file, statystyka &stat)
{
    while(!file.eof())
    {
        Wyra_zespolone wyrazenie;
        LZespolona z1;
        if(file.eof())        
        {
            std::cerr << "????" << std::endl;
            break;
        }
            file >> wyrazenie;
            if(file.fail())
            {   
                std::cout << "Napotkano bledne wyrazenie. Zostalo ono pominiete." << std::endl << std::endl;
                file.clear();
                file.ignore(1024, '\n');
            }else
            {
                std::cout << "Podaj wynik operacji: " << wyrazenie << " = ";
                std::cin >> z1;
                if(std::cin.fail())
                {   
                    int i(0);
                    for(; i < 2; i++)
                    {
                        std::cin.clear();
                        std::cin.ignore(1024, '\n');
                        std::cin >> z1;
                        if(!std::cin.fail())
                        {
                            sprawdz(z1, wyrazenie, stat);
                            break;
                        }
                    }
                    if(i == 2)
                    {
                    std::cin.clear();
                    std::cin.ignore(1024, '\n');
                    stat.licz_pytania();
                    std::cout << std::endl;
                    }
                }else
                {
                    sprawdz(z1, wyrazenie, stat);
                }
            }   
    }
}