#pragma once
#include <string>

class IOClass {
public:
    void print(const std::string message);
    void println(const std::string message);
    std::string getData(void);
};