#ifndef BHASHA_LEXER_H
#define BHASHA_LEXER_H

#include "token.h"
#include <vector>
#include <string>

class Lexer {
public:
    Lexer(const std::string& code);
    std::vector<Token> tokenize();
    
private:
    std::string code;
    size_t pos;
    int line;
    int column;
    
    char current();
    char peek(int offset = 1);
    void advance();
    void skipWhitespace();
    void skipComment();
    
    Token readNumber();
    Token readString();
    Token readIdentifier();
    
    TokenType getKeywordType(const std::string& word);
};

#endif
