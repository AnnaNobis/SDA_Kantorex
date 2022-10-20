#include <iostream>
#include "JSONLib/JSONReader.h"
#include "StaticLib_DisplayWindowsConsole/IKantorDisplay.h"
#include "StaticLib_DisplayWindowsConsole/Menu_Operations.h"
#include "../include_libraries/tabulate.hpp"
#include "../Kantorex_login/Kantorex.hpp"
#include "JSONLib/ReadBuyRates.h"
#include "JSONLib/ReadSellRates.h"
#include "Kantorex_login/LogInManager.hpp"
#include "Kantorex_login/WriteJSONfile.hpp"
#include "Kantorex_login/Administrator.hpp"





using namespace tabulate;

int main()
{


	//IKantorDisplay window;
	//window.displayLogin();
	//system("cls"); //czy�ci ekran logowania

	LogInManager login;
	login.checkUser();
	std::shared_ptr<ILoggedUser> loggedUser = login.creatLoggedUser();

	
	system("cls"); //czy�ci ekran logowania


	//// IKantorDisplay window;
 //  //window.displayCurrencyTable();


	//Menu_Operations screen;
	//screen.displayMenuOperations();

	Menu_Operations screen;
	screen.displayMenuOperations(loggedUser);

 //   JSONReader dataReader;
 //   dataReader.readCurrencies("JSONTabelaA.json");
 //   dataReader.wypisz();
	//ReadSellRates r;
	//r.read("TabelaC.json");
	//std::cout << "---------------------------------" << std::endl;
	//ReadBuyRates b;
	//b.read();
}

