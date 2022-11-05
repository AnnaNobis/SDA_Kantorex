#include <iostream>
#include "StaticLib_DisplayWindowsConsole/Manager_start.h"

#include "JSONLib/ReadSellAndBuyTable.h"
//using json = nlohmann::ordered_json;

using namespace tabulate;

int main()
{
KlaudiaNNN
	ReadSellAndBuyTable tab;
	tab.read();

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

	Manager_start start;
	start.startProgram();

}













