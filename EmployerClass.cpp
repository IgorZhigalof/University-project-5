#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>
#include "EmployerClass.h"

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
		splitted.emplace_back(iteratorStart, iteratorEnd);
		if (iteratorEnd == line.cend()) {
			break;
		}
		iteratorStart = iteratorEnd + 1; 
		iteratorEnd = std::find(iteratorStart, line.cend(), ' ');
	}

	return splitted;
}

Employer::Employer(__int64 IIAN, std::string surname, std::string name, std::string secondName, _int64 passport, std::string birthday, __int64 taxAmount) {
	if (name.empty())
	{
		throw invalid_argument("surname must not be empty");
	}
	if (isDate(birthday))
	{
		throw invalid_argument("Date: " + birthday + "does not match the format: DD.MM.YYYY");
	}
	this->IIAN = IIAN;
	this->surname = surname;
	this->name = name;
	this->secondName = secondName;
	this->birthday = birthday;
	this->passport = passport;
	this->taxAmount = taxAmount;
}

__int64 Employer::getId() {
	return this->passport;
}
	

string Employer::toString() {
	string ln =
	#ifdef _WIN32
		"\r\n";
	#else
		"\n";
	#endif
	return to_string(this->IIAN) + ln
		+ this->surname + ln
		+ this->name + ln
		+ this->secondName + ln
		+ to_string(this->passport) + ln
		+ birthday + ln
		+ to_string(this->taxAmount) + ln;
}

string Employer::toString(string separator) {
	return to_string(this->IIAN) + separator
		+ this->surname + separator
		+ this->name + separator
		+ this->secondName + separator
		+ to_string(this->passport) + separator
		+ birthday + separator
		+ to_string(this->taxAmount) + separator;
}

Employer::Employer(string line) {
	vector<string> values = split(line);

	if (values.size() < 7) {
		throw std::invalid_argument("input: " + line + "doesn't match the template: IIAN Surname Name SecondName Passport Birthday TaxAmount");
	}

	if (values[1].empty())
	{
		throw invalid_argument("surname must not be empty");
	}
	if (!isDate(values[5]))
	{
		throw invalid_argument("Date: " + birthday + "does not match the format: DD.MM.YYYY");
	}
	this->IIAN = atol(values[0].c_str());
	this->surname = values[1];
	this->name = values[2];
	this->secondName = values[3];
	this->passport = _atoi64(values[4].c_str());
	this->birthday = values[5];
	this->taxAmount = _atoi64(values[6].c_str());
}