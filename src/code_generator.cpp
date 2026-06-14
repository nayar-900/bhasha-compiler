#include "code_generator.h"
#include <sstream>

std::string CodeGenerator::generate(Program* program) {
    code.str("");
    indentLevel = 0;
    tempVarCount = 0;
    
    emit("#include <stdio.h>");
    emit("#include <stdlib.h>");
    emit("#include <string.h>");
    emit("");
    emit("int main() {");
    indentLevel++;
    
    for (auto& stmt : program->statements) {
        generateStatement(stmt.get());
    }
    
    indentLevel--;
    emit("    return 0;");
    emit("}");
    
    return code.str();
}

void CodeGenerator::indent() {
    for (int i = 0; i < indentLevel; i++) {
        code << "    ";
    }
}

void CodeGenerator::emit(const std::string& line) {
    code << line << "\n";
}

std::string CodeGenerator::getTempVar() {
    return "temp_" + std::to_string(tempVarCount++);
}

void CodeGenerator::generateStatement(Statement* stmt) {
    if (auto var = dynamic_cast<VarDeclaration*>(stmt)) {
        generateVarDeclaration(var);
    }
}

void CodeGenerator::generateVarDeclaration(VarDeclaration* var) {
    indent();
    code << var->type << " " << var->name << ";";
    emit("");
}

void CodeGenerator::generateExpression(Expression* expr, std::string& result) {
    // Placeholder
}
