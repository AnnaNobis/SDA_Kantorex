#include "pch.h"
#include "IKantorDisplay.h"
#include "../Kantorex_login/LogInManager.hpp"
#include <iostream>

void IKantorDisplay::displayLogin()
{
	//Kantorex session;
	//ApplicationRole appRole = session.userAuthorization();
	//std::shared_ptr<LogInManager> currentUser = session.creatLoggedUser(appRole)
	//currentUser->displayLoggedUserInfo();
	
}

void IKantorDisplay::displayCurrencyTable()
{
	Table currenciesTable;

	currenciesTable.add_row({ "SYM", "COUNTRY", "CURRENCY", "UNIT", "CURRENCY BALANCE", "BUY", "SELL" });
	currenciesTable.add_row({ "USD", "USA", "dolar", "100", "10000", "5.20", "4.90" });
	currenciesTable.add_row({ "EUR", "Europa", "euro", "100", "5000", "5.00", "4.50" });
	currenciesTable.add_row({ "CHF", "Szwajcaria", "frank szwajcarski", "100", "20000", "5.50", "5.00" });

	// center align 'Director' column
	currenciesTable.column(2).format()
		.font_align(FontAlign::center);

	// right align 'Estimated Budget' column
	currenciesTable.column(3).format()
		.font_align(FontAlign::right);

	// right align 'Release Date' column
	currenciesTable.column(4).format()
		.font_align(FontAlign::right);

	// center-align and color header cells
	for (size_t i = 0; i < 7; ++i)
	{
		currenciesTable[0][i].format()
			.font_color(Color::yellow)
			.font_align(FontAlign::center)
			.font_style({ FontStyle::bold });
	}

	std::cout << currenciesTable << std::endl;
	std::cout << std::endl << std::endl << std::endl;

}

void IKantorDisplay::displayMenu()
{
	// struktura która przyjmuje
	{
		Table choiceTable;

		choiceTable.add_row({ "1.", "For exchange currency  -  SELL operiation" });
		choiceTable.add_row({ "2.", "For exchange currency  -  BUY operiation" });
		choiceTable.add_row({ "3.", "Balance" });
		choiceTable.add_row({ "4.", "Reports" });
		choiceTable.add_row({ "5.", "Exit" });

		std::cout << choiceTable << std::endl;
		std::cout << std::endl << std::endl << std::endl;

	}
}

void IKantorDisplay::reset()
{
	displayMenu();
}

void IKantorDisplay::dislayBalanceTable()
{
}

void IKantorDisplay::displaySellOperation()
{

}

void IKantorDisplay::displayBuyOperation()
{
}

void IKantorDisplay::displayExitScreen()
{
	//tutaj powinien byæ balance table

}
