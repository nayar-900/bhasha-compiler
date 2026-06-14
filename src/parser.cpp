#include "parser.h"
#include <stdexcept>

Parser::Parser(const std::vector<Token>& tokens) : tokens(tokens), pos(0) {}

const Token& Parser::current() {
    return pos < tokens.size() ? tokens[pos] : tokens.back();
}

void Parser::advance() {
    if (pos < tokens.size()) pos++;
}

std::shared_ptr<Program> Parser::parse() {
    auto prog = std::make_shared<Program>();
    while (current().type != TokenType::END_OF_FILE) {
        auto stmt = parseStatement();
        if (stmt) prog->statements.push_back(stmt);
    }
    return prog;
}

StatementPtr Parser::parseStatement() {
    switch (current().type) {
        case TokenType::GOLDEN:
            return parseVarDeclaration();
        case TokenType::MORI:
        case TokenType::LBRACE: {
            advance();
            std::vector<StatementPtr> block;
            while (current().type != TokenType::RBRACE && current().type != TokenType::END_OF_FILE) {
                auto stmt = parseStatement();
                if (stmt) block.push_back(stmt);
            }
            if (current().type == TokenType::RBRACE) advance();
            return nullptr;
        }
        case TokenType::DARSHAN: {
            advance();
            auto stmt = std::make_shared<PrintStatement>();
            if (current().type == TokenType::LPAREN) {
                advance();
                // parse expression
                advance();
            }
            if (current().type == TokenType::SEMI) advance();
            return stmt;
        }
        default:
            advance();
            return nullptr;
    }
}

StatementPtr Parser::parseVarDeclaration() {
    auto var = std::make_shared<VarDeclaration>();
    advance(); // golden
    if (current().type == TokenType::MACHINE) advance();
    if (current().type == TokenType::INT_TYPE) {
        var->type = "int";
        advance();
    }
    var->name = current().value;
    advance();
    if (current().type == TokenType::SEMI) advance();
    return var;
}

ExpressionPtr Parser::parseExpression() {
    return parseLogicalOr();
}

ExpressionPtr Parser::parseLogicalOr() {
    return nullptr;
}

ExpressionPtr Parser::parseLogicalAnd() {
    return nullptr;
}

ExpressionPtr Parser::parseComparison() {
    return nullptr;
}

ExpressionPtr Parser::parseAdditive() {
    return nullptr;
}

ExpressionPtr Parser::parseMultiplicative() {
    return nullptr;
}

ExpressionPtr Parser::parseUnary() {
    return nullptr;
}

ExpressionPtr Parser::parsePrimary() {
    return nullptr;
}
