# Big Integer Arithmetic Algorithms

[![C++](https://img.shields.io/badge/language-C++-blue.svg)](https://isocpp.org/)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)
[![Build Status](https://img.shields.io/badge/build-passing-brightgreen.svg)]()

**A C++ implementation of arbitrary-precision integer addition and subtraction using a custom Stack ADT.**  
*Perfect for showcasing data structures, OOP, and algorithmic problem-solving to recruiters.*

## Project Overview

Physical machines have fixed limits for integer sizes (e.g., 32/64-bit). This project overcomes that limitation by implementing big-integer arithmetic using stacks to handle **arbitrarily large numbers** (tested with 20+ digit numbers).

**Key Concepts Demonstrated:**
- Linked-list based **Stack ADT**
- Digit-by-digit processing with carry/borrow handling
- Sign management and operand swapping for negative results
- Right-aligned formatted output
- File I/O for batch processing expressions

## Features

- Supports `+` and `-` operations on positive/negative large integers
- Handles cases where minuend < subtrahend (produces negative results)
- Removes leading zeros in results
- Clean, modular OOP design (`Stack`, `Operand`, `ArithmeticExpression`, `BigIntegerArithmetic`, `ExpressionReader`)
- Comprehensive unit tests using Catch2
- Memory-leak free (verified via project requirements)

## Sample Run

```bash
 12
+ 5
 17
----------
  5
+12
 17
----------
 12
- 5
  7
----------
  5
-12
 -7
----------
  364287463834623846283426384
+ 923742938742934723947239847
 1288030402577558570230666231
----------
 364287463834623846283426384
-923742938742934723947239847
-559455474908310877663813463
----------

# Build and Run

```# Clone and navigate to project
   make main          # Build the main executable
   ./main             # Run sample expressions from test/expressions.txt

   make test-all      # Run all unit tests (requires Catch2)
   make clean         # Clean build artifacts
   ```
