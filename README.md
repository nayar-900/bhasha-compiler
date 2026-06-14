# BHASHA Compiler - C++ Edition

A production-grade compiler for the BHASHA custom programming language written in C++.

## Features

- **Input**: BHASHA custom language
- **Output**: C code
- **Architecture**: 4-phase compiler
  - Phase 1: Lexical Analysis (Tokenization)
  - Phase 2: Syntax Analysis (Parsing)
  - Phase 3: Semantic Analysis (Type Checking & Symbol Table)
  - Phase 4: Code Generation (C code generation)

## Language Keywords

| Keyword | Meaning |
|---------|---------|
| mori | main program |
| golden | variable declaration |
| machine | type keyword |
| eagle | function declaration |
| penguin | return statement |
| lana | if conditional |
| ghrup | while loop |
| tulsi | for loop |
| darshan | print/output |
| shart | input/read |
| sheeba | break statement |
| kubri | array |

## Building

```bash
mkdir build
cd build
cmake ..
make
```

## Usage

```bash
./bhasha-compiler input.bhasha -o output.c
gcc output.c -o program
./program
```

## Example Program

**hello.bhasha**:
```
mori {
    darshan("Hello World");
}
```

**Generated C code**:
```c
#include <stdio.h>

int main() {
    printf("Hello World\n");
    return 0;
}
```

## Project Structure

```
bhasha-compiler/
├── include/          # Header files
│   ├── token.h       # Token definitions
│   ├── lexer.h       # Lexical analyzer
│   ├── parser.h      # Parser
│   ├── ast.h         # AST nodes
│   ├── symbol_table.h # Symbol table
│   ├── semantic_analyzer.h # Semantic analyzer
│   └── code_generator.h    # Code generator
├── src/              # Implementation files
│   ├── main.cpp
│   ├── lexer.cpp
│   ├── parser.cpp
│   ├── ast.cpp
│   ├── symbol_table.cpp
│   ├── semantic_analyzer.cpp
│   └── code_generator.cpp
├── examples/         # Example programs
│   ├── hello.bhasha
│   └── variables.bhasha
├── tests/            # Test files
└── CMakeLists.txt    # Build configuration
```

## Compiler Pipeline

```
Source Code (BHASHA)
        ↓
Lexer (Phase 1) → Tokens
        ↓
Parser (Phase 2) → AST
        ↓
Semantic Analyzer (Phase 3) → Validated AST
        ↓
Code Generator (Phase 4) → C Code
        ↓
C Compiler (GCC/Clang) → Executable
```

## License

MIT License

## Author

BHASHA Compiler Development Team
