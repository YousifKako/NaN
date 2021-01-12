#pragma once

#include <iostream>
#include <vector>
#include <NaN/Utilities/Utilities.hpp>

class Token
{
public:
    uint64_t ID         = ZERO;
    uint64_t LineNumber = ZERO;
    uint16_t Index      = ZERO;
    std::string Type    = EMPTY_STRING;
    std::string Symbol  = EMPTY_STRING;
};

void print_tokens(const std::vector<Token>& token_list);