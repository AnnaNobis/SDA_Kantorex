#include "pch.h"
#include "IKantorDisplay.h"
#include "../Kantorex_login/LogInManager.hpp"
#include <iostream>
#include "../ExhangerStaticLib/ITransaction.h"
#include "../Kantorex_login/LogInManager.hpp"
#include "../Kantorex_login/ILoggedUser.hpp"
#include "../Kantorex_login/Administrator.hpp"
#include "../ExhangerStaticLib/Exchanger.h"
#include "Menu_Operations.h"

void IKantorDisplay::WriteLine(unsigned int width)
{

		for (unsigned int i = 0; i < width; i++)
		{
			std::cout << "="; // width  wypisuje =
		}
		std::cout << std::endl;
	
}

void IKantorDisplay::displayMenu()
{
}

void IKantorDisplay::reset()
{
	displayMenu();
}


void IKantorDisplay::displayExitScreen()
{
	//tutaj powinien by� balance table

}

void IKantorDisplay::displayReportSelectionScreen()
{
	/*int reportNumber;
	Table reportsTable;

	std::cout << "Select number to enter report of your choice: " << std::endl;
	reportsTable.add_row({ "1.", "For users logger report" });
	reportsTable.add_row({ "2.", "For transactions report" });
	reportsTable.add_row({ "3.", "For ...do not remember.. " });
	reportsTable.add_row({ "0.", "Exit" });

	std::cout << reportsTable << std::endl;
	std::cin >> reportNumber;
	std::cout << std::endl << std::endl << std::endl;*/

}