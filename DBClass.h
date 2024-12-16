#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include "EmployerClass.h"

class DatabaseService {
private:
    std::string filename;
    std::map<__int64, Employer> employers;

public:
    DatabaseService();
    bool update(Employer student);
    std::map<__int64, Employer> getAllEmployers();
    Employer getById(__int64 id);
    bool remove(__int64 id);
    bool commit();
};
