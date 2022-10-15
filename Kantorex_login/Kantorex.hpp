#pragma once
#include "Authorization.hpp"
#include "ICurrentUser.hpp"
#include <memory>

class Kantorex : public Authorization
{
private:
	//std::shared_ptr<ICurrentUser> _currentUser;
	//ICurrentUser* _currentUser_;
public:
	Kantorex();
	ApplicationRole userAuthorization();
	//ICurrentUser* creatCurrentUser(ApplicationRole appRole);
	std::shared_ptr<ICurrentUser> creatCurrentUser(ApplicationRole appRole);
};

