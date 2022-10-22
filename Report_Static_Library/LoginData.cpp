#include "pch.h"
#include "LoginData.h"

LoginData::LoginData(std::string name, std::string surname, std::string dateAndTime, bool isLogged):
	_name(name),
	_surname(surname),
	_dateAndTime(dateAndTime),
	_isLogged(isLogged)
{
}

LoginData::LoginData()
{
}
