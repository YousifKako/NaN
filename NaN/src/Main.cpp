#include <NaN/Lexer/Lexer.hpp>

int main(int argc, char const* argv[])
{

    if (argc >= 1)
    {
        std::string str;
        std::ifstream file("..\\..\\NaN\\NaN\\src\\test.txt");
        Lexer laxer(&file);
    }

}