#include <NaN/Parser/Parser.hpp>

Parser::Parser(const std::vector<Token>& token_list) : token_list(token_list)
{
    this->parse();
}

void Parser::parse()
{
    AST_tree.ast.push_back(AST("str2"));
    AST_tree.ast.push_back(AST("str3"));
    AST_tree.ast.push_back(AST("str4"));
    AST_tree.ast.at(0).ast.push_back(AST("str5"));
    AST_tree.ast.at(0).ast.push_back(AST("str6"));
    std::cout << AST_tree.data << std::endl;
}