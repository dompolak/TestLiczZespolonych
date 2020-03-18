#include "BazaTestu.hh"

int main()
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
    }

    inicjalizuj_test(argv[1]);*/

  
   LZespolona z1, z2;
    for(;;)
    {
        cin >> z1;
        
        if(cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1024,'\n');
        }else
        {
            cout << z1 << endl;
        }


    }



}