#pragma once
#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>

using namespace std;

class Student {
private:
    std::string surname;
    std::string name;
    std::string secondName;
    std::string dateOfAdmission;
    __int64 studentId;
    __int16 specialtyCode;

public:
    Student(__int64 id, std::string surname, std::string name, std::string secondName, std::string dateOfAdmission, __int16 specialtyCode);
    Student(std::string line);
    Student() = default;

    __int64 getId();
    std::string toString();
    std::string toString(std::string separator);
};