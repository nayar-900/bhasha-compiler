# BHASHA Compiler Architecture

## Overview

The BHASHA compiler is a 4-phase compiler written in C++ that translates BHASHA custom language to C code.

## Phase Breakdown

### Phase 1: Lexical Analysis (Lexer)
**File**: `src/lexer.cpp` / `include/lexer.h`

Converts source code characters into tokens:
- Recognizes keywords (mori, golden, eagle, etc.)
- Identifies operators (+, -, *, /, ==, etc.)
- Extracts literals (numbers, strings)
- Tracks line/column information for error reporting

**Input**: Raw source code string
**Output**: Vector of Token objects

### Phase 2: Syntax Analysis (Parser)
**File**: `src/parser.cpp` / `include/parser.h`

Builds an Abstract Syntax Tree (AST) by parsing the token stream:
- Recursive descent parser
- Validates grammar against language specification
- Builds hierarchical AST structure

**Input**: Vector of tokens
**Output**: Program AST

### Phase 3: Semantic Analysis
**File**: `src/semantic_analyzer.cpp` / `include/semantic_analyzer.h`

Validates semantic correctness:
- Type checking
- Symbol table management
- Scope tracking
- Variable/function existence verification

**Input**: Program AST
**Output**: Validated AST + Error list

### Phase 4: Code Generation
**File**: `src/code_generator.cpp` / `include/code_generator.h`

Converts validated AST to C code:
- Generates proper C syntax
- Handles type conversions
- Manages memory and variable allocation

**Input**: Validated AST
**Output**: Valid C code string

## AST Node Hierarchy

```
ASTNode (base)
├── Program
├── Statement
│   ├── VarDeclaration
│   ├── Assignment
│   ├── PrintStatement
│   ├── IfStatement
│   ├── WhileStatement
│   ├── ForStatement
│   ├── FunctionDeclaration
│   ├── ReturnStatement
│   └── BreakStatement
└── Expression
    ├── BinaryOp
    ├── UnaryOp
    ├── FunctionCall
    ├── Identifier
    ├── NumberLiteral
    ├── StringLiteral
    ├── ArrayAccess
    └── ...
```

## Symbol Table

Multi-level scope management:
- Tracks variable declarations
- Maintains function signatures
- Validates identifier usage
- Supports nested scopes

## Example Compilation Flow

**BHASHA Input**:
```
mori {
    golden machine int x = 10;
    darshan(x);
}
```

**Phase 1 Output (Tokens)**:
```
MORI | LBRACE | GOLDEN | MACHINE | INT_TYPE | ID(x) | ASSIGN | NUMBER(10) | SEMI | DARSHAN | LPAREN | ID(x) | RPAREN | RBRACE
```

**Phase 2 Output (AST)**:
```
Program
├── VarDeclaration (x, int)
├── PrintStatement
│   └── Identifier (x)
```

**Phase 3 Output**:
```
Validation: OK
Symbols: x -> int (valid)
```

**Phase 4 Output (C Code)**:
```c
#include <stdio.h>

int main() {
    int x = 10;
    printf("%d\n", x);
    return 0;
}
```

## Error Handling

- Line/column tracking through all phases
- Detailed error messages
- Compilation halts on semantic errors
- Parser recovery for better error reporting

## Compilation Pipeline

```
bhasha-compiler input.bhasha -o output.c
        ↓
[Lexer] → Tokens
        ↓
[Parser] → AST
        ↓
[Semantic Analyzer] → Validated AST
        ↓
[Code Generator] → C Code
        ↓
output.c (ready to compile with gcc/clang)
```
