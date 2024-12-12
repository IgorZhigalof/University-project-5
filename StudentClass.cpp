#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>
#include "StudentClass.h"

using namespace std;

bool isDate(std::string str1) {
	using std::string;
	int a, b, c;
	string str2;
	string str3;
	bool result;

	if (str1 == "-")
	{
		return true;
	}

	a = str1.find('.', 0);
	str2 = str1.substr(0, a);
	b = stoi(str2);
	str1.erase(0, a + 1);
	a = str1.find('.', 0);
	str3 = str1.substr(0, a);
	c = stoi(str3);
	if (c == 1 || c == 3 || c == 5 || c == 7 || c == 8 || c == 10 || c == 12) {
		if (b <= 31) {
			result = true;
		}
		else {
			result = false;
		}
	}
	else {
		if (c == 2 || c == 4 || c == 6 || c == 9 || c == 11) {
			if (b <= 30) {
				result = true;
			}
			else {
				result = false;
			}
		}
		else {
			result = false;
		}
	}
	return result;
}





std::vector<std::string> split(const std::string& line) {
	using std::string;
	using std::vector;

	auto iteratorStart = line.cbegin();
	auto iteratorEnd = std::find(iteratorStart, line.cend(), ' ');
	vector<string> splitted;

	while (iteratorStart != line.cend()) {
		splitted.emplace_back(iteratorStart, iteratorEnd - 1);
		if (iteratorEnd == line.cend()) break;
		iteratorStart = iteratorEnd + 1;
		iteratorEnd = std::find(iteratorStart, line.cend(), ' ');
	}

	return splitted;
}

Student::Student(__int64 id, std::string surname, std::string name, std::string secondName, std::string dateOfAdmission, __int16 specialtyCode) {
	if (name.empty())
	{
		throw invalid_argument("surname must not be empty");
	}
	if (isDate(dateOfAdmission))
	{
		throw invalid_argument("Date: " + dateOfAdmission + "does not match the format: DD.MM.YYYY");
	}
	this->surname = surname;
	this->name = name;
	this->secondName = secondName;
	this->dateOfAdmission = dateOfAdmission;
	this->studentId = id;
	this->specialtyCode = specialtyCode;
}

__int64 Student::getId() {
	return this->studentId;
}
	

string Student::toString() {
	string ln =
	#ifdef _WIN32
		"\r\n";
	#else
		"\n";
	#endif
	return this->surname + ln
		+ this->name + ln
		+ this->secondName + ln
		+ this->dateOfAdmission + ln
		+ to_string(this->studentId) + ln
		+ to_string(this->specialtyCode) + ln;
}

string Student::toString(string separator) {
	return this->surname + separator
		+ this->name + separator
		+ this->secondName + separator
		+ this->dateOfAdmission + separator
		+ to_string(this->studentId) + separator
		+ to_string(this->specialtyCode) + separator;
}

Student::Student(string line) {
	vector<string> values = split(line);

	if (values[1].empty())
	{
		throw invalid_argument("surname must not be empty");
	}
	if (!isDate(values[3]))
	{
		throw invalid_argument("Date: " + dateOfAdmission + "does not match the format: DD.MM.YYYY");
	}
	this->surname = values[0];
	this->name = values[1];
	this->secondName = values[2];
	this->dateOfAdmission = values[3];
	this->studentId = _atoi64(values[4].c_str());
	this->specialtyCode = _atoi64(values[5].c_str());
}