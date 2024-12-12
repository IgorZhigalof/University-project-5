#include "DBClass.h"
#include "IOClass.h"
#include "UpdateAction.h"

using namespace std;

UpdateAction::UpdateAction(DatabaseService* db, IOClass* inOut) {
	this->db = db;
	this->inOut = inOut;
}

void UpdateAction::getInfo() const {
	inOut->println("Insert or update");
}

void UpdateAction::getHelp() const {
	string ln =
	#ifdef _WIN32
		"\r\n";
	#else
		"\n";
	#endif
	inOut->print("Template: surname name secondName dateOfAdmission studentId specialtyCode" + ln
		+ "Use \"-\" to skip information");
}

void UpdateAction::run() const {
	Student* student;
	while(true) {
		try
		{
			student = new Student(inOut->getData());
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
	inOut->println("Succesfully added");
	db->update(*student);
}
