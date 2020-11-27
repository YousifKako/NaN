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
    std::unordered_map<std::string, std::string> symbol_mapping = {
        {"(", "OpenParen"       }, {")" , "CloseParen"  },
        {"[", "OpenBracket"     }, {"]" , "CloseBracket"},
        {"{", "OpenBrace"       }, {"}" , "CloseBrace"  },
        {";", "SemiColon"       }, {"," , "Comma"       },
        {"-", "Minue"           }, {"~" , "Tilde"       },
        {"!", "ExclamationMark" }, {"&" , "Ampersand"   },
        {">", "gt"              }, {">=", "ge"          },
        {"<", "lt"              }, {"<=", "LE"          },
        {"=", "Equal"           }, {"*" , "Star"        }
    };

    std::unordered_map<std::string, std::string> keyword_mapping = {
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