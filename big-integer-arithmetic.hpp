#ifndef BIG_INTEGER_ARITHMETIC_H
#define BIG_INTEGER_ARITHMETIC_H

#include "arithmetic-expression.hpp"
#include <string>

class BigIntegerArithmetic{
    private:
        string firstOperandString;
        string secondOperandString;
        char opSymbol;

        string stringResult;

    public:
        BigIntegerArithmetic() = default; // [7]
        BigIntegerArithmetic(ArithmeticExpression ae);
        int operandComp(Operand op1, Operand op2);
        void digitByDigitOperation(Stack op1Stack, Stack op2Stack, char operation);
        void carryAddition(Stack op1Stack, Stack op2Stack);
        void borrowSubtraction(Stack op1Stack, Stack op2Stack, bool negate);
        string prepareDisplay(string op1, string op2, char operatorSymbol, string result);
        string getResults();
};

#endif

