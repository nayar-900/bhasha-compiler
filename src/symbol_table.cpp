#include "symbol_table.h"

void SymbolTable::enterScope() {
    scopes.push_back(std::unordered_map<std::string, Symbol>());
}

void SymbolTable::exitScope() {
    if (!scopes.empty()) {
        scopes.pop_back();
    }
}

void SymbolTable::addSymbol(const Symbol& sym) {
    if (!scopes.empty()) {
        scopes.back()[sym.name] = sym;
    }
}

Symbol* SymbolTable::lookup(const std::string& name) {
    for (auto it = scopes.rbegin(); it != scopes.rend(); ++it) {
        auto found = it->find(name);
        if (found != it->end()) {
            return &found->second;
        }
    }
    return nullptr;
}

bool SymbolTable::isDefined(const std::string& name) {
    return lookup(name) != nullptr;
}
