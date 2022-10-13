#include <iostream>
//#include "framework.h"  przykładowy
#include "Kantorex.hpp"
//#include "tabulate/table.hpp"
//
//using namespace tabulate;


int main()
{
    Kantorex session;
    ApplicationRole appRole = session.userAuthorization();
    ICurrentUser* currentUser = session.creatCurrentUser(appRole);
    currentUser->displayStartScreen();
    delete currentUser;
}