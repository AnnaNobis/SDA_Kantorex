
#include <iostream>
#include "JSONLib/JSONReader.h"
#include "StaticLib_DisplayWindowsConsole/IKantorDisplay.h"
#include "StaticLib_DisplayWindowsConsole/Menu_Operations.h"
#include "../include_libraries/tabulate.hpp"
#include "../Kantorex_login/Kantorex.hpp"
#include "../ExhangerStaticLib/Exchanger.h"
#include "JSONLib/RawData.h"
#include "../ExhangerStaticLib/RateCurrrencyMap.h"
#include "JSONLib/ReadBuyRates.h"
#include "JSONLib/ReadSellRates.h"
#include "Kantorex_login/LogInManager.hpp"
#include "Kantorex_login/WriteJSONfile.hpp"
#include "Kantorex_login/Administrator.hpp"
#include "../JSONLib/LoggedUsersReader.h"




//using json = nlohmann::ordered_json;


using namespace tabulate;

int main()
{
	//IKantorDisplay window;
	//window.displayLogin();
	//system("cls"); //czy�ci ekran logowania


	LogInManager login;
	login.checkUser();
	std::shared_ptr<ILoggedUser> loggedUser = login.creatLoggedUser();


	//std::vector<LoginData> vect = LoggedUsersReader::read();
	//for_each(vect.begin(), vect.end(), [](LoginData d) {std::cout << d._name << "   " << d._surname << "   " << d._dateAndTime << "   " << d._isLogged << std::endl; });

	system("cls"); //czy�ci ekran logowania

	Menu_Operations screen;
	screen.displayMenuOperations(loggedUser);

    //JSONReader dataReader;
    //dataReader.readCurrencies("JSONTabelaA.json");
    //dataReader.wypisz();
	//auto buy = OperationSellBuy::BUY;
	//auto sell = OperationSellBuy::SELL;

	//Exchanger first(OperationSellBuy::SELL, "PLN", 100, "HUF");
	//first.rate();
	//std::cout << std::endl;
	//first.calculationPrint();


	//system("cls"); //czy�ci ekran logowania

	//// IKantorDisplay window;
 //  //window.displayCurrencyTable();

	//Menu_Operations screen;
	//screen.displayMenuOperations(loggedUser);

 //   JSONReader dataReader;
 //   dataReader.readCurrencies("JSONTabelaA.json");
 //   dataReader.wypisz();

}

