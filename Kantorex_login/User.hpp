#pragma once
#include <string>
//#include "../include_libraries/json.hpp"

enum class ApplicationRole
{
	ADMINISTRATOR,
	CASHIER,
	GUEST
};

class User
{
private:
	static int _counter;
	std::string _id;
	std::string _firstname;
	std::string _lastname;
	std::string _login;
	std::string _password;
	ApplicationRole _applicationRole;
public:
	User(std::string firstname = "Joe", std::string lastname="Doe", std::string login="jDoe", std::string password="1111", ApplicationRole applicationRole = ApplicationRole::GUEST)
		: _firstname(firstname)
		, _lastname(lastname)
		, _login(login)
		, _password(password)
		, _applicationRole(applicationRole)
	{
		_id = std::to_string(++_counter);
	}
	void setUserId(std::string id);
	void setUserFirstname(std::string firstname);
	void setUserLastname(std::string lastname);
	void setLogin(std::string login);
	void setPassword(std::string password);
	void setApplicationRole(ApplicationRole applicatioRole);
	std::string getUserId() const;
	std::string getUserFirstname() const;
	std::string getUserLastname() const;
	std::string getLogin() const;
	std::string getPassword() const;
	std::string getAppRole_str() const;
	ApplicationRole getAppRole_enum() const;
	std::string enumToString(ApplicationRole appRole) const;
	static ApplicationRole stringToEnum(std::string appRole);
	//virtual~User();
};