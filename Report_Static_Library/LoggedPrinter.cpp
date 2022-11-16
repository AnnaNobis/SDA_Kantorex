#include "pch.h"
#include "LoggedPrinter.hpp"

LoggedPrinter::LoggedPrinter()
{
	loggedData = dataFromFile.read();
}

std::vector<LoginData> LoggedPrinter::ReadLoggReportAll()
{

	/*std::for_each(loggedData.begin(), loggedData.end(), [](LoginData l) {
		std::string loggStatus;
		if (l._isLogged == 0)
		{
			loggStatus = "log out";
		}
		else
		{
			loggStatus = "log in";
		}
		std::cout << std::endl
			<< "name: " << l._name
			<< "    surname: " << l._surname
			<< "    dateAndTime: " << l._dateAndTime
			<< "    operation: " << loggStatus
			<< std::endl; });*/
	return loggedData;
}

void LoggedPrinter::ReadLoggReportSurname(std::string requestedSurname)
{

	std::vector<LoginData> tmp_data(loggedData.size());

	auto it = std::copy_if(loggedData.begin(), loggedData.end(), tmp_data.begin(), [&](LoginData r)
		{

			return r._surname == requestedSurname;
		});

	tmp_data.resize(std::distance(tmp_data.begin(), it));

	//std::cout << std::endl << "################Logged user report for: " << requestedSurname << " ################" << std::endl;

	std::for_each(tmp_data.begin(), tmp_data.end(), [](LoginData l) {
		std::string loggStatus;
		if (l._isLogged == 0)
		{
			loggStatus = "log out";
		}
		else
		{
			loggStatus = "log in";
		}
		std::cout << std::endl
			<< "name: " << l._name
			<< "    surname: " << l._surname
			<< "    dateAndTime: " << l._dateAndTime
			<< "    operation: " << loggStatus
			<< std::endl; });

}


