#ifndef BHASHA_SEMANTIC_ANALYZER_H
#define BHASHA_SEMANTIC_ANALYZER_H

#include "ast.h"
#include "symbol_table.h"
#include <string>
#include <vector>

class SemanticAnalyzer {
public:
    void analyze(Program* program);
    std::vector<std::string> getErrors() const { return errors; }
    bool hasErrors() const { return !errors.empty(); }
    
private:
    SymbolTable symbolTable;
    std::vector<std::string> errors;
    
    void analyzeStatement(Statement* stmt);
    void analyzeExpression(Expression* expr, std::string& resultType);
    void analyzeVarDeclaration(VarDeclaration* var);
    void analyzeFunctionDeclaration(FunctionDeclaration* func);
    
    void addError(const std::string& msg);
};

#endif
