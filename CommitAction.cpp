#include "DBClass.h"
#include "CommitAction.h"


CommitAction::CommitAction(DatabaseService* db, IOClass* inOut) {
	this->db = db;
	this->inOut = inOut;
}

void CommitAction::getInfo() const {
	inOut->println("Commit updates");
}

void CommitAction::getHelp() const {
}

void CommitAction::run() const {
	db->commit();
	inOut->println("Successfully commited");
}
