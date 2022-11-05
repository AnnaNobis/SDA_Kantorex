#pragma once
#include "../include_libraries/tabulate.hpp"
#include "IKantorDisplay.h"
#include "../Kantorex_login/LogInManager.hpp"
#include <iostream>
#include "../ExhangerStaticLib/ITransaction.h"
#include "../Kantorex_login/LogInManager.hpp"
#include "../Kantorex_login/ILoggedUser.hpp"
#include "../Kantorex_login/Administrator.hpp"
#include "../ExhangerStaticLib/Exchanger.h"
#include "Menu_Operations.h"

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

