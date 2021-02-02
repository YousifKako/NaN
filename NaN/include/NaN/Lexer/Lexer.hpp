#pragma once

#include <algorithm>
#include <unordered_map>
#include <sstream>
#include <fstream>
#include <vector>

#include <NaN/Lexer/Token.hpp>

class Lexer : public Token
{
private:
    std::ifstream* file = nullptr;
    std::vector<Token> token_list = { };

public:
    Lexer(std::ifstream* file);
    ~Lexer();
    void tokenize();
    Token type_check(std::string_view str, const uint64_t& line_count, 
        const uint16_t& index, const uint64_t& count);
    const std::vector<Token> get_tokens();

private:
    std::unordered_map<std::string_view, std::string_view> symbol_mapping = {
        {"(", "OpenParen"       }, {")" , "CloseParen"  },
        {"[", "OpenBracket"     }, {"]" , "CloseBracket"},
        {"{", "OpenBrace"       }, {"}" , "CloseBrace"  },
        {";", "SemiColon"       }, {"," , "Comma"       },
        {"-", "Minus"           }, {"~" , "Tilde"       },
        {"!", "ExclamationMark" }, {"&" , "Ampersand"   },
        {">", "gt"              }, {">=", "ge"          },
        {"<", "lt"              }, {"<=", "le"          },
        {"=", "Equal"           }, {"*" , "Star"        }
    };

    std::unordered_map<std::string_view, std::string_view> keyword_mapping = {
        {"int"      , "int"     }, {"float"     , "float"   },
        {"double"   , "double"  }, {"short"     , "short"   },
        {"long"     , "long"    }, {"return"    , "return"  },
        {"char"     , "char"    }, {"if"        , "if"      },
        {"else"     , "else"    }, {"enum"      , "enum"    },
        {"break"    , "break"   }, {"bool"      , "bool"    },
        {"switch"   , "switch"  }, {"case"      , "case"    },
        {"continue" , "continue"}, {"default"   , "default" },
        {"delete"   , "delete"  }, {"do"        , "do"      },
        {"const"    , "const"   }, {"extern"    , "extern"  },
        {"goto"     , "goto"    }, {"register"  , "register"},
        {"signed"   , "signed"  }, {"unsigned"  , "unsigned"},
        {"static"   , "static"  }, {"sizeof"    , "sizeof"  },
        {"struct"   , "struct"  }, {"typedef"   , "typedef" },
        {"union"    , "union"   }, {"void"      , "void"    },
        {"while"    , "while"   }, {"volatile"  , "volatile"}
    };

    std::unordered_map<uint8_t, uint8_t> constant_check = {
        {'0', 48}, {'1', 49}, {'2', 50}, {'3', 51}, {'4', 52},
        {'5', 53}, {'6', 54}, {'7', 55}, {'8', 56}, {'9', 57}
    };
};