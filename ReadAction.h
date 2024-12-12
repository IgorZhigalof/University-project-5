#pragma once

#include "Action.h"
#include "DBClass.h"
#include "IOClass.h"

class ReadAction : public Action
{
public:
    ReadAction(DatabaseService* db, IOClass* inOut);
    void getInfo(void) const override;
    void getHelp(void) const override;
    void run(void) const override;

private:
    DatabaseService* db;
    IOClass* inOut;
};
