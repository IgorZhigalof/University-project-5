#include <iostream>
#include "DBClass.h"
#include "IOClass.h"
#include "UpdateAction.h"
#include "ReadAction.h"
#include "RemoveAction.h"
#include "CommitAction.h"
#include <vector>

int main() {
    DatabaseService db;
    IOClass io;

    std::vector<std::unique_ptr<Action>> actions;

    actions.push_back(std::make_unique<ReadAction>(&db, &io));
    actions.push_back(std::make_unique<UpdateAction>(&db, &io));
    actions.push_back(std::make_unique<RemoveAction>(&db, &io));
    actions.push_back(std::make_unique<CommitAction>(&db, &io));

    while (true)
    {
        int counter = 0;
        for (const auto& action : actions) {
            counter++;
            std::cout << counter << ". ";
            action->getInfo();
        }
        int value;
        cin >> value;
        actions[value - 1]->getHelp();
        actions[value - 1]->run();
    }
    

    return 0;
}
