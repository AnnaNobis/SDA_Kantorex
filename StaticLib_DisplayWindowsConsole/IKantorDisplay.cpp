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
#include "../Report_Static_Library/ReportPrinter.hpp"


//void IKantorDisplay::displayLogin()
//{
//    LogInManager login;
//	login.checkUser();
//	//std::shared_ptr<ILoggedUser> loggedUser = login.creatLoggedUser();
//}

void IKantorDisplay::displayCurrencyTable()
{
	Table currenciesTable;

	//

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

void IKantorDisplay::WriteLine(unsigned int width)
{
	{
		for (unsigned int i = 0; i < width; i++)
		{
			std::cout << "="; // width razy wypisuj� =
		}
		std::cout << std::endl;
	}
}

void IKantorDisplay::displaySwitchForReports(int reportNumber)
{

	switch (reportNumber)
	{
	case 1: //users logger report
	{std::cout << "Users logger report" << std::endl;
	break;
	}

    case 2: //daily transaction report
	{
		Table reportTransaction;
		ReportPrinter newReport;
		std::cout << "Enter report date, format: dd.mm.yyyy " << std::endl;
		std::string _reportDate;
		std::cin >> _reportDate;
		auto data = newReport.ReadDailyReport(_reportDate);
		reportTransaction.add_row({ "TRANSACTION NO", "DATE","TIME","CURRENCY FROM" ,"CASH AMOUNT FROM ","CURRENCY TO","CASH AMOUNT TO" });
		std::for_each(data.begin(), data.end(), [&](ReportData l) 
			{std::string tmp_data = l._ID;
		std::string tmp_date = l._date;
		std::string tmp_time = l._time;
		std::string tmp_currency_from = l._currencyFrom;
		std::string tmp_cash_from = std::to_string (l._cashAmountFrom);
		std::string tmp_currency_to = l._currencyTo;
		std::string tmp_cash_to = std::to_string(l._cashAmountTo);
		reportTransaction.add_row({ tmp_data, tmp_date, tmp_time, tmp_currency_from, tmp_cash_from, tmp_currency_to , tmp_cash_to }); } );
		
		std::cout << reportTransaction << std::endl;
		std::cout << std::endl << std::endl << std::endl;

		break;
	}

	case 3://currency transaction report

		Table reportTransaction2;
		ReportPrinter newReport;
		std::cout << "Enter currency code: e.g. USD, to enter currency report. " << std::endl;
		std::string _reportCurrency;
		std::cin >> _reportCurrency;
		auto data = newReport.ReadCurrencyReport(_reportCurrency);
		reportTransaction2.add_row({ "TRANSACTION NO", "DATE","TIME","CURRENCY FROM" ,"CASH AMOUNT FROM ","CURRENCY TO","CASH AMOUNT TO" });
		std::for_each(data.begin(), data.end(), [&](ReportData l)
			{std::string tmp_data = l._ID;
		std::string tmp_date = l._date;
		std::string tmp_time = l._time;
		std::string tmp_currency_from = l._currencyFrom;
		std::string tmp_cash_from = std::to_string(l._cashAmountFrom);
		std::string tmp_currency_to = l._currencyTo;
		std::string tmp_cash_to = std::to_string(l._cashAmountTo);
		reportTransaction2.add_row({ tmp_data, tmp_date, tmp_time, tmp_currency_from, tmp_cash_from, tmp_currency_to , tmp_cash_to }); });

		std::cout << reportTransaction2 << std::endl;
		std::cout << std::endl << std::endl << std::endl;

		break;

	}
}

