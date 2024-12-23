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
	inOut->println("Employer list:");
}

void ReadAction::run() const {
	auto elements = db->getAllElements();
	if (elements.size() == 0) {
		inOut->println("There's no employers yet");
	}
	for (auto& kv : elements) {
		inOut->println(kv.second.toString(" "));
	}
}
