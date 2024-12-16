#pragma once

#include "Action.h"
#include "DBClass.h"
#include "IOClass.h"

class CommitAction : public Action
{
public:
    CommitAction(DatabaseService* db, IOClass* inOut);
    void getInfo(void) const override;
    void getHelp(void) const override;
    void run(void) const override;

private:
    DatabaseService* db;
    IOClass* inOut;
};