#include "lexer.h"
#include "parser.h"
#include "semantic_analyzer.h"
#include "code_generator.h"
#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: bhasha-compiler <input-file> [-o <output-file>]\n";
        return 1;
    }
    
    std::string inputFile = argv[1];
    std::string outputFile = "output.c";
    
    // Check for output file argument
    for (int i = 2; i < argc; i++) {
        if (std::string(argv[i]) == "-o" && i + 1 < argc) {
            outputFile = argv[i + 1];
        }
    }
    
    // Read input file
    std::ifstream infile(inputFile);
    if (!infile) {
        std::cerr << "Error: Cannot open file " << inputFile << "\n";
        return 1;
    }
    
    std::stringstream buffer;
    buffer << infile.rdbuf();
    std::string sourceCode = buffer.str();
    infile.close();
    
    try {
        // Phase 1: Lexical Analysis
        Lexer lexer(sourceCode);
        auto tokens = lexer.tokenize();
        std::cout << "Lexical Analysis: OK (" << tokens.size() << " tokens)\n";
        
        // Phase 2: Syntax Analysis
        Parser parser(tokens);
        auto program = parser.parse();
        std::cout << "Syntax Analysis: OK\n";
        
        // Phase 3: Semantic Analysis
        SemanticAnalyzer analyzer;
        analyzer.analyze(program.get());
        if (analyzer.hasErrors()) {
            for (const auto& err : analyzer.getErrors()) {
                std::cerr << "Error: " << err << "\n";
            }
            return 1;
        }
        std::cout << "Semantic Analysis: OK\n";
        
        // Phase 4: Code Generation
        CodeGenerator generator;
        std::string cCode = generator.generate(program.get());
        std::cout << "Code Generation: OK\n";
        
        // Write output
        std::ofstream outfile(outputFile);
        outfile << cCode;
        outfile.close();
        
        std::cout << "Output written to: " << outputFile << "\n";
        std::cout << "Compilation successful!\n";
        
    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << "\n";
        return 1;
    }
    
    return 0;
}
