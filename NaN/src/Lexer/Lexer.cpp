#include <NaN/Lexer/Lexer.hpp>
#include <NaN/Utilities/Utilities.hpp>

Lexer::Lexer(std::ifstream* file) : file(file)
{
    this->tokenize();
    print_tokens(this->token_list);
}

Lexer::~Lexer()
{
    this->file->close();
}

void Lexer::tokenize()
{
    uint64_t count = ZERO;

    if (this->file->is_open())
    {
        uint64_t line_count = 1;
        std::string line = EMPTY_STRING;

        while (std::getline(*this->file, line))
        {
            std::string to_append = EMPTY_STRING;
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
                    if (to_append != EMPTY_STRING)
                    {
                        token = type_check(to_append, line_count, i, count);
                        this->token_list.push_back(token);
                        count++;
                    }

                    token = type_check(std::string(1, line[i]), line_count, i, count);
                    this->token_list.push_back(token);
                    to_append = EMPTY_STRING;
                    count++;
                    break;
                case '\t':
                case '\n':
                    if (to_append != EMPTY_STRING)
                    {
                        token = type_check(to_append, line_count, i, count);
                        this->token_list.push_back(token);
                        count++;
                    }
                    break;
                case ' ':
                    if (to_append != EMPTY_STRING)
                    {
                        token = type_check(to_append, line_count, i, count);
                        this->token_list.push_back(token);
                        count++;
                    }
                    to_append = EMPTY_STRING;
                    break;
                default:
                    to_append += line[i];
                    break;
                }
            }
            if (to_append != EMPTY_STRING)
            {
                token = type_check(to_append, line_count, i, count);
                this->token_list.push_back(token);
                count++;
            }

            line_count++;
        }
    }
}

Token Lexer::type_check(std::string_view str, const uint64_t& line_count,
    const uint16_t& index, const uint64_t& count)
{
    Token token = { };

    token.ID = count;
    token.Index = index;
    token.LineNumber = line_count;

    if (this->keyword_mapping[str] != EMPTY_STRING)
    {
        token.Type = str;
        return token;
    }
    else if (str == "#include")
    {
        token.Type = "Include";
        return token;
    }
    else if (str[0] == '"' && str[str.length() - 1] == '"')
    {
        token.Type = "String";
        token.Symbol = str;
    }
    else if (this->symbol_mapping[str] != EMPTY_STRING)
    {
        token.Type = this->symbol_mapping[str];
    }
    else
    {
        if (this->constant_check[str[0]] != 0 || str[0] == '.')
        {
            uint8_t num_check = 1;
            uint8_t float_check = 0;

            for (uint8_t i = 0; i < str.length(); ++i)
            {
                if (str[i] == '.') float_check = 1; continue;
                if (this->constant_check[str[i]] == 0) num_check = 0; break;
            }

            if (num_check && float_check) token.Type = "Float";
            else if (num_check && ~float_check) token.Type = "Constant";
            else token.Type = "Ident";
        }
        else
        {
            token.Type = "Ident";
        }

        token.Symbol = str;
    }

    return token;
}

const std::vector<Token> Lexer::get_tokens()
{
    return this->token_list;
}