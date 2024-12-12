#include "DBClass.h"
#include "ReadAction.h"


ReadAction::ReadAction(DatabaseService* db, IOClass* inOut) {
	this->db = db;
	this->inOut = inOut;
}

void ReadAction::getInfo() const {
	inOut->println("Read all students");
}

void ReadAction::getHelp() const {
}

void ReadAction::run() const {
	auto students = db->getAllStudents();
	for (auto& kv : students) {
		inOut->println(kv.second.toString(" "));
	}
}
