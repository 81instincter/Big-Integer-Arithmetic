#ifndef EXPRESSION_READER_H
#define EXPRESSION_READER_H

#include "big-integer-arithmetic.hpp"

class ExpressionReader{
    private:
        int currentExpressionIndex;
        vector<string> fileLines;
        string fileOperand1Text;
        string fileOperand2Text;
        char fileExpressionOperator;

    public:
        ExpressionReader() = default;
        ExpressionReader(string fp);
        bool readNextExpression();
        string getResult();
};

#endif