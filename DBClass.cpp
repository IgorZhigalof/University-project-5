#include <iostream>
#include <fstream>
#include <map>
#include "DBClass.h"
#include "EmployerClass.h"

using namespace std;


DatabaseService::DatabaseService() {
	this->filename = "data.txt";
	ifstream file;
	file.open(filename);
	string line;
	while (getline(file, line))
	{
		Employer employer(line);
		employers[employer.getId()] = employer;
	}
}

bool DatabaseService::update(Employer student) {
	employers[student.getId()] = student;
	return true;
}

std::map<__int64, Employer> DatabaseService::getAllElements() {
	return employers;
}

Employer DatabaseService::getById(__int64 id) {
	return employers[id];
}

bool DatabaseService::remove(__int64 id) {
	bool isThere = employers.count(id);
	if (isThere) {
		employers.erase(id);
	}
	return isThere;
}

bool DatabaseService::commit() {
	std::ofstream ofs(filename, std::ofstream::trunc);

	for (auto& kv : employers) {
		ofs << kv.second.toString(" ") << endl;
	}

	ofs.close();

	return 0;
}

