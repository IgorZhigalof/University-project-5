#pragma once
#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>

class DTO {
public:
    virtual __int64 getId();
    virtual std::string toString();
    virtual std::string toString(std::string separator);
};