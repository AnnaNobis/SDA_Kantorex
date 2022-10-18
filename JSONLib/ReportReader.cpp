#include "pch.h"
#include "ReportReader.h"
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

std::vector<ReportData> ReportReader::readReport(std::string filePath)
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