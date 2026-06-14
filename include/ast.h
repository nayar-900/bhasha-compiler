#ifndef BHASHA_AST_H
#define BHASHA_AST_H

#include <string>
#include <vector>
#include <memory>

// Forward declarations
struct ASTNode;
struct Statement;
struct Expression;

using ASTNodePtr = std::shared_ptr<ASTNode>;
using StatementPtr = std::shared_ptr<Statement>;
using ExpressionPtr = std::shared_ptr<Expression>;

struct ASTNode {
    virtual ~ASTNode() = default;
    virtual void print(int indent = 0) const = 0;
};

struct Program : public ASTNode {
    std::vector<StatementPtr> statements;
    void print(int indent = 0) const override;
};

struct Statement : public ASTNode {
    virtual ~Statement() = default;
};

struct Expression : public ASTNode {
    virtual ~Expression() = default;
};

struct VarDeclaration : public Statement {
    std::string name;
    std::string type;
    ExpressionPtr initialValue;
    void print(int indent = 0) const override;
};

struct Assignment : public Statement {
    std::string name;
    ExpressionPtr value;
    void print(int indent = 0) const override;
};

struct PrintStatement : public Statement {
    ExpressionPtr value;
    void print(int indent = 0) const override;
};

struct InputStatement : public Statement {
    std::string varName;
    void print(int indent = 0) const override;
};

struct IfStatement : public Statement {
    ExpressionPtr condition;
    std::vector<StatementPtr> thenBlock;
    std::vector<StatementPtr> elseBlock;
    void print(int indent = 0) const override;
};

struct WhileStatement : public Statement {
    ExpressionPtr condition;
    std::vector<StatementPtr> body;
    void print(int indent = 0) const override;
};

struct ForStatement : public Statement {
    StatementPtr init;
    ExpressionPtr condition;
    ExpressionPtr increment;
    std::vector<StatementPtr> body;
    void print(int indent = 0) const override;
};

struct FunctionDeclaration : public Statement {
    std::string name;
    std::vector<std::pair<std::string, std::string>> params; // (name, type)
    std::string returnType;
    std::vector<StatementPtr> body;
    void print(int indent = 0) const override;
};

struct ReturnStatement : public Statement {
    ExpressionPtr value;
    void print(int indent = 0) const override;
};

struct FunctionCall : public Expression {
    std::string name;
    std::vector<ExpressionPtr> arguments;
    void print(int indent = 0) const override;
};

struct BinaryOp : public Expression {
    std::string op;
    ExpressionPtr left;
    ExpressionPtr right;
    void print(int indent = 0) const override;
};

struct UnaryOp : public Expression {
    std::string op;
    ExpressionPtr operand;
    void print(int indent = 0) const override;
};

struct Identifier : public Expression {
    std::string name;
    void print(int indent = 0) const override;
};

struct NumberLiteral : public Expression {
    double value;
    void print(int indent = 0) const override;
};

struct StringLiteral : public Expression {
    std::string value;
    void print(int indent = 0) const override;
};

struct ArrayAccess : public Expression {
    std::string name;
    ExpressionPtr index;
    void print(int indent = 0) const override;
};

struct BreakStatement : public Statement {
    void print(int indent = 0) const override;
};

#endif
