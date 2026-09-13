# Assignment 2: Syntax, Semantics, and Memory Management

**Course:** MSCS-632-M30 — Advanced Programming Languages  
**Student:** Anulekha Kavutarapu  
**University:** University of the Cumberlands  
**Term:** Fall 2026

## Overview

This assignment analyzes syntax error handling, type systems, scoping, closures, and memory management across multiple programming languages.

## Repository Structure

```
assignment2/
├── part1_section1/          # Syntax error analysis
│   ├── python/
│   │   ├── calculate_sum_original.py
│   │   └── calculate_sum_error.py
│   ├── javascript/
│   │   ├── calculateSum_original.js
│   │   └── calculateSum_error.js
│   └── cpp/
│       ├── calculate_sum_original.cpp
│       └── calculate_sum_error.cpp
├── part1_section2/          # Type systems, scoping, and closures
│   ├── python/type_scope_demo.py
│   ├── javascript/typeScopeDemo.js
│   └── cpp/type_scope_demo.cpp
├── part2_section3/          # Memory management
│   ├── rust/memory_demo.rs
│   ├── java/MemoryDemo.java
│   └── cpp/memory_demo.cpp
└── README.md
```

## How to Run

### Part 1, Section 1 (Syntax Errors)
```bash
# Python
python3 calculate_sum_original.py
python3 calculate_sum_error.py

# JavaScript
node calculateSum_original.js
node calculateSum_error.js

# C++
g++ -o calculate_sum calculate_sum_original.cpp && ./calculate_sum
g++ -o calculate_sum_err calculate_sum_error.cpp
```

### Part 1, Section 2 (Type Systems and Scoping)
```bash
# Python
python3 type_scope_demo.py

# JavaScript
node typeScopeDemo.js

# C++
g++ -std=c++17 -o type_scope_demo type_scope_demo.cpp && ./type_scope_demo
```

### Part 2, Section 3 (Memory Management)
```bash
# Rust
rustc memory_demo.rs -o memory_demo && ./memory_demo

# Java
javac MemoryDemo.java && java -verbose:gc MemoryDemo

# C++
g++ -std=c++17 -o memory_demo memory_demo.cpp && ./memory_demo
# With Valgrind (memory profiling):
valgrind --tool=memcheck --leak-check=full ./memory_demo
```

## Languages and Tools Used
- Python 3.x
- JavaScript (Node.js)
- C++ (g++ with C++17)
- Rust (rustc)
- Java (JDK 21)
- Valgrind (memory profiling for C++)
