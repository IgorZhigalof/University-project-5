#pragma once
#include <iostream>
#include <fstream>
#include "StudentClass.h"
#include <map>

class DatabaseService {
private:
    std::string filename;
    std::map<__int64, Student> students;

public:
    DatabaseService();

    bool update(Student student);

    std::map<__int64, Student> getAllStudents();

    Student getById(__int64 id);

    bool remove(__int64 id);

    bool commit();
};
