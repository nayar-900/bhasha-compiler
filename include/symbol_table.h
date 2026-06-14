#ifndef BHASHA_SYMBOL_TABLE_H
#define BHASHA_SYMBOL_TABLE_H

#include <string>
#include <unordered_map>
#include <vector>
#include <memory>

struct Symbol {
    std::string name;
    std::string type;
    bool isFunction;
    std::vector<std::string> paramTypes;
    std::string returnType;
};

class SymbolTable {
public:
    void enterScope();
    void exitScope();
    void addSymbol(const Symbol& sym);
    Symbol* lookup(const std::string& name);
    bool isDefined(const std::string& name);
    
private:
    std::vector<std::unordered_map<std::string, Symbol>> scopes;
};

#endif
