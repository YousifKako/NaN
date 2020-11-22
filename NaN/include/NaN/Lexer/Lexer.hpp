#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

class Lexer
{
private:
	std::ifstream* file;
	std::vector<std::string> list;

public:
	Lexer(std::ifstream* file);
	void tokenize();
	std::string type_check(std::string str);
};