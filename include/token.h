#ifndef BHASHA_TOKEN_H
#define BHASHA_TOKEN_H

#include <string>

enum class TokenType {
    // Keywords
    MORI, GOLDEN, MACHINE, EAGLE, PENGUIN, LANA, ELSE, GHRUP, TULSI, DARSHAN, SHART, SHEEBA, KUBRI,
    
    // Types
    INT_TYPE, STR_TYPE, BOOL_TYPE,
    
    // Operators
    PLUS, MINUS, MULTIPLY, DIVIDE, MODULO, ASSIGN,
    EQUAL, NOT_EQUAL, LESS, LESS_EQUAL, GREATER, GREATER_EQUAL,
    AND, OR, NOT,
    
    // Delimiters
    LPAREN, RPAREN, LBRACE, RBRACE, LBRACKET, RBRACKET,
    SEMI, COMMA, DOT,
    
    // Literals
    NUMBER, STRING, IDENTIFIER,
    
    // Special
    END_OF_FILE, ERROR
};

struct Token {
    TokenType type;
    std::string value;
    int line;
    int column;
    
    Token(TokenType t = TokenType::ERROR, const std::string& v = "", int l = 0, int c = 0)
        : type(t), value(v), line(l), column(c) {}
};

#endif
