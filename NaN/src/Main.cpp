#include <chrono>

#include <NaN/Lexer/Lexer.hpp>
#include <NaN/Parser/Parser.hpp>


// Performance Debug
#if ZERO
static uint32_t s_AllocCount = 0;
void* operator new(size_t size)
{
    s_AllocCount++;
    //std::cout << "Allocating " << size << " Bytes" << std::endl;
    return malloc(size);
}
#define NUM_ALLOC std::cout << s_AllocCount << " Allocations" << std::endl
#else
#define NUM_ALLOC
#endif


int main(int argc, char const* argv[])
{
    if (argc >= 1)
    {
        auto start = std::chrono::high_resolution_clock::now();
    
        std::ifstream file("..\\..\\NaN\\NaN\\src\\test.txt");
        Lexer lexer(&file);
    
        const std::vector<Token> tokens_list = lexer.get_tokens();
        Parser parser(tokens_list);
    
        auto end = std::chrono::high_resolution_clock::now();
    
        std::cout << "Execution Time: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
            << "ms"
            << std::endl;
    }

    NUM_ALLOC;

    return EXIT_SUCCESS;
}