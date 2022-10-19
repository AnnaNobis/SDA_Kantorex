#include "pch.h"
#include "JSONReportWriter.hpp"
#include <fstream>
#include "json/json.hpp"
#include <memory>

using json = nlohmann::json;

std::string JSONReportWriter::filePath = "json.json";

void to_json(json& j, const ReportData& data) {
	j = {
	{"transactionNumber", data._ID},
	{"date", data._date},
	{"time", data._time},
	{"currency", data._currency},
	{"amount", data._cashAmount},
	{"user", data._userId} };
}

bool JSONReportWriter::checkIfFileExist(std::string filePath)
{
	std::ifstream checkedFile(filePath);
	return checkedFile.good();
}

//JSONReportWriter::JSONReportWriter()
//{
//}

void JSONReportWriter::writeReport(std::string filePath, ReportData data)
{
	if (checkIfFileExist(filePath)) {
		writeToExistingReport(filePath, data);
	}
	else {
		writeNewReport(filePath, data);
	}

	//std::ofstream stream(filePath);
	//json report;
	////std::shared_ptr<json>  newEntry = std::make_shared<json>();


	//report[data._ID] = {
	//	{"date", data._date},
	//	{"time", data._time},
	//	{"currency", data._currency},
	//	{"amount", data._cashAmount},
	//	{"user", data._userId} };

	//stream << std::setw(4) << report << std::endl;
}
void JSONReportWriter::writeNewReport(std::string filePath, ReportData data)
{
	std::ofstream stream(filePath);
	json j;
	std::vector<ReportData> vectorToWrite;
	vectorToWrite.push_back(data);
	j = json(vectorToWrite);
	stream << std::setw(4) << j << std::endl;
}
void JSONReportWriter::writeToExistingReport(std::string filePath, ReportData data)
{
	std::vector<ReportData>fileData = JSONReportReader::readReport(filePath);
	fileData.push_back(data);

	std::ofstream stream(filePath);
	json j;
	j = json(fileData);
	stream << std::setw(4) << j << std::endl;
}
//void to_json(json& j, const Employee& e) {
//	j = { {"firstName", e.getName()}, {"lastName", e.getSurname()}, {"email", e.getEmail()}, {"gender", Employee::toString(e.getGender())}, {"salary", e.getSalary()} };
