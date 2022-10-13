#pragma once
#include "User.hpp"
#include <vector>


class UsersList
{
private:
	std::vector<User> _usersList =
	{
		{"Maja","Kaleta"},
		{"Iri","Lilska"},
		{"Tomasz","Ultrecht"}
	};
public:
	//UsersList() // uruchomić, gdy pojawi się zapis do pliku. Na razie na sztywno.
	//	: User()
	//{}
	std::vector<User>& getUsersList();
	User getUser(int id);
	User getUser(std::string lastName);
	void addUser(std::string firstname, std::string lastname);
};

