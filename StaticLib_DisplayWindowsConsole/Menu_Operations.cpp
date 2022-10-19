#include "pch.h"
#include "Menu_Operations.h"
#include "IKantorDisplay.h"
#include "../ExhangerStaticLib/ITransaction.h"

void Menu_Operations::displayMenuOperations()
{ 
   // IKantorDisplay window;
   //window.displayCurrencyTable();

    std::cout << std::endl << std::endl << std::endl;

    std::vector<std::string> tMenuGl; // tutaj bï¿½dï¿½ zapisywane pozycje z menu
    tMenuGl.push_back("Exit \t\t\t\t\t"); // tutaj na koï¿½cu dodaï¿½em tabulator bo funkcja menu na koï¿½cu doda numer opcji
    tMenuGl.push_back("For exchange currency - SELL operiation\t");
    tMenuGl.push_back("For exchange currency -  BUY operiation\t");
    tMenuGl.push_back("Balance\t\t\t\t\t");
    tMenuGl.push_back("Reports\t\t\t\t\t");

    int id = 0; // id wyboru

    do {
        menu("SELECT OPERATION:", tMenuGl, id); // wywoï¿½anie funkcji menu, ktï¿½ra wyï¿½wietli i wykona niezbï¿½dne instrukcje zwiï¿½zane z rysowaniem i zmianï¿½ pozycji w menu
        system("cls"); // czyszczenie ekranu, gdy funkcja menu gï¿½ï¿½wnego zostanie wykonana
        switch (id)  // tutaj zachowanie programu w zaleï¿½noï¿½ci od wyboru opcji
        {
        case 1:  // BUY OPERATION
          //if(_) - funkcja na obiekcie tworzonym dynamicznie
       //X.get_canBuy
       
            //tutaj kod od Klaudii

            //else - "nie masz dostêpu do tej opcji"


            break;
        case 2: // SELL OPERATION
           
            std::cout << std::endl;
            break;
        case 3: // BALANCE

            break;
        case 4: //REPORTS

            break;
        case 0: // dla wyjï¿½cia z programu
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
        c.X = x - 1; // x i y to numery wiersza i kolumny, gdzie numeracja jest od 1 a w systemie od 0 wiï¿½c odejmujï¿½ jeden
        c.Y = y - 1; // to samo co powyï¿½ej
        SetConsoleCursorPosition(handle, c); // ustaw pozycjï¿½ karetki
    }


void Menu_Operations::WriteMenuPos(std::string & str, int id, int idset)
    {
        if (id == idset) { // gdy pozycja jest wybrana
            SetConsoleTextAttribute(handle, 240); // to trzeba jï¿½ podï¿½wietliï¿½
            std::cout << str << "[" << id << "]" << std::endl; // wypisujï¿½ pozycjï¿½ z menu i dodajï¿½ jej numer w nawiasach kwadratowych
            SetConsoleTextAttribute(handle, 7); // powracam do domyï¿½lnych ustawieï¿½ kolorï¿½w
        }
        else { // w przeciwnym przypadku
            std::cout << str << "[" << id << "]" << std::endl; // wypisujï¿½ tekst danej pozycji menu i dodajï¿½ jej indeks w nawiasach kwadratowych
        }
    }

void Menu_Operations::WriteLine(unsigned int width)
    {
        for (unsigned int i = 0; i < width; i++)
        {
            std::cout << "="; // width razy wypisujï¿½ =
        }
        std::cout << std::endl;
    }


int Menu_Operations::menu(std::string title, std::vector<std::string>& tMenu, int& id)
{
A: // znacznik miejsca skoku
    gotoxy(1, 1); // ustawienie karetki klawiatury w linii 1 i kolumnie 1
    WriteLine(title.size()); // rysujï¿½ liniï¿½ ====== o dï¿½ugoï¿½ci rï¿½wnej dï¿½ugoï¿½ci tekstu tytuï¿½y menu
    std::cout << title << std::endl; // wypisujï¿½ menu
    WriteLine(title.size()); // i znowu linia =======
    for (int i = 0; i < tMenu.size(); i++) { // dla wszystkich pozycji menu
        WriteMenuPos(tMenu[i], i, id); // wypisuj danï¿½ pozycjï¿½ korzystajï¿½c z funkcji WriteLine
    }
    int c = _getch(); // pobieraj znak za pomocï¿½ getch() bez oczekiwania na znak powrotu
    if (c == 224) { // jak 224 znak zostaï¿½ wprowadzony to trzeba jeszcze pobraï¿½ jeden znak
        c = c << 8; // przesuwam bitowo o 8 pozycji
        c |= _getch(); // i operacjï¿½ bitowï¿½ OR robiï¿½ z wartoï¿½ciï¿½ uzyskanï¿½ z getch() -a
    }

    switch (c) {
    case (224 << 8) | 72: // to dla strzaï¿½ki w gï¿½rï¿½
        id = id ? id - 1 : 0; // jeï¿½eli id nie jest rï¿½wne zero to ustawiam id = id - 1
        gotoxy(1, 1); // ustawienie karetki klawiatury w linii 1 i wierszu 1
        goto A; // skok do znacznika A
    case (224 << 8) | 80: // to dla strzaï¿½ki w dï¿½
        id = id + 1 < tMenu.size() ? id + 1 : tMenu.size() - 1; // jak id < liczby pozycji menu to id ++
        gotoxy(1, 1); // ustawienie karetki klawiatury w linii 1 i wierszu 1
        goto A; // skok do znacznika A
    default: // w przypadkach innych niï¿½ powyï¿½sze
        if (c > 47 && c < 48 + tMenu.size()) { // gdy dany znak odpowiada pozycji w menu (np. 0, 1, ...) to
            id = c - 48; // obliczanie pozycji z menu
            return id; // i zwracanie
        }
        break;
    }

    return id; // zwraca numer wybranej pozycji

}



