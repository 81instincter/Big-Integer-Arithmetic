#include "expression-reader.hpp"
#include <fstream>
#include <sstream>
#include <vector>

ExpressionReader::ExpressionReader(string filePath)
{
    currentExpressionIndex = 0;

    string fileText;
    
    if (filePath != "test/expressions.txt"){
        cout << "Error: Incorrect file path provided. Error code 1." << endl;
        exit(1); 
    }
    else{
        ifstream MyReadFile(filePath); // [13]
        while (getline(MyReadFile, fileText)){
            fileLines.push_back(fileText);
        }
    }
}

bool ExpressionReader::readNextExpression(){
    if (static_cast<size_t>(currentExpressionIndex) > fileLines.size()){
        return false;
    }

    string currentExpression = fileLines[currentExpressionIndex];

    // extract the operands and the operation symbol 
    stringstream ss(currentExpression);
    string term;
    vector<string> terms; 
    
    while (getline(ss, term, ' ')){
        terms.push_back(term);
    }

    fileOperand1Text = terms[0];
    fileOperand2Text = terms[2];
    fileExpressionOperator = terms[1][0];

    currentExpressionIndex++;

    return true;
}

string ExpressionReader::getResult(){
    ArithmeticExpression fileLineExpression(fileOperand1Text, fileOperand2Text, fileExpressionOperator);
    BigIntegerArithmetic bia(fileLineExpression);
    string biaResult = bia.getResults();
    return biaResult;
}