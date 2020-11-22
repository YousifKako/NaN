#include <NaN/Lexer/Lexer.hpp>

int main(int argc, char const* argv[])
{
	
	if (argc >= 1)
	{
		std::string str;
		std::ifstream file("C:\\Users\\PC\\Documents\\Visual Studio 2019\\repos\\NaN\\NaN\\src\\test.txt");
		//std::ifstream file(argv[1], std::ios_base::in);
		Lexer laxer(&file);
	}

}