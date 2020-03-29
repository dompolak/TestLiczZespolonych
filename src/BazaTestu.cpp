#include "Bazatestu.hh"

/*
*   Funkcja inicjalizujaca test
*Przyjmuje
*   Typ testu podany przez uzytkownika 
*   
*Funkcja
*   -sprawdza czy typ testu zostal podany poprawnie
*   -czy plik otworzyl sie poprawnie
*   -nastpenie inicjuje test liczb zespolonych
*/
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
/*
*   Funkcja sprawdzajaca czy podane dane przez uzytkownika sa zgodne z wynikiem dzialania
*Przyjmuje:
*   z1 - liczba zespolona podana przez uzytkownika
*   pytanie_testowe - pytanie pobrane z bazy testow
*   stat - statystyka 
* 
*Funckja wyswietla czy wynik byl poprawny czy bledny 
*/

void sprawdz(const LZespolona &z1, Wyra_zespolone &pytanie_testowe, statystyka &stat)
{
    LZespolona wynik;
    stat.licz_pytania();
    try
    {
        wynik = pytanie_testowe.oblicz_wyrazenie(pytanie_testowe);
    }
    catch(std::string w)
    {
        std::cout << w << std::endl << std::endl;
        return;
    }
    
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

/*
*   Funckja realizuja test liczb zespolonych
*Argementy:
*   file - wczytany plik z pytaniami
*   stat - statystyka 
*Funkcja wczytuje pytania z pliku i sprawdza czy zgadza sie z ustalonymi parametrami 
*/
void test_arytmetyki( std::istream &file, statystyka &stat)
{
    while(true)
    {
        Wyra_zespolone wyrazenie;
        LZespolona z1;
        file >> wyrazenie;
        if(file.eof())        
            {break;}
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
                std::cout << "Niepoprawny format liczby zespolonej. Masz 3 proby." << std::endl;
                for(; i < 3; i++)
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

                if(i == 3)
                {
                    std::cin.clear();
                    std::cin.ignore(1024, '\n');
                    stat.licz_pytania();
                    std::cout << "Odpowiedz zostala uznana za bledna" << std::endl << std::endl;
                }
            }else
            {
                sprawdz(z1, wyrazenie, stat);
            }
        }   
    }
}