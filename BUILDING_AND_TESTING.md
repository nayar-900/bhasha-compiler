# Building and Testing the BHASHA Compiler

## Prerequisites

- C++17 compiler (g++, clang, MSVC)
- CMake 3.10 or later
- GCC/Clang for testing compiled output

## Building

### Using CMake (Recommended)

```bash
# Clone the repository
git clone https://github.com/nayar-900/bhasha-compiler.git
cd bhasha-compiler

# Create build directory
mkdir build && cd build

# Configure and build
cmake ..
make

# Install (optional)
make install
```

### Using G++ Directly

```bash
g++ -std=c++17 -I./include src/main.cpp src/lexer.cpp src/parser.cpp src/ast.cpp \
    src/symbol_table.cpp src/semantic_analyzer.cpp src/code_generator.cpp -o bhasha-compiler
```

## Running the Compiler

### Basic Usage

```bash
./bhasha-compiler program.bhasha -o output.c
```

### Compiling Generated C Code

```bash
gcc output.c -o program
./program
```

### Full Workflow

```bash
# Step 1: Write BHASHA program
echo 'mori { darshan("Hello"); }' > hello.bhasha

# Step 2: Compile with BHASHA compiler
./bhasha-compiler hello.bhasha -o hello.c

# Step 3: Inspect generated C code
cat hello.c

# Step 4: Compile C code
gcc hello.c -o hello

# Step 5: Run program
./hello
```

## Testing

### Test Examples

The `examples/` directory contains test programs:

```bash
# Test hello world
./bhasha-compiler examples/hello.bhasha -o test_hello.c
gcc test_hello.c -o test_hello
./test_hello

# Test variables
./bhasha-compiler examples/variables.bhasha -o test_vars.c
gcc test_vars.c -o test_vars
./test_vars
```

### Expected Output

**hello.bhasha** → prints "Hello World"
**variables.bhasha** → declares and uses integer variables

## Troubleshooting

### CMake not found
Install CMake: `apt-get install cmake` (Linux) or `brew install cmake` (macOS)

### Compiler error: No such file
Ensure all include paths are correct and source files exist

### C code won't compile
Check the generated C code for syntax issues

## Project Structure for Building

```
bhasha-compiler/
├── include/        # Headers (.h files)
├── src/           # Implementation (.cpp files)
├── examples/      # Test programs (.bhasha files)
├── CMakeLists.txt # Build configuration
├── README.md      # Quick start
└── ARCHITECTURE.md # Detailed architecture
```
