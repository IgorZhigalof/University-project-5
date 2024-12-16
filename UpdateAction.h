#pragma once

#include "Action.h"
#include "DBClass.h"
#include "IOClass.h"
#include <optional>
#include <stdexcept>

class UpdateAction : public  Action
{
public:
    UpdateAction(DatabaseService* db, IOClass* inOut);
    void getInfo() const override;
    void getHelp() const override;
    void run() const override;

private:
    DatabaseService* db;
    IOClass* inOut;
};

