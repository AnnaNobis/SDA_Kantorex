
#include <iostream>
#include "JSONLib/JSONReader.h"
#include "StaticLib_DisplayWindowsConsole/IKantorDisplay.h"
#include "StaticLib_DisplayWindowsConsole/Menu_Operations.h"
#include "../include_libraries/tabulate.hpp"
#include "../Kantorex_login/Kantorex.hpp"
#include "../ExhangerStaticLib/Exchanger.h"
#include "JSONLib/RawData.h"
#include "../ExhangerStaticLib/RateCurrrencyMap.h"
#include "JSONLib/ReadBuyRates.h"
#include "JSONLib/ReadSellRates.h"
#include "Kantorex_login/LogInManager.hpp"
#include "Kantorex_login/WriteJSONfile.hpp"
#include "Kantorex_login/Administrator.hpp"
#include "Report_Static_Library/ReportPrinter.hpp"

#include "Report_Static_Library/LoggedPrinter.hpp"

#include "../CashBalanceStaticLib/CashBalance.h"
#include "Kantorex_login/Authorization.hpp"

//using json = nlohmann::ordered_json;
using namespace tabulate;

int main()
{


	//LogInManager login;
	//login.checkUser();
	//std::shared_ptr<ILoggedUser> loggedUser = login.creatLoggedUser();
	//
	//system("cls"); //czy�ci ekran logowania

	//


	//Menu_Operations screen;
	//screen.displayMenuOperations(loggedUser);

	//drukowanie raportu 
	LoggedPrinter newReport;
	//newReport.ReadLoggReport("Maja");
	newReport.ReadLoggReportAll();
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;
	newReport.ReadLoggReportSurname("Sobieski");


	LogInManager login;
	login.checkUser();
	std::shared_ptr<ILoggedUser> loggedUser = login.creatLoggedUser();
	
	system("cls"); //czy�ci ekran logowania



	/*CashBalance balance(OperationSellBuy::BUY, "USD", 200000, "PLN");
	balance.showOpeningBalance();
	balance.checkCashRegister();*/


	//loggedUser->setCanBuy(0);
	//loggedUser->displayAllowedOperations();

	//UsersList list;
	//User user1;
	//user1 = list.getUser(1);

	//std::cout << std::endl;
	//login.displayLoggedUserInfo();



	/*LogInManager login;
	login.checkUser();
	std::shared_ptr<ILoggedUser> loggedUser = login.creatLoggedUser();
	std::vector<LoginData> vect = LoggedUsersReader::read();
	for_each(vect.begin(), vect.end(), [](LoginData d) {std::cout << d._name << "   " << d._surname << "   " << d._dateAndTime << "   " << d._isLogged << std::endl; });*/


	//std::vector<LoginData> vect = LoggedUsersReader::read();
	//for_each(vect.begin(), vect.end(), [](LoginData d) {std::cout << d._name << "   " << d._surname << "   " << d._dateAndTime << "   " << d._isLogged << std::endl; });

    //JSONReader dataReader;
    //dataReader.readCurrencies("JSONTabelaA.json");
    //dataReader.wypisz();
	//auto buy = OperationSellBuy::BUY;
	//auto sell = OperationSellBuy::SELL;

	//Exchanger first(OperationSellBuy::BUY, "USD", 200000, "PLN");
	//first.rate();
	//std::cout << std::endl;
	//first.calculationPrint();
	//Exchanger second(OperationSellBuy::SELL, "PLN", 30000, "USD");
	//second.rate();
	//std::cout << std::endl;
	//second.calculationPrint();







}

