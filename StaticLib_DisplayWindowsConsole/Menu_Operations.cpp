#include "pch.h"
#include "Menu_Operations.h"
#include "IKantorDisplay.h"
#include "../ExhangerStaticLib/ITransaction.h"
#include "../Kantorex_login/LogInManager.hpp"
#include "../Kantorex_login/ILoggedUser.hpp"
#include "../Kantorex_login/Administrator.hpp"
#include "../ExhangerStaticLib/Exchanger.h"
#include "../Kantorex_login/Authorization.hpp"
#include "../JSONLib/LoggedUsersWriter.h"
#include "KantorDisplay_switchForReports.h"
#include "../StaticLib_DisplayWindowsConsole/KantorDisplay_balanceTable.h"
#include "../JSONLib/ReadSellAndBuyTable.h"
#include "KantorDisplay_CurrencyTable.h"


void Menu_Operations::displayMenuOperations(std::shared_ptr<ILoggedUser> loggedUser)
{ 
    CashBalance balance;


    const std::string red("\033[0;37;41m");
    const std::string blue("\033[0;37;44m");
    const std::string green("\033[0;37;42m");
    const std::string reset("\033[0m");

    std::cout << std::endl << std::endl << std::endl;


        std::vector<std::string> tMenuGl;// tutaj b�d� zapisywane pozycje z menu
        tMenuGl.push_back("Exit \t\t\t\t\t"); // tutaj na ko�cu doda�em tabulator bo funkcja menu na ko�cu doda numer opcji
        tMenuGl.push_back("For exchange currency - SELL operation\t");
        tMenuGl.push_back("For exchange currency -  BUY operation\t");
        tMenuGl.push_back("Balance\t\t\t\t\t");
        tMenuGl.push_back("Reports\t\t\t\t\t");
        std::cout << std::endl<< std::endl << std::endl << std::endl << std::endl;
        KantorDisplay_CurrencyTable table;
        table.displayCurrencyTable();
        
    int id = 0; // id wyboru


    do {
        menu("SELECT OPERATION:", tMenuGl, id); // wywo�anie funkcji menu, kt�ra wy�wietli i wykona niezb�dne instrukcje zwi�zane z rysowaniem i zmian� pozycji w menu
        system("cls"); // czyszczenie ekranu, gdy funkcja menu g��wnego zostanie wykonana
        
        std::vector<std::string> currenciesToChoose = { "THB","USD", "AUD", "HKD", "CAD", "NZD","SGD", "EUR", "HUF","CHF", "GBP", "UAH","JPY","CZK", "DKK","ISK", "NOK","SEK","HRK","RON","BGN","TRY", "ILS","CLP","PHP","MXN","ZAR","BRL","MYR","IDR","INR","KRW","CNY","XDR","SDR(MFW)" };
       
        switch (id)  // tutaj zachowanie programu w zale�no�ci od wyboru opcji
        { 
 
        case 1:  // SELL OPERATION
            if (loggedUser->getCanSell())
            {
                std::string _inputCurrencyFrom= "PLN";
                std::string _inputCurrencyTo;
                float _inputAmount;
                std::string _operationName = " SELL OPERATION MODE ";

                displayOperationName(_operationName);

          
                std::cout << "Enter currency to which exchange PLN : " << std::endl;
                std::cin >> _inputCurrencyTo;
              

                for (auto& s : currenciesToChoose)
                {
                    if (std::find(currenciesToChoose.begin(), currenciesToChoose.end(), _inputCurrencyTo) != currenciesToChoose.end())
                    {
                        std::cout << green << "Correct currency" << reset << std::endl;
                        std::cout << "You are exchanging from : " << _inputCurrencyFrom << " to : " << _inputCurrencyTo << std::endl;

                        std::cout << "Enter amount in: " << _inputCurrencyFrom << std::endl;
                        std::cin >> _inputAmount;

                        auto sell = OperationSellBuy::SELL;
                        Exchanger transactionSell(balance, sell, _inputCurrencyFrom, _inputAmount, _inputCurrencyTo);
                        std::cout << _inputCurrencyTo << " RATE: " << transactionSell.getRate() << std::endl;
                    }
                    else
                        std::cout <<red << "Currency is incorrect"<< reset << std::endl;
                    break;
                }
                

            }
              
            else 
            std::cout <<red << "Sorry, access to this operation is denied!"<<reset << std::endl;
            break;

        case 2: // BUY OPERATION
            
            if (loggedUser->getCanBuy())
            { 
                std::string _inputCurrencyFrom;
                 std::string _inputCurrencyTo = "PLN";
                 float _inputAmount;
                 std::string _operationName = " BUY OPERATION MODE ";


                displayOperationName(_operationName);
                

                std::cout << "Enter currency to buy (not PLN) : " << std::endl;
                std::cin >> _inputCurrencyFrom;

                for (auto& s : currenciesToChoose)
                {
                    if (std::find(currenciesToChoose.begin(), currenciesToChoose.end(), _inputCurrencyFrom) != currenciesToChoose.end())
                    {
                        std::cout << green << "Correct currency" << reset << std::endl;
                        std::cout << "You are exchanging to : " << _inputCurrencyTo << std::endl;

                        std::cout << "Enter amount in: " << _inputCurrencyFrom << std::endl;
                        std::cin >> _inputAmount;

                        auto buy = OperationSellBuy::BUY;
                        Exchanger transactionBuy(balance, buy, _inputCurrencyFrom, _inputAmount, _inputCurrencyTo);
                        std::cout << _inputCurrencyFrom << " RATE: " << transactionBuy.getRate() << std::endl;
                    }
                    else
                        std::cout << red << "Currency is incorect" << reset << std::endl;
                    break;
                }

                // transactionBuy.calculationPrint();
                
          } else    
            std::cout << "Sorry, access to this operation is denied!" << std::endl;
            break;

        case 3: // BALANCE
            if (loggedUser->getCanBalance()) //zmienić 
            {
                KantorDisplay_balanceTable tabBalance;
                tabBalance.dislayBalanceTable(balance);
                std::cout << std::endl;
  

            }
            else  
            std::cout << red << "Sorry, access to this operation is denied!" << reset << std::endl;
            break;

        case 4: //REPORTS
            if (loggedUser->getCanReport()) 
            {
                int reportNumber;
                Table reportsTable;
                std::string _operationName = "Select number to enter report of your choice: ";
               
                displayOperationName(_operationName);
                //std::cout <<  _operationName << std::endl;
                reportsTable.add_row({ "1.", "For users logger report" });
                reportsTable.add_row({ "2.", "For  daily transactions report" });
                reportsTable.add_row({ "3.", "For currency transactions report" });
                //reportsTable.add_row({ "4.", "For ...do not remember.. " });
               //reportsTable.add_row({ "0.", "Exit" });

                std::cout << reportsTable << std::endl;
                std::cin >> reportNumber;
                std::cout << std::endl << std::endl << std::endl;

                KantorDisplay_switchForReports temp;
                temp.displaySwitchForReports(reportNumber);
           
            }
            else  
            std::cout << red << "Sorry, access to this operation is denied!" << reset << std::endl;
            break;

        case 0: 
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
    LoggedUsersWriter logout;
    logout.writeToExistingFileLogout();
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
    const std::string blue("\033[0;37;44m");
    const std::string reset("\033[0m");

A: // znacznik miejsca skoku
    gotoxy(1, 1); // ustawienie karetki klawiatury w linii 1 i kolumnie 1
    WriteLine(title.size()); // rysuj� lini� ====== o d�ugo�ci r�wnej d�ugo�ci tekstu tytu�y menu
    std::cout << blue << title << reset<< std::endl; // wypisuj� menu
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



void Menu_Operations::displayOperationName(std::string _operationName)
{
    const std::string blue("\033[0;37;44m");
    const std::string reset("\033[0m");
   

    WriteLine(_operationName.size());
    std::cout << blue << _operationName << reset << std::endl;
   // std::cout  << _operationName <<std::endl;
    WriteLine(_operationName.size());

  
}

