#include "BazaTestu.hh"

int main(int argc, char **argv)
{   

    using std::cout; 
    using std::endl; 
    using std::cin; 
  /* if(argc < 2)
    {
        cout << endl;
        cout << "Brak opcji okreslajacej rodzaj testu." << endl;
        cout << "Dopuszczalne nazwy to: latwy, trudny." << endl;
        cout << endl;
        return 1;
    }else
    {
         inicjalizuj_test(argv[1]);
    }
*/
 
    LZespolona z1, z2;

    std::cin >> z1 >> z2;
    std::cout << z1 / z2 << std::endl;
    /*catch(const char *msg)
    {
        std::cout << msg << std::endl;
    }*/
    
}