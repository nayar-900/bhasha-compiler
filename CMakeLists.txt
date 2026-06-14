cmake_minimum_required(VERSION 3.10)
project(BhashaCompiler VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(bhasha-compiler
    src/main.cpp
    src/lexer.cpp
    src/parser.cpp
    src/semantic_analyzer.cpp
    src/code_generator.cpp
    src/symbol_table.cpp
    src/ast.cpp
)

install(TARGETS bhasha-compiler DESTINATION bin)
