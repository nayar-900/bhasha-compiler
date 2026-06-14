#include "ast.h"
#include <iostream>
#include <iomanip>

void Program::print(int indent) const {
    std::cout << std::string(indent, ' ') << "Program\n";
    for (const auto& stmt : statements) {
        if (stmt) stmt->print(indent + 2);
    }
}

void VarDeclaration::print(int indent) const {
    std::cout << std::string(indent, ' ') << "VarDecl: " << name << " (" << type << ")\n";
}

void Assignment::print(int indent) const {
    std::cout << std::string(indent, ' ') << "Assign: " << name << "\n";
}

void PrintStatement::print(int indent) const {
    std::cout << std::string(indent, ' ') << "Print\n";
}

void IfStatement::print(int indent) const {
    std::cout << std::string(indent, ' ') << "If\n";
}

void WhileStatement::print(int indent) const {
    std::cout << std::string(indent, ' ') << "While\n";
}

void ForStatement::print(int indent) const {
    std::cout << std::string(indent, ' ') << "For\n";
}

void FunctionDeclaration::print(int indent) const {
    std::cout << std::string(indent, ' ') << "Function: " << name << "\n";
}

void ReturnStatement::print(int indent) const {
    std::cout << std::string(indent, ' ') << "Return\n";
}

void FunctionCall::print(int indent) const {
    std::cout << std::string(indent, ' ') << "Call: " << name << "\n";
}

void BinaryOp::print(int indent) const {
    std::cout << std::string(indent, ' ') << "BinOp: " << op << "\n";
}

void UnaryOp::print(int indent) const {
    std::cout << std::string(indent, ' ') << "UnaryOp: " << op << "\n";
}

void Identifier::print(int indent) const {
    std::cout << std::string(indent, ' ') << "Id: " << name << "\n";
}

void NumberLiteral::print(int indent) const {
    std::cout << std::string(indent, ' ') << "Num: " << value << "\n";
}

void StringLiteral::print(int indent) const {
    std::cout << std::string(indent, ' ') << "Str: " << value << "\n";
}

void InputStatement::print(int indent) const {
    std::cout << std::string(indent, ' ') << "Input: " << varName << "\n";
}

void ArrayAccess::print(int indent) const {
    std::cout << std::string(indent, ' ') << "ArrayAccess: " << name << "\n";
}

void BreakStatement::print(int indent) const {
    std::cout << std::string(indent, ' ') << "Break\n";
}
