#include "pch.h"
#include "ReportData.hpp"
int ReportData::count = 0;
ReportData::ReportData(std::string date, std::string time, std::string currency, double cashAmount, std::string userId):
	_date(date),
	_time(time),
	_currency(currency),
	_cashAmount(cashAmount),
	_userId(userId)
{
	count++;
	setID();
	//setNewId();
}

ReportData::ReportData()
{
}

//void ReportData::setNewId()
//{
//	int tmpId = std::stoi(_ID);
//	tmpId++;
//	_ID = std::to_string(tmpId);
//}

std::string ReportData::getDate()
{
	return _date;
}

void ReportData::setID()
{
	_ID = std::to_string(count);
}