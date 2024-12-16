#pragma once
#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>
#include "DTO.h"

using namespace std;

class Employer {
private:
    _int64 IIAN;
    std::string surname;
    std::string name;
    std::string secondName;
    std::string birthday;
    __int64 passport;
    __int16 taxAmount;

public:
    Employer(__int64 IIAN, std::string surname, std::string name, std::string secondName, _int64 passport, std::string birthday, __int64 taxAmount);
    Employer(std::string line);
    Employer() = default;

    __int64 getId();
    std::string toString();
    std::string toString(std::string separator);
};