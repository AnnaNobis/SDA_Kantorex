#pragma once
#include <string>
//#include "../include_libraries/json.hpp"


class User
{
private:
	static int _counter;
	std::string _id;
	std::string _firstname;
	std::string _lastname;
public:
	User(std::string firstname, std::string lastname)
		: _firstname(firstname)
		, _lastname(lastname)
	{
		_id = std::to_string(++_counter);
	}
	User() {}
	std::string getUserId() const;
	std::string getUserFirstname() const;
	std::string getUserLastname() const;
	void setUserFirstname(std::string firstname);
	void setUserLastname(std::string lastname);

};