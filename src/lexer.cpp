#include "lexer.h"
#include <cctype>

Lexer::Lexer(const std::string& code) : code(code), pos(0), line(1), column(1) {}

char Lexer::current() {
    return pos < code.length() ? code[pos] : '\0';
}

char Lexer::peek(int offset) {
    return pos + offset < code.length() ? code[pos + offset] : '\0';
}

void Lexer::advance() {
    if (pos < code.length() && code[pos] == '\n') {
        line++;
        column = 1;
    } else {
        column++;
    }
    pos++;
}

void Lexer::skipWhitespace() {
    while (std::isspace(current())) {
        advance();
    }
}

void Lexer::skipComment() {
    if (current() == '/' && peek() == '/') {
        while (current() != '\n' && current() != '\0') {
            advance();
        }
    }
}

Token Lexer::readNumber() {
    int startLine = line, startCol = column;
    std::string num;
    while (std::isdigit(current())) {
        num += current();
        advance();
    }
    if (current() == '.' && std::isdigit(peek())) {
        num += current();
        advance();
        while (std::isdigit(current())) {
            num += current();
            advance();
        }
    }
    return Token(TokenType::NUMBER, num, startLine, startCol);
}

Token Lexer::readString() {
    int startLine = line, startCol = column;
    advance(); // skip opening quote
    std::string str;
    while (current() != '"' && current() != '\0') {
        if (current() == '\\' && peek() == '"') {
            str += '"';
            advance();
            advance();
        } else {
            str += current();
            advance();
        }
    }
    if (current() == '"') advance();
    return Token(TokenType::STRING, str, startLine, startCol);
}

Token Lexer::readIdentifier() {
    int startLine = line, startCol = column;
    std::string id;
    while (std::isalnum(current()) || current() == '_') {
        id += current();
        advance();
    }
    TokenType type = getKeywordType(id);
    return Token(type, id, startLine, startCol);
}

TokenType Lexer::getKeywordType(const std::string& word) {
    static const std::unordered_map<std::string, TokenType> keywords = {
        {"mori", TokenType::MORI}, {"golden", TokenType::GOLDEN}, {"machine", TokenType::MACHINE},
        {"eagle", TokenType::EAGLE}, {"penguin", TokenType::PENGUIN}, {"lana", TokenType::LANA},
        {"else", TokenType::ELSE}, {"ghrup", TokenType::GHRUP}, {"tulsi", TokenType::TULSI},
        {"darshan", TokenType::DARSHAN}, {"shart", TokenType::SHART}, {"sheeba", TokenType::SHEEBA},
        {"kubri", TokenType::KUBRI}, {"int", TokenType::INT_TYPE}, {"str", TokenType::STR_TYPE},
        {"bool", TokenType::BOOL_TYPE}
    };
    auto it = keywords.find(word);
    return it != keywords.end() ? it->second : TokenType::IDENTIFIER;
}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    
    while (current() != '\0') {
        skipWhitespace();
        if (current() == '\0') break;
        
        if (current() == '/' && peek() == '/') {
            skipComment();
            continue;
        }
        
        int startLine = line, startCol = column;
        
        if (std::isdigit(current())) {
            tokens.push_back(readNumber());
        } else if (current() == '"') {
            tokens.push_back(readString());
        } else if (std::isalpha(current()) || current() == '_') {
            tokens.push_back(readIdentifier());
        } else {
            char ch = current();
            advance();
            
            switch (ch) {
                case '+': tokens.push_back(Token(TokenType::PLUS, "+", startLine, startCol)); break;
                case '-': tokens.push_back(Token(TokenType::MINUS, "-", startLine, startCol)); break;
                case '*': tokens.push_back(Token(TokenType::MULTIPLY, "*", startLine, startCol)); break;
                case '/': tokens.push_back(Token(TokenType::DIVIDE, "/", startLine, startCol)); break;
                case '%': tokens.push_back(Token(TokenType::MODULO, "%", startLine, startCol)); break;
                case '=':
                    if (current() == '=') {
                        advance();
                        tokens.push_back(Token(TokenType::EQUAL, "==", startLine, startCol));
                    } else {
                        tokens.push_back(Token(TokenType::ASSIGN, "=", startLine, startCol));
                    }
                    break;
                case '!':
                    if (current() == '=') {
                        advance();
                        tokens.push_back(Token(TokenType::NOT_EQUAL, "!=", startLine, startCol));
                    } else {
                        tokens.push_back(Token(TokenType::NOT, "!", startLine, startCol));
                    }
                    break;
                case '<':
                    if (current() == '=') {
                        advance();
                        tokens.push_back(Token(TokenType::LESS_EQUAL, "<=", startLine, startCol));
                    } else {
                        tokens.push_back(Token(TokenType::LESS, "<", startLine, startCol));
                    }
                    break;
                case '>':
                    if (current() == '=') {
                        advance();
                        tokens.push_back(Token(TokenType::GREATER_EQUAL, ">=", startLine, startCol));
                    } else {
                        tokens.push_back(Token(TokenType::GREATER, ">", startLine, startCol));
                    }
                    break;
                case '&':
                    if (current() == '&') {
                        advance();
                        tokens.push_back(Token(TokenType::AND, "&&", startLine, startCol));
                    }
                    break;
                case '|':
                    if (current() == '|') {
                        advance();
                        tokens.push_back(Token(TokenType::OR, "||", startLine, startCol));
                    }
                    break;
                case '(': tokens.push_back(Token(TokenType::LPAREN, "(", startLine, startCol)); break;
                case ')': tokens.push_back(Token(TokenType::RPAREN, ")", startLine, startCol)); break;
                case '{': tokens.push_back(Token(TokenType::LBRACE, "{", startLine, startCol)); break;
                case '}': tokens.push_back(Token(TokenType::RBRACE, "}", startLine, startCol)); break;
                case '[': tokens.push_back(Token(TokenType::LBRACKET, "[", startLine, startCol)); break;
                case ']': tokens.push_back(Token(TokenType::RBRACKET, "]", startLine, startCol)); break;
                case ';': tokens.push_back(Token(TokenType::SEMI, ";", startLine, startCol)); break;
                case ',': tokens.push_back(Token(TokenType::COMMA, ",", startLine, startCol)); break;
                case '.': tokens.push_back(Token(TokenType::DOT, ".", startLine, startCol)); break;
                default:
                    tokens.push_back(Token(TokenType::ERROR, std::string(1, ch), startLine, startCol));
            }
        }
    }
    
    tokens.push_back(Token(TokenType::END_OF_FILE, "", line, column));
    return tokens;
}
