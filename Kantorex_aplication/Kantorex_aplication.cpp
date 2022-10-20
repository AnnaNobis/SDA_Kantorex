
#include <iostream>
#include "JSONLib/JSONReader.h"
#include "StaticLib_DisplayWindowsConsole/IKantorDisplay.h"
#include "StaticLib_DisplayWindowsConsole/Menu_Operations.h"
#include "../include_libraries/tabulate.hpp"
#include "../Kantorex_login/Kantorex.hpp"
#include "../ExhangerStaticLib/Exchanger.h"
#include "JSONLib/RawData.h"
#include "../ExhangerStaticLib/RateCurrrencyMap.h"


using namespace tabulate;

int main()
{
	auto buy = OperationSellBuy::BUY;
	auto sell = OperationSellBuy::SELL;

	Exchanger firstBuy(buy);
//
//	IKantorDisplay window;
//	window.displayLogin();
//	system("cls"); //czyœci ekran logowania
//
//	// IKantorDisplay window;
//   //window.displayCurrencyTable();
//
//	Menu_Operations screen;
//	screen.displayMenuOperations();
//
//    JSONReader dataReader;
//    dataReader.readCurrencies("JSONTabelaA.json");
//    dataReader.wypisz();
}

