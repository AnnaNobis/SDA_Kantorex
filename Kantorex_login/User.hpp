#pragma once
#include <string>

class User
{
private:
	static int _id;
	std::string _firstname;
	std::string _lastname;
public:
	User(std::string firstname, std::string lastname)
		: _firstname(firstname)
		, _lastname(lastname)
	{
		_id++;
	}

	User()
		: User("ND", "ND")
	{}

	int getUserId();
	std::string getUserFirstname();
	std::string getUserLastname();
	void setUserFirstname(std::string firstname);
	void setUserLastname(std::string lastname);

};

