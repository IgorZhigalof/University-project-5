#include <string>
#include "Action.h"
#include "DBClass.h"
#include "RemoveAction.h"

using namespace std;


RemoveAction::RemoveAction(DatabaseService* db, IOClass* inOut) {
	this->db = db;
}

void RemoveAction::getInfo() const {
	inOut->println("Remove item");
}

void RemoveAction::getHelp() const {
	string ln =
	#ifdef _WIN32
		"\r\n";
	#else
		"\n";
	#endif
	inOut->println("Enter student id to delete" + ln
		+ "Enter \"-\" to close delete action");
}

void RemoveAction::run() const {
	while (true) {
		string data = inOut->getData();
		if (data == "-") {
			return;
		}
		try
		{
			__int64 id = atol(data.c_str());
			db->remove(id);
		}
		catch (const std::exception& ex)
		{
			inOut->println("Caught an error with description:");
			inOut->println(ex.what());
			inOut->println("Try again");
			continue;
		}
	}
	inOut->println("Succesfully removed");
}
	
