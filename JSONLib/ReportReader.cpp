#include "pch.h"
#include "ReportReader.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "json/json.hpp"
using json = nlohmann::ordered_json;
//TODO podac ostateczna sciezke do pliku
std::string ReportReader::filePath = "freshReport.json";

void from_json(const json& j, ReportData& data) {
	j.at("date").get_to(data._date);
	j.at("time").get_to(data._time);
	j.at("currency_from").get_to(data._currencyFrom);
	j.at("amount_from").get_to(data._cashAmountFrom);
	j.at("currency_to").get_to(data._currencyTo);
	j.at("amount_to").get_to(data._cashAmountTo);
	j.at("transactionNumber").get_to(data._ID);
}



std::vector<ReportData> ReportReader::readReport()
{
	json j;
	std::ifstream stream(filePath);

	if (!stream.is_open())
	{
		std::cout << "Opening error" << std::endl;
	}

	stream >> j;
	stream.close();
	std::vector<ReportData> vect;

	for (auto& obj : j) {
		vect.push_back(obj);
	}
	return vect;
}

void ReportReader::changePath(std::string newPath)
{
	filePath = newPath;
}
