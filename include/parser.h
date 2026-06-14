#ifndef BHASHA_PARSER_H
#define BHASHA_PARSER_H

#include "token.h"
#include "ast.h"
#include <vector>
#include <memory>

class Parser {
public:
    Parser(const std::vector<Token>& tokens);
    std::shared_ptr<Program> parse();
    
private:
    std::vector<Token> tokens;
    size_t pos;
    
    const Token& current();
    const Token& peek(int offset = 1);
    void advance();
    void expect(TokenType type);
    bool check(TokenType type);
    
    StatementPtr parseStatement();
    StatementPtr parseVarDeclaration();
    StatementPtr parseIfStatement();
    StatementPtr parseWhileStatement();
    StatementPtr parseForStatement();
    StatementPtr parseFunctionDeclaration();
    StatementPtr parseReturnStatement();
    StatementPtr parseBreakStatement();
    
    ExpressionPtr parseExpression();
    ExpressionPtr parseLogicalOr();
    ExpressionPtr parseLogicalAnd();
    ExpressionPtr parseComparison();
    ExpressionPtr parseAdditive();
    ExpressionPtr parseMultiplicative();
    ExpressionPtr parseUnary();
    ExpressionPtr parsePrimary();
};

#endif
