#include "DBClass.h"
#include "ReadAction.h"


ReadAction::ReadAction(DatabaseService* db, IOClass* inOut) {
	this->db = db;
	this->inOut = inOut;
}

void ReadAction::getInfo() const {
	inOut->println("Read all employers");
}

void ReadAction::getHelp() const {
}

void ReadAction::run() const {
	auto students = db->getAllEmployers();
	for (auto& kv : students) {
		inOut->println(kv.second.toString(" "));
	}
}
