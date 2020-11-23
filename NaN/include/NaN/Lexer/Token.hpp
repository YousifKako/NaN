#pragma once

#include <iostream>

class Token
{
public:
	uint64_t ID = 0;
	uint64_t LineNumber = 0;
	uint16_t Index = 0;
	std::string Type = "";
	std::string Symbol = "";

public:
	void print_token(Token token);
};