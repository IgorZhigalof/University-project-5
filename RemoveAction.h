#pragma once

#include <string>
#include "Action.h"
#include "DBClass.h"
#include "IOClass.h"

using namespace std;

class RemoveAction : public  Action
{
public:
    RemoveAction(DatabaseService* db, IOClass* inOut);
    void getInfo() const override;
    void getHelp() const override;
    void run() const override;

private:
    DatabaseService* db;
    IOClass* inOut;
};