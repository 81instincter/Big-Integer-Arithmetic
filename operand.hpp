#ifndef OPERAND_H
#define OPERAND_H

#include "stack.hpp"
#include <vector>

class Operand{
    private:
        string value;
        char sign; 
    public:
        Operand() = default; 
        Operand(string v);
        string getValue();
        char getSign();
        void setValue(string v);
        void flipSign();
        bool isNegative();
        
        Stack valueToStack(); // setter function
};

#endif

/*

{*} I needed to define a default constructor for the Operand class 
to get the parameterized ArithmeticExpression constructor in arithmetic-expression.cpp 
to work properly.

    3/19/2025 - The same thing here needed to get applied to arithmetic-expression.hpp and big-integer-arithmetic.hpp
       
*/