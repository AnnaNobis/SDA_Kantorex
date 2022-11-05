#pragma once
#include <string>

enum class ApplicationRole
{
	ADMINISTRATOR,
	CASHIER,
	GUEST,
	UNKNOWN
};

class User
{
private:
	std::string _id;
	std::string _firstname;
	std::string _lastname;
	std::string _login;
	std::string _password;
	ApplicationRole _applicationRole;
public:
	User(std::string id = "0", std::string firstname = "Joe", std::string lastname = "Doe", std::string login = "jDoe", std::string password = "1111", ApplicationRole applicationRole = ApplicationRole::GUEST)
		: _id(id)
		, _firstname(firstname)
		, _lastname(lastname)
		, _login(login)
		, _password(password)
		, _applicationRole(applicationRole)
	{
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
};