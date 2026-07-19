#include "arithmetic-expression.hpp"

ArithmeticExpression::ArithmeticExpression(string op1, string op2, char opSymbol){
    operand1.setValue(op1); // {&} 
    operand2.setValue(op2);

    // logic for dealing with special operation cases 
    if (opSymbol == '-' && operand2.getSign() == '-' ){ // double negatives
        operand2.flipSign();
        operatorSymbol = '+';
    }
    else if (opSymbol == '+' && operand2.getSign() == '-'){ 
        operand2.flipSign();    // second operand is negative and operator is -, turning the arithmetic 
        operatorSymbol = '-';   // into an addition between two positive numbers
    }
    else {
        operatorSymbol = opSymbol;
    }
}

Operand ArithmeticExpression::getOp1_(){
    return operand1;
}

Operand ArithmeticExpression::getOp2_(){
    return operand2;
}

string ArithmeticExpression::getOp1(){
    return operand1.getValue();
}

string ArithmeticExpression::getOp2(){
    return operand2.getValue();
}

char ArithmeticExpression::getOperator(){
    return operatorSymbol;
}

// {&} needed to define a default constructor for the Operand class to get this to work