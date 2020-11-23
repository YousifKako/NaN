#include <NaN/Lexer/Token.hpp>

void Token::print_token(Token token)
{
	std::cout << "ID: " << token.ID 
		<< "\tType: " << token.Type 
		<< "\tLine: " << token.LineNumber 
		<< "[" << token.Index 
		<< "]\tSymbol: " << token.Symbol 
		<< std::endl;
}