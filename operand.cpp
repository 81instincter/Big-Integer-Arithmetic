#include "operand.hpp"

Operand::Operand(string v){
    if (v.empty()) {
        value = "0";
        sign = '+';
        return;
    }
    // {1} used for extracting the number value of the operand, leaving the sign
    // {2} used for extracting the sign from the operand
    if (v[0] == '+') {
        sign = v[0]; // {2}
        value = v.substr(1); // {1}
    } 
    else if (v[0] == '-') { // keeps the negative
        sign = v[0];
        value = v;  
    } 
    else { // if the operand does not have a sign, then it is assumed to be positive
        value = v;
        sign = '+';
    }
}

string Operand::getValue(){
    return value;
}

char Operand::getSign(){
    return sign;
}

void Operand::setValue(string v){
    if (v.empty()) {
        value = "0";
        sign = '+';
        return;
    }
    // {1} used for extracting the number value of the operand, leaving the sign
    // {2} used for extracting the sign from the operand
    if (v[0] == '+'){
        sign = v[0]; // {2}
        value = v.substr(1); // {1}
    }
    else if (v[0] == '-') { // keeps the negative
        sign = v[0];
        value = v;
    }
    else{ // if the operand does not have a sign, then it is assumed to be positive
        value = v;
        sign = '+';
    }
}

void Operand::flipSign(){
    if (sign == '+') {
        sign = '-';
        if(!value.empty() && value[0] != '-'){
            value = "-" + value;
        }
    }
    else if (sign == '-'){
        if (!value.empty() && value[0] == '-') {
            value = value.substr(1);
        }
        sign = '+';
    }
}

bool Operand::isNegative(){
    return sign == '-';
}


Stack Operand::valueToStack(){ // {1.1}
    // Strip sign before converting digits to avoid segfault/crash on '-'
    string digitsStr = value;
    if (!digitsStr.empty() && (digitsStr[0] == '+' || digitsStr[0] == '-')) {
        digitsStr = digitsStr.substr(1);
    }

    int valLen = digitsStr.length();
    vector<int> digits; // {1.2}
    
    for (int i = 0; i < valLen;i++){ 
        digits.push_back(digitsStr[i] - '0'); 
    }

    Stack valStack;

    for (int j = 0; j < valLen; j++){
        valStack.push(digits.at(j));
    }

    return valStack;
}

/*
Notes:

{1.1}
This function extracts the digits from a value and puts each value into a node in a stack,
with the most significant bit being located at the bottom of the stack, and the least significant bit at the top.

{1.2}
Store each digit of the value into a vector to allow for easy creation of a stack of a number
tem at index 0 will be the MSB. Item at the last index will be the LSB.
*/