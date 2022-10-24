#include "pch.h"
#include "ReportData.hpp"
#include "Time.hpp"
#include "RawDate.hpp"
#include "Date.hpp"

int ReportData::count/* = 0*/;
ReportData::ReportData(/*std::string date,*/ /*std::string time,*/ 
	std::string currencyFrom, double cashAmountFrom, std::string currencyTo, double cashAmountTo/*, std::string userId*/):
	/*_date(date),*/
	/*_time(time),*/
	_currencyFrom(currencyFrom),
	_cashAmountTo(cashAmountTo),
	_currencyTo(currencyTo),
	_cashAmountFrom(cashAmountFrom)/*,
	_userId(userId)*/
{
	

	RawDate raw;
	Date date(raw);
	_date = date.get_date();
	Time time(raw);
	_time = time.get_time();

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