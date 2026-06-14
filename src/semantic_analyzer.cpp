#include "semantic_analyzer.h"

void SemanticAnalyzer::analyze(Program* program) {
    symbolTable.enterScope();
    for (auto& stmt : program->statements) {
        analyzeStatement(stmt.get());
    }
    symbolTable.exitScope();
}

void SemanticAnalyzer::analyzeStatement(Statement* stmt) {
    if (auto var = dynamic_cast<VarDeclaration*>(stmt)) {
        analyzeVarDeclaration(var);
    } else if (auto func = dynamic_cast<FunctionDeclaration*>(stmt)) {
        analyzeFunctionDeclaration(func);
    }
}

void SemanticAnalyzer::analyzeExpression(Expression* expr, std::string& resultType) {
    // Placeholder
}

void SemanticAnalyzer::analyzeVarDeclaration(VarDeclaration* var) {
    Symbol sym;
    sym.name = var->name;
    sym.type = var->type;
    sym.isFunction = false;
    symbolTable.addSymbol(sym);
}

void SemanticAnalyzer::analyzeFunctionDeclaration(FunctionDeclaration* func) {
    Symbol sym;
    sym.name = func->name;
    sym.isFunction = true;
    sym.returnType = func->returnType;
    symbolTable.addSymbol(sym);
}

void SemanticAnalyzer::addError(const std::string& msg) {
    errors.push_back(msg);
}
