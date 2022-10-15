#include <iostream>
//#include "framework.h"  przykładowy
#include "Kantorex.hpp"
#include "tabulate.hpp"

using namespace tabulate;


int main()
{
    Kantorex session;
    ApplicationRole appRole = session.userAuthorization();
    std::shared_ptr<ICurrentUser> currentUser = session.creatCurrentUser(appRole);
    currentUser->displayStartScreen();
}