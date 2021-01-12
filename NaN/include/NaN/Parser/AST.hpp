#pragma once

#include <NaN/Lexer/Token.hpp>

class AST
{
public:
    const std::string data = EMPTY_STRING;
    std::vector<AST> ast   = { };

    AST(const std::string data) : data(data) { }
};