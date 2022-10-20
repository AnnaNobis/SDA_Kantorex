#include "pch.h"
#include "JSONReportReader.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "json/json.hpp"

using json = nlohmann::json;

void from_json(const json& j, ReportData& data) {
	j.at("date").get_to(data._date);
	j.at("time").get_to(data._time);
	j.at("currency").get_to(data._currency);
	j.at("amount").get_to(data._cashAmount);
	j.at("user").get_to(data._userId);
	j.at("transactionNumber").get_to(data._ID);
}

std::vector<ReportData> JSONReportReader::readReport(std::string filePath)
{
	json j;
	std::ifstream stream(filePath);
	//j = json::parse(stream);

	if (!stream.is_open())
	{
		std::cout << "Couldn't open file" << std::endl;
	}

	stream >> j;
	stream.close();
	std::vector<ReportData> vect;
	for (auto& obj : j) {
		vect.push_back(obj);
	}
	//std::string amount;
	//std::string currency;
	//std::string date;
	//std::string time;
	//std::string userId;
	//ReportData temp;
	//for (auto& elemen : j)
	//{
	//	//std::cout << elemen << std::endl;
	//	amount = elemen["amount"];
	//	currency = elemen["currency"];
	//	date = elemen["date"];
	//	time = elemen["time"];
	//	userId = elemen["user"];

	//	temp._cashAmount = amount;
	//	temp._currency = currency;
	//	temp._date = date;
	//	temp._time = time;
	//	temp._userId = userId;
	//	vect.emplace_back(temp);
	//}

	//std::for_each(vect.begin(), vect.end(), [](ReportData r) {
	//	std::cout << std::endl << "data: " << r._date << "    time: " << r._time << std::endl; });

	return vect;
}
