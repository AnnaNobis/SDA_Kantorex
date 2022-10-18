#include <iostream>
#include "JSONLib/JSONReader.h"
#include "StaticLib_DisplayWindowsConsole/IKantorDisplay.h"
#include "StaticLib_DisplayWindowsConsole/Menu_Operations.h"
#include "../include_libraries/tabulate.hpp"
#include "../Kantorex_login/Kantorex.hpp"

using namespace tabulate;

int main()
{

	IKantorDisplay window;
	window.displayLogin();
	system("cls"); //czyœci ekran logowania

	// IKantorDisplay window;
   //window.displayCurrencyTable();

	Menu_Operations screen;
	screen.displayMenuOperations();

    JSONReader dataReader;
    dataReader.readCurrencies("JSONTabelaA.json");
    dataReader.wypisz();
}

