#include "pch.h"
#include "Menu_Operations.h"
#include "IKantorDisplay.h"

void Menu_Operations::displayMenuOperations()
{ 
   // IKantorDisplay window;
   //window.displayCurrencyTable();

    std::cout << std::endl << std::endl << std::endl;

    std::vector<std::string> tMenuGl; // tutaj b�d� zapisywane pozycje z menu
    tMenuGl.push_back("Exit \t\t\t\t\t"); // tutaj na ko�cu doda�em tabulator bo funkcja menu na ko�cu doda numer opcji
    tMenuGl.push_back("For exchange currency - SELL operiation\t");
    tMenuGl.push_back("For exchange currency -  BUY operiation\t");
    tMenuGl.push_back("Balance\t\t\t\t\t");
    tMenuGl.push_back("Reports\t\t\t\t\t");

    int id = 0; // id wyboru

    do {
        menu("SELECT OPERATION:", tMenuGl, id); // wywo�anie funkcji menu, kt�ra wy�wietli i wykona niezb�dne instrukcje zwi�zane z rysowaniem i zmian� pozycji w menu
        system("cls"); // czyszczenie ekranu, gdy funkcja menu g��wnego zostanie wykonana
        switch (id)  // tutaj zachowanie programu w zale�no�ci od wyboru opcji
        {
        case 1:  // BUY OPERATION
          
          
            break;
        case 2: // SELL OPERATION
           
            std::cout << std::endl;
            break;
        case 3: // BALANCE

            break;
        case 4: //REPORTS

            break;
        case 0: // dla wyj�cia z programu
        {
            std::cout << "Press y, if you want to exit...";
            if (_getch() == 'y')
                id = -1;
            std::cout << std::endl;

        }
        break;
        }
        if (id > 0) {
            WriteLine(50);
            std::cout << "Press enter to return to main menu...";
            _getch();
        }
        system("cls");
    } while (id > -1);

    std::cout << "Press enter to end session...";
    std::cin.get();

   

}

void Menu_Operations::gotoxy(int x, int y)
    {
        COORD c; // struktura stosowana do pozycjonowania
        c.X = x - 1; // x i y to numery wiersza i kolumny, gdzie numeracja jest od 1 a w systemie od 0 wi�c odejmuj� jeden
        c.Y = y - 1; // to samo co powy�ej
        SetConsoleCursorPosition(handle, c); // ustaw pozycj� karetki
    }



void Menu_Operations::WriteMenuPos(std::string & str, int id, int idset)
    {
        if (id == idset) { // gdy pozycja jest wybrana
            SetConsoleTextAttribute(handle, 240); // to trzeba j� pod�wietli�
            std::cout << str << "[" << id << "]" << std::endl; // wypisuj� pozycj� z menu i dodaj� jej numer w nawiasach kwadratowych
            SetConsoleTextAttribute(handle, 7); // powracam do domy�lnych ustawie� kolor�w
        }
        else { // w przeciwnym przypadku
            std::cout << str << "[" << id << "]" << std::endl; // wypisuj� tekst danej pozycji menu i dodaj� jej indeks w nawiasach kwadratowych
        }
    }

void Menu_Operations::WriteLine(unsigned int width)
    {
        for (unsigned int i = 0; i < width; i++)
        {
            std::cout << "="; // width razy wypisuj� =
        }
        std::cout << std::endl;
    }


int Menu_Operations::menu(std::string title, std::vector<std::string>& tMenu, int& id)
{
A: // znacznik miejsca skoku
    gotoxy(1, 1); // ustawienie karetki klawiatury w linii 1 i kolumnie 1
    WriteLine(title.size()); // rysuj� lini� ====== o d�ugo�ci r�wnej d�ugo�ci tekstu tytu�y menu
    std::cout << title << std::endl; // wypisuj� menu
    WriteLine(title.size()); // i znowu linia =======
    for (int i = 0; i < tMenu.size(); i++) { // dla wszystkich pozycji menu
        WriteMenuPos(tMenu[i], i, id); // wypisuj dan� pozycj� korzystaj�c z funkcji WriteLine
    }
    int c = _getch(); // pobieraj znak za pomoc� getch() bez oczekiwania na znak powrotu
    if (c == 224) { // jak 224 znak zosta� wprowadzony to trzeba jeszcze pobra� jeden znak
        c = c << 8; // przesuwam bitowo o 8 pozycji
        c |= _getch(); // i operacj� bitow� OR robi� z warto�ci� uzyskan� z getch() -a
    }

    switch (c) {
    case (224 << 8) | 72: // to dla strza�ki w g�r�
        id = id ? id - 1 : 0; // je�eli id nie jest r�wne zero to ustawiam id = id - 1
        gotoxy(1, 1); // ustawienie karetki klawiatury w linii 1 i wierszu 1
        goto A; // skok do znacznika A
    case (224 << 8) | 80: // to dla strza�ki w d�
        id = id + 1 < tMenu.size() ? id + 1 : tMenu.size() - 1; // jak id < liczby pozycji menu to id ++
        gotoxy(1, 1); // ustawienie karetki klawiatury w linii 1 i wierszu 1
        goto A; // skok do znacznika A
    default: // w przypadkach innych ni� powy�sze
        if (c > 47 && c < 48 + tMenu.size()) { // gdy dany znak odpowiada pozycji w menu (np. 0, 1, ...) to
            id = c - 48; // obliczanie pozycji z menu
            return id; // i zwracanie
        }
        break;
    }

    return id; // zwraca numer wybranej pozycji

}


