#include <NaN/Lexer/Lexer.hpp>

Lexer::Lexer(std::ifstream* file) : file(file)
{
	this->tokenize();
	for (auto i : this->list)
		std::cout << i << std::endl;
}

void Lexer::tokenize()
{
	if (this->file->is_open())
	{
		std::string line = "";
		while (std::getline(*this->file, line))
		{
			std::string to_append = "";
			for (uint32_t i = 0; i < line.size(); ++i)
			{
				switch (line[i])
				{
					case '{':
					case '}':
					case '(':
					case ')':
					case '[':
					case ']':
					case ';':
					case '#':
						// TODO: Fix #
					case '*':
					case '&':
					case ',':
						if (to_append != "")
							list.push_back(to_append);
						list.push_back(std::string(1, line[i]));
						to_append = "";
						break;
					case '\t':
					case '\n':
						if (to_append != "")
							list.push_back(to_append);
						break;
					case ' ':
						if (to_append != "")
							list.push_back(to_append);
						to_append = "";
						break;
					default:
						to_append += line[i];
						break;
				}
			}
			if (to_append != "")
				list.push_back(to_append);
		}
	}
}

std::string type_check(std::string str)
{
	// TODO
}