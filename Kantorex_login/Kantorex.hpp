#pragma once
#include "Authorization.hpp"
#include "ICurrentUser.hpp"

class Kantorex : public Authorization
{
private:
	ICurrentUser* _currentUser;
public:
	Kantorex();
	ApplicationRole userAuthorization();
	ICurrentUser* creatCurrentUser(ApplicationRole appRole);
};

