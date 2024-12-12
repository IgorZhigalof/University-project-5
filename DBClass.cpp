#include <iostream>
#include <fstream>
#include "StudentClass.h"
#include <map>
#include "DBClass.h"

using namespace std;


DatabaseService::DatabaseService() {
	this->filename = "data.txt";
	ifstream file;
	file.open(filename);
	string line;
	while (getline(file, line))
	{
		Student student(line);
		students[student.getId()] = student;
	}
}

bool DatabaseService::update(Student student) {
	students[student.getId()] = student;
	return true;
}

std::map<__int64, Student> DatabaseService::getAllStudents() {
	return students;
}

Student DatabaseService::getById(__int64 id) {
	return students[id];
}

bool DatabaseService::remove(__int64 id) {
	bool isThere = students.count(id);
	if (isThere) {
		students.erase(id);
	}
	return isThere;
}

bool DatabaseService::commit() {
	std::ofstream ofs(filename, std::ofstream::trunc);

	for (auto& kv : students) {
		ofs << kv.second.toString(" ");
	}

	ofs.close();

	return 0;
}

