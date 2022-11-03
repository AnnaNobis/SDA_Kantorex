#include <iostream>
#include "StaticLib_DisplayWindowsConsole/Manager_start.h"

//using json = nlohmann::ordered_json;
using namespace tabulate;



int main()
{

	Manager_start start;
	start.startProgram();
}















	//int attempts = 0;
	//KantorDisplay_login login;
	//std::shared_ptr<ILoggedUser> loggedUser;
	//do
	//{
	//	loggedUser = login.displayLogin();
	//	attempts++;

	//} while (attempts < 3 && loggedUser == nullptr);

	//if (loggedUser != nullptr)
	//{
	//	system("cls");
	//	Menu_Operations screen;
	//	screen.displayMenuOperations(loggedUser);
	//}


	/*KantorDisplay_login kantor;
	int attempts = 0;
	std::shared_ptr<ILoggedUser>  loggedUser = kantor.displayLogin();
	do
	{
		loggedUser = kantor.displayLogin();
	} while
	{};*/


	////drukowanie raportu 
	//LoggedPrinter newReport;
	////newReport.ReadLoggReport("Maja");
	//newReport.ReadLoggReportAll();
	//std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;
	//newReport.ReadLoggReportSurname("Sobieski");


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



//std::shared_ptr<ILoggedUser> displayLogin()
//{
//	LogInManager login;
//	login.checkUser();
//	if (login.isUnknown())
//	{
//		return nullptr;
//	}
//	else
//	{
//		return login.creatLoggedUser();
//	}
//}
// 
// 
// //#include "JSONLib/JSONReader.h"
//#include "StaticLib_DisplayWindowsConsole/IKantorDisplay.h"
//#include "StaticLib_DisplayWindowsConsole/Menu_Operations.h"
//#include "../include_libraries/tabulate.hpp"
//#include "../Kantorex_login/Kantorex.hpp"
//#include "../ExhangerStaticLib/Exchanger.h"
//#include "JSONLib/RawData.h"
//#include "../ExhangerStaticLib/RateCurrrencyMap.h"
//#include "JSONLib/ReadBuyRates.h"
//#include "JSONLib/ReadSellRates.h"
//#include "Kantorex_login/LogInManager.hpp"
//#include "Kantorex_login/WriteJSONfile.hpp"
//#include "Kantorex_login/Administrator.hpp"
//#include "Report_Static_Library/ReportPrinter.hpp"
//#include "Report_Static_Library/LoggedPrinter.hpp"
//#include "../CashBalanceStaticLib/CashBalance.h"
//#include "Kantorex_login/Authorization.hpp"
//#include "../StaticLib_DisplayWindowsConsole/KantorDisplay_login.h"