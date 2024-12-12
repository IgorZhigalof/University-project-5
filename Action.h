#pragma once

class Action {
public:
    virtual void getInfo() const = 0;
    virtual void getHelp() const = 0;
    virtual void run() const = 0;
    virtual ~Action() = default;
};