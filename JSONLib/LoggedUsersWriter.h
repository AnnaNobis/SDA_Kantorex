#pragma once
#include <string>
#include "../Report_Static_Library/LoginData.h"
#include "../Report_Static_Library/Time.hpp"
#include "../Report_Static_Library/Date.hpp"
class LoggedUsersWriter
{
	//tu nalezy przekazac data i czas bezposrednio z plikow Mileny 
//zmienic konstruktory tak, zeby przyjmowaly tylko 2 argumenty od magdy
	// na koncu maina wywolac wylogowanie z aplikacji do pliku
	//RawDate _raw;
	//Time _t;
	std::string dateAndTime;
	static std::string filePath;
	static bool checkIfFileExist();
	static void writeNewFile(LoginData login);
	static void writeToExistingFile(LoginData login);
public:
	LoggedUsersWriter() {
		RawDate r;
		dateAndTime = r.getDate();
	}
	void write(std::string userName, std::string userSurname, bool isLogged);

	void writeToExistingFileLogout();
};

