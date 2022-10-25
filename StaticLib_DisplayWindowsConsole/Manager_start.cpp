#include "pch.h"
#include "Manager_start.h"
#include "KantorDisplay_login.h"

void Manager_start::startProgram()
{
	int attempts = 0;
	KantorDisplay_login login;
	std::shared_ptr<ILoggedUser> loggedUser;
	do
	{
		loggedUser = login.displayLogin();
		attempts++;

	} while (attempts < 3 && loggedUser == nullptr);

	if (loggedUser != nullptr)
	{
		system("cls");
		Menu_Operations screen;
		screen.displayMenuOperations(loggedUser);
	}
}
