#pragma once
#include "../include_libraries/tabulate.hpp"
//#include "../Kantorex_login/Kantorex.hpp"

using namespace tabulate;

class IKantorDisplay
{
public:
	virtual void WriteLine(unsigned int width);

	void displayMenu();

	void reset(); //wraca do menu
	
	void displayExitScreen();

	//void displaySellOperation();
	//void displayBuyOperation();

	void displayReportSelectionScreen();

};

