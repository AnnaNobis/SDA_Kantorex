#pragma once
#include "../include_libraries/tabulate.hpp"
//#include "../Kantorex_login/Kantorex.hpp"

using namespace tabulate;

class IKantorDisplay
{
public:
	//void displayLogin();
	
	void displayCurrencyTable();

	void displayMenu();

	void reset(); //wraca do menu

	void dislayBalanceTable();

	void displaySellOperation();

	void displayBuyOperation();

	void displayExitScreen();

	void displayReportSelectionScreen();

	void WriteLine(unsigned int width);


};

