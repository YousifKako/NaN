#include <NaN/Lexer/Lexer.hpp>

Lexer::Lexer(std::ifstream* file) : file(file)
{
	this->tokenize();

	for (auto token : this->token_list)
		print_token(token);
}

void Lexer::tokenize()
{
	uint64_t count = 0;

	if (this->file->is_open())
	{
		uint64_t line_count = 0;
		std::string line = "";

		while (std::getline(*this->file, line))
		{
			std::string to_append = "";
			Token token = { };
			uint32_t i = 0;

			for ( ; i < line.size(); ++i)
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
					case '*':
					case '&':
					case ',':
					case '-':
					case '~':
					case '!':
						if (to_append != "")
						{
							token = type_check(to_append, line_count, i, count);
							this->token_list.push_back(token);
							count++;
						}

						token = type_check(std::string(1, line[i]), line_count, i, count);
						this->token_list.push_back(token);
						to_append = "";
						count++;
						break;
					case '\t':
					case '\n':
						if (to_append != "")
						{
							token = type_check(to_append, line_count, i, count);
							this->token_list.push_back(token);
							count++;
						}
						break;
					case ' ':
						if (to_append != "")
						{
							token = type_check(to_append, line_count, i, count);
							this->token_list.push_back(token);
							count++;
						}
						to_append = "";
						break;
					default:
						to_append += line[i];
						break;
				}
			}
			if (to_append != "")
			{
				token = type_check(to_append, line_count, i, count);
				this->token_list.push_back(token);
				count++;
			}

			line_count++;
		}
	}
}

Token Lexer::type_check(std::string str, uint64_t line_count, uint16_t index, uint64_t count)
{
	Token token;

	token.ID = count;
	token.Index = index;
	token.LineNumber = line_count;

	if (str == "int" || str == "return" || str == "char" || str == "if" || str == "const")
	{
		token.Type = str;
		return token;
	}
	else if (str == "#include")
	{
		token.Type = "Include";
		return token;
	}
	else if (str[0] == '"' && str[str.length()-1] == '"')
	{
		token.Type = "String";
		token.Symbol = str;
	}
	else if (this->mapping[str] != "")
	{
		token.Type = this->mapping[str];
	}
	else
	{
		token.Type = "Ident";
		token.Symbol = str;
	}

	return token;
}