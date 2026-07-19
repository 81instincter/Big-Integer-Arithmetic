#ifndef ARITHMETIC_EXPRESSION_H
#define ARITHMETIC_EXPRESSION_H

#include "operand.hpp"

class ArithmeticExpression{
    private:
        Operand operand1;
        Operand operand2;

        string operand1String;
        string operand2String;

        char operatorSymbol;

    public:
        ArithmeticExpression() = default;
        ArithmeticExpression(string op1, string op2, char opSymbol);
        
        Operand getOp1_();
        Operand getOp2_();

        string getOp1();
        string getOp2();

        char getOperator();
};

#endif