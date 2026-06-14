# BHASHA Compiler - Quick Start Guide

## Step-by-Step Instructions

### Step 1: Download the Compiler

```bash
# Clone the repository from GitHub
git clone https://github.com/nayar-900/bhasha-compiler.git

# Go into the directory
cd bhasha-compiler
```

### Step 2: Check Requirements

You need:
- **C++ compiler** (g++ or clang): `which g++`
- **CMake**: `which cmake`
- **Make**: `which make`

If you don't have them:
- **Ubuntu/Debian**: `sudo apt-get install build-essential cmake`
- **macOS**: `brew install cmake`
- **Windows**: Install MinGW or Visual Studio

### Step 3: Build the Compiler

```bash
# Create a build directory
mkdir build
cd build

# Configure the build with CMake
cmake ..

# Build the compiler
make

# You'll now have: ./bhasha-compiler executable
```

### Step 4: Verify Installation

```bash
# Check if compiler was built
ls -la bhasha-compiler

# You should see: bhasha-compiler (executable file)
```

### Step 5: Write Your First BHASHA Program

Create a file `hello.bhasha`:

```bash
cat > hello.bhasha << 'END'
mori {
    darshan("Hello World");
}
END
```

### Step 6: Compile BHASHA Code to C

```bash
# Use the compiler you just built
./bhasha-compiler hello.bhasha -o hello.c

# Check if it worked
cat hello.c
```

You'll see generated C code like:
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Hello World\n");
    return 0;
}
```

### Step 7: Compile Generated C Code to Executable

```bash
# Compile the C code using gcc
gcc hello.c -o hello_program

# You now have an executable: hello_program
```

### Step 8: Run Your Program

```bash
# Execute the program
./hello_program

# You'll see output:
# Hello World
```

## Complete Workflow (All Commands)

```bash
# 1. Clone
git clone https://github.com/nayar-900/bhasha-compiler.git
cd bhasha-compiler

# 2. Build
mkdir build && cd build
cmake ..
make

# 3. Write program
cd ..
echo 'mori { darshan("Hello"); }' > test.bhasha

# 4. Compile BHASHA → C
./build/bhasha-compiler test.bhasha -o test.c

# 5. Compile C → Executable
gcc test.c -o test_program

# 6. Run
./test_program

# Output: Hello
```

## Using Example Programs

The repository includes example programs:

```bash
# Example 1: Hello World
./build/bhasha-compiler examples/hello.bhasha -o hello.c
gcc hello.c -o hello
./hello

# Example 2: Variables
./build/bhasha-compiler examples/variables.bhasha -o vars.c
gcc vars.c -o vars
./vars
```

## Command Reference

### Compile BHASHA to C

```bash
./bhasha-compiler input.bhasha -o output.c
```

Options:
- `input.bhasha` - Your BHASHA program file
- `-o output.c` - Output C file name (optional, defaults to output.c)

### Compile C to Executable

```bash
gcc output.c -o my_program
```

### Run Program

```bash
./my_program
```

## Troubleshooting

### Error: "bhasha-compiler not found"
Make sure you:
1. Are in the `build/` directory
2. Have run `cmake ..` and `make`
3. Use `./bhasha-compiler` (with ./)

### Error: "No such file or directory: hello.bhasha"
Make sure the .bhasha file exists in current directory

### Error: "gcc: command not found"
Install GCC: `sudo apt-get install gcc` (Linux) or `brew install gcc` (macOS)

### Compiler produces empty or wrong C code
Check your BHASHA syntax - see examples/ for correct syntax

## Typical File Extensions

- `.bhasha` - Your custom language code
- `.c` - Generated C code
- (no extension) - Compiled executable

## Typical Folder Structure After Setup

```
bhasha-compiler/
├── build/                    ← Your build directory
│   └── bhasha-compiler       ← The executable you use
├── examples/                 ← Example programs
│   ├── hello.bhasha
│   └── variables.bhasha
├── include/                  ← Source headers
├── src/                      ← Source code
├── CMakeLists.txt
└── README.md
```

## Next Steps

1. Complete all steps above
2. Run the examples
3. Write your own BHASHA programs
4. Test them with the compiler
5. Submit your project to your instructor

That's it! You now have a working compiler!
