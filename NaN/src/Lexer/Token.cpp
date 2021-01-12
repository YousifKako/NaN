#include <NaN/Lexer/Token.hpp>

void print_tokens(const std::vector<Token>& token_list)
{
    for (const Token& token : token_list)
    {
        std::cout << "ID: "  << token.ID
            << "\tType: "    << token.Type
            << "\t\tLine: "  << token.LineNumber
            << "["           << token.Index
            << "]\tSymbol: " << token.Symbol
                             << std::endl;
    }
}