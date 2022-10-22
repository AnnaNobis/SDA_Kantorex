#pragma once
#include <string>
struct LoginData
{
	std::string _name;
	std::string _surname;
	std::string _dateAndTime;
	bool _isLogged;
	LoginData(std::string name, std::string surname, std::string dateAndTime, bool isLogged);
	LoginData();
};

