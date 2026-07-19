#include "big-integer-arithmetic.hpp"
#include <sstream> // [5]
#include <iomanip> // [12]
#include <string>
#include <algorithm>

//Executes the function to compute the integer operation
BigIntegerArithmetic::BigIntegerArithmetic(ArithmeticExpression ae){
    // Puts in the class string private variables for display purposes
    firstOperandString = ae.getOp1_().getValue();
    secondOperandString = ae.getOp2_().getValue();
    opSymbol = ae.getOperator();

    // This block deals with the conversion of the operands to stacks
    if (operandComp(ae.getOp1(), ae.getOp2()) <= 0 && ae.getOperator() == '-'){ 
        // flips operation of subtracting a big number from a small number to be 
        // taking the negative of subtracting a small number from a big number 
        // i.e. 30 - 45 = - (45 - 30)

        Stack greaterOperandStack = ae.getOp2_().valueToStack();
        Stack lesserOperandStack = ae.getOp1_().valueToStack();
    
        if (ae.getOp2_().getSign() == '-'){
            carryAddition(greaterOperandStack, lesserOperandStack);
        }
        else{
            bool shouldNegate = true;
            borrowSubtraction(greaterOperandStack, lesserOperandStack, shouldNegate);
        }
    }

    else{
        Stack operand1Stack = ae.getOp1_().valueToStack();
        Stack operand2Stack = ae.getOp2_().valueToStack();
        digitByDigitOperation(operand1Stack, operand2Stack, ae.getOperator());
    }
}

int BigIntegerArithmetic::operandComp(Operand op1, Operand op2){
    // Returns +1 if op1 > op2, or 0 if op1 == op2, or -1 if op1 < op2

    string op1String = op1.getValue();
    string op2String = op2.getValue();

    // first checks to see if one operand is bigger than the other in terms of number of digits
    if (op1String.length() > op2String.length()){
        return 1;
    }
    else if (op1String.length() < op2String.length()){
        return -1;
    }
    else{ // {$}
        for (size_t i = 0; i < op1String.length(); i++){
            if ( (op1String[i] - '0') > (op2String[i] - '0') ){
                return 1;
            }
            else if ( (op1String[i] - '0') < (op2String[i] - '0') ) {
                return -1;
            }
        }
    }
    return 0; // the operands are exactly the same (e.g. 12345 == 12345)
}

// This function executes and returns the string results of the digit by digit addition/subtraction function
void BigIntegerArithmetic::carryAddition(Stack op1Stack, Stack op2Stack) {
    Stack sumStack;
    vector<int> sumStackElements;
    int carry = 0;

    while (!op1Stack.empty() || !op2Stack.empty() || carry != 0) {
        int d1 = op1Stack.empty() ? 0 : op1Stack.pop();
        int d2 = op2Stack.empty() ? 0 : op2Stack.pop();
        int total = d1 + d2 + carry;

        sumStackElements.push_back(total % 10);
        carry = total / 10;
    }

    // Copy back to stack (reverse order)
    for (size_t i = sumStackElements.size(); i-- > 0; ) {
        sumStack.push(sumStackElements[i]);
    }

    stringResult = sumStack.stackStringDisplay();
}

void BigIntegerArithmetic::borrowSubtraction(Stack greaterStack, Stack lesserStack, bool negate) {
    Stack differenceStack;
    vector<int> differenceStackElements;
    int borrow = 0;

    while (!greaterStack.empty() || !lesserStack.empty() || borrow != 0) {
        int g = greaterStack.empty() ? 0 : greaterStack.pop();
        int l = lesserStack.empty() ? 0 : lesserStack.pop();

        g -= borrow;

        if (g < l) {
            g += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        differenceStackElements.push_back(g - l);
    }

    // Reverse into stack
    for (size_t i = differenceStackElements.size(); i-- > 0; ) {
        differenceStack.push(differenceStackElements[i]);
    }

    stringResult = differenceStack.stackStringDisplay();

    // Remove leading zeros
    size_t start = stringResult.find_first_not_of('0');
    if (start == string::npos) {
        stringResult = "0";
    } else {
        stringResult = stringResult.substr(start);
    }

    if (negate && stringResult != "0") {
        stringResult = "-" + stringResult;
    }
}
    

void BigIntegerArithmetic::digitByDigitOperation(Stack op1Stack, Stack op2Stack, char operation){
    // create a temporary vector to store the results of each decimal place operation result
    
    if (operation == '+'){ // {Refer to carryAddition.txt}
        carryAddition(op1Stack, op2Stack);
    }

    else if (operation == '-'){ // {Refer to borrowSubtraction.txt}
        borrowSubtraction(op1Stack, op2Stack, false);
    }

    else {
        cout << "Invalid arithmetic operator!" << endl;
    }
}

string BigIntegerArithmetic::getResults() {
    string opString1 = firstOperandString;
    string opString2 = secondOperandString;
    char op = opSymbol;

    stringstream ss; 
    int maxWidth;

    if (opSymbol == '+'){
        // Calculate the maximum width, adding 1 for potential spaces in formatting
        int maxWidth = max({opString1.length(), opString2.length(), stringResult.length()}) + 1;

        // Format the first operand, ensuring it's right-aligned
        ss << setw(maxWidth) << right << opString1 << '\n';

        // Format the operator and second operand, ensuring correct spacing
        if (op == '+') {
            ss << setw(maxWidth - opString2.length() - 1) << right << op << " " << opString2 << '\n';
        } else {
            ss << setw(maxWidth - opString2.length()) << right << op << opString2 << '\n';
        }

        // Format the result with correct spacing; handle negative result separately
        if (stringResult[0] == '-') {
            ss << setw(maxWidth) << right << stringResult; // for negative results
        } else {
            ss << setw(maxWidth) << right << stringResult; // for positive results
        }
    }

    else{
            // Calculate the maximum width, adding 1 for potential spaces in formatting
        maxWidth = max({opString1.length(), opString2.length(), stringResult.length()});

        // Format the first operand, ensuring it's right-aligned
        ss << setw(maxWidth) << right << opString1 << '\n';

        // Format the operator and second operand, ensuring correct spacing
        if (op == '+') {
            ss << setw(maxWidth - opString2.length() - 1) << right << op << " " << opString2 << '\n';
        } else {
            ss << setw(maxWidth - opString2.length()) << right << op << opString2 << '\n';
        }

        // Format the result with correct spacing; handle negative result separately
        if (stringResult[0] == '-') {
            ss << setw(maxWidth) << right << stringResult; // for negative results
        } else {
            ss << setw(maxWidth) << right << stringResult; // for positive results
        }
    }

    return ss.str();
}

/*
{$}
If the operands are of the same length, then a comparison is made of each integer's digit in the same decimal place 
to see if one integer's digit is greater in value than the  other integer's digit. 
*/