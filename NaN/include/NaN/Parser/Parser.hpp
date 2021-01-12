#pragma once

#include <NaN/Parser/AST.hpp>

class Parser
{
private:
    const std::vector<Token> token_list = { };
    AST AST_tree = AST("Root");

public:
    Parser(const std::vector<Token>& token_list);

private:
    void parse();
};