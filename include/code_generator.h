#ifndef BHASHA_CODE_GENERATOR_H
#define BHASHA_CODE_GENERATOR_H

#include "ast.h"
#include <string>
#include <sstream>

class CodeGenerator {
public:
    std::string generate(Program* program);
    
private:
    std::stringstream code;
    int indentLevel;
    int tempVarCount;
    
    void indent();
    void emit(const std::string& line);
    std::string getTempVar();
    
    void generateStatement(Statement* stmt);
    void generateExpression(Expression* expr, std::string& result);
    
    void generateVarDeclaration(VarDeclaration* var);
    void generateAssignment(Assignment* assign);
    void generatePrintStatement(PrintStatement* print);
    void generateInputStatement(InputStatement* input);
    void generateIfStatement(IfStatement* ifStmt);
    void generateWhileStatement(WhileStatement* whileStmt);
    void generateForStatement(ForStatement* forStmt);
    void generateFunctionDeclaration(FunctionDeclaration* func);
    void generateReturnStatement(ReturnStatement* ret);
    void generateFunctionCall(FunctionCall* call, std::string& result);
    void generateBinaryOp(BinaryOp* op, std::string& result);
};

#endif
