#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#include <NaN/Lexer/Token.hpp>

#define NEXT(line) (i + 1 < (uint32_t)line.size() ? line[i + 1] : 0)
#define PREV(line) (i - 1 >= 0 && line.size() > 0 ? line[i - 1] : 0)

class Lexer : public Token
{
private:
	std::ifstream* file = nullptr;
	std::vector<Token> token_list = { };
	//std::vector<std::string> token_list;

public:
	Lexer(std::ifstream* file);
	void tokenize();
	Token type_check(std::string str, uint64_t line_count, uint16_t index, uint64_t count);
};