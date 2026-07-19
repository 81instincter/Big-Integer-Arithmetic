#include "stack.hpp"
#include <vector>

Node::Node(int newData){
    this -> data = newData;
    this -> next = nullptr;
}

int Node::getValue(){
    return this -> data;
}

Node* Node::getNext(){
    return this -> next;
}

void Node::setNext(Node* newNext){
    this -> next = newNext;
}

void Stack::push(int v){            
    Node* pushNode = new Node(v);          // newNode = allocated new linked list node, newNode -> data = item
    pushNode -> setNext(this -> top); // newNode -> next = stack -> top
    this -> top = pushNode;                        // stack -> top = newNode
    size++;
}

int Stack::pop(){
    if (this -> top == nullptr){
        //cout << "Stack Underflow" << endl;
        return -1;
    }
    else{
        int poppedVal = this -> top -> getValue();
        Node* tempNext = this -> top -> getNext();
        delete top; // delete the old previous top node to save memory
        this -> top = tempNext; // set the new top node as the old top node's next node 
        size--;
        return poppedVal;
    }
}

int Stack::peek(){
    if (this -> top == nullptr){
        cout << "Stack is Empty" << endl;
        return -1;
    }
    else{
        return this -> top -> getValue();
    }
}


bool Stack::empty(){
    if (this -> top == nullptr){
        return true;
    }
    else {
        return false;
    }
}

void Stack::display(){ // [2]
    Node* temp;
    if (this -> top == nullptr){
        cout << "Stack is empty" << endl;
    }
    else{
        temp = this -> top;
        cout << "Stack elements (from top to bottom) are: ";
        while (temp != nullptr){
            cout << temp -> getValue() << " ";
            temp = temp -> getNext();
        }
    }
    cout << endl;
}

string Stack::stackStringDisplay(){ // {^}
    stackString = ""; // Clear previous content
    Node* temp;
    if (this -> top == nullptr){
        return " ";
    }
    else{
        temp = this -> top;
        vector<char> stackDigits;
        while (temp != nullptr){
            stackDigits.push_back((temp -> getValue()) + '0'); // add a '0' to an integer to turn it into a character
            temp = temp -> getNext();
        }

        for (int i = stackDigits.size() - 1; i >= 0; i--){
            stackString += stackDigits[i];
        }
    }
    return this -> stackString;
}

int Stack::getSize(){
    return size;
}

/*
{^}
For the carryAddition() and borrowSubtraction() operators under big-integer-arithmetic.hpp

Sources:
[2] Display function
    https://www.tutorialspoint.com/cplusplus-program-to-implement-stack-using-linked-list
*/