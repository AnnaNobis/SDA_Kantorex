#pragma once
#include "Authorization.hpp"
#include "ILoggedUser.hpp"
#include <memory>

class Kantorex : public Authorization
{
public:
	ApplicationRole userAuthorization();
	std::shared_ptr<ILoggedUser> creatLoggedUser(ApplicationRole appRole);
};

