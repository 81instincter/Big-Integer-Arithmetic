#include "expression-reader.hpp"

int main(){

    ExpressionReader er("test/expressions.txt");

    er.readNextExpression();
    cout << er.getResult() << endl;
    cout << "----------" << endl;

    er.readNextExpression();
    cout <<  er.getResult() << endl;
    cout << "----------" << endl;

    er.readNextExpression();
    cout << er.getResult() << endl;
    cout << "----------" << endl;

    er.readNextExpression();
    cout << er.getResult() << endl;
    cout << "----------" << endl;
    
    er.readNextExpression();
    cout << er.getResult() << endl;
    cout << "----------" << endl;

    er.readNextExpression();
    cout << er.getResult() << endl;
    cout << "----------" << endl;

    return 0;
}