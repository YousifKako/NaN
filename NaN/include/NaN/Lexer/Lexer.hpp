#pragma once

#include <iostream>
#include <algorithm>
#include <unordered_map>
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

public:
	Lexer(std::ifstream* file);
	void tokenize();
	Token type_check(std::string str, uint64_t line_count, uint16_t index, uint64_t count);

private:
	std::unordered_map<std::string, std::string> mapping = {
		{"(", "OpenParen"},
		{")", "CloseParen"},
		{"[", "OpenBracket"},
		{"]", "CloseBracket"},
		{"{", "OpenBrace"},
		{"}", "CloseBrace"},
		{";", "SemiColon"},
		{",", "Comma"},
		{"-", "Minue"},
		{"~", "Tilde"},
		{"!", "ExclamationMark"},
		{"&", "Ampersand"},
		{">", "gt"},
		{">=", "ge"},
		{"<", "lt"},
		{"<=", "LE"},
		{"=", "Equal"},
		{"*", "Star"}
	};
};