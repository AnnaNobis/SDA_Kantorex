#include <iostream>
#include "JSONLib/JSONReader.h"
#include "StaticLib_DisplayWindowsConsole/IKantorDisplay.h"
#include "StaticLib_DisplayWindowsConsole/Menu_Operations.h"
#include "../include_libraries/tabulate.hpp"
#include "../Kantorex_login/Kantorex.hpp"
#include "Kantorex_login/LogInManager.hpp"
#include "Kantorex_login/WriteJSONfile.hpp"

using namespace tabulate;

int main()
{

	//LogInManager login;
	//login.checkUser();
	//std::shared_ptr<ILoggedUser> loggedUser = login.creatLoggedUser();

	IKantorDisplay window;
	window.displayLogin();
	system("cls"); //czy�ci ekran logowania

	// IKantorDisplay window;
   //window.displayCurrencyTable();

	Menu_Operations screen;
	screen.displayMenuOperations();

    JSONReader dataReader;
    dataReader.readCurrencies("JSONTabelaA.json");
    dataReader.wypisz();
}

