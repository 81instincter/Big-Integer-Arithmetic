#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

class Node{
    int data;
    Node *next;

    public:
        Node(int newData);
        int getValue();
        Node* getNext();
        void setNext(Node* newNext);

};

class Stack{ //[1]
    private:
        Node* top; // top of stack is the head of the linked list
        int size;
        string stackString;

    public:
        Stack () { this -> top = nullptr; size = 0; stackString = "";}
        void push(int newData);
        int pop(); // returns and removes top element of stack
        int peek(); // returns top element of stack without removing
        bool empty();
        void display(); // for testing purposes
        string stackStringDisplay();
        int getSize();
};

#endif

/*
Project Notes:

    Perform large integer operation using stacks
        - Create three stacks: two for the operands, one for the operator
        - For both operands, push every digit into the corresponding 
            stack starting from left to right
        - Pop one digit from each operand every time to calculate the result for this digit in the result stack
        - When one operand run out of digits before another, must handle it correctly
        - For each decimal place, apply the operations to both digits
            - include the carry and borrow bit from the last round as needed
            - set the new carry and borrow next rounds
        - Clean up the leading zero in subtraction
*/