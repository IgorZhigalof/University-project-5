#include "DBClass.h"
#include "IOClass.h"
#include "UpdateAction.h"
#include "EmployerClass.h"

using namespace std;

UpdateAction::UpdateAction(DatabaseService* db, IOClass* inOut) {
	this->db = db;
	this->inOut = inOut;
}

void UpdateAction::getInfo() const {
	inOut->println("Insert or update");
}

void UpdateAction::getHelp() const {
	inOut->println("Enter \"-\" to go back");
	inOut->println("Template: IIAN Surname Name SecondName Passport Birthday TaxAmount");
}

void UpdateAction::run() const {
	Employer* employer;
	while(true) {
		try
		{
			employer = new Employer(inOut->getData());
		}
		catch (const std::exception &ex)
		{
			inOut->println("Caught an error with description:");
			inOut->println(ex.what());
			inOut->println("Try again");
			continue;
		}
		break;
	}
	inOut->println("Successfully added");
	db->update(*employer);
}
