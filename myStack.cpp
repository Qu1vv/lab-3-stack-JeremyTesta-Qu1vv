#include "myStack.hpp"

#include <iostream>
#include <sstream>
using namespace std;
//CLion wanted expr
constexpr int EMPTY = -1;

MyStack::MyStack() : currentIndex(EMPTY) {}

//checks for a full stack by taking array size -1 to see if index's 0-9 are filled.
bool MyStack::full() const {
    if(currentIndex == TEN - 1) {
        return true;
    }else {
        return false;
    }
}
//checks if current index is at -1 telling us the stack is currently empty.
bool MyStack::empty() const{
    if(currentIndex == EMPTY) {
        return true;
    }
    return false;
}
//Pushes the passed in value to the top of the stack if its not full.
bool MyStack::push(int value) {
    if(full()) {
        return false;
    }else {
        //++ in front otherwise we'd be out of bounds at start.
        stack[++currentIndex] = value;
        return true;
    }
}
//We pop by moving from top of stack down by 1 decrementing the index.
void MyStack::pop() {
    if(!empty()) {
        --currentIndex;
    }
}
//top returns current element at the top of stack or a error message if it is empty.
int MyStack::top() const {
    if(!empty()) {
        return stack[currentIndex];
    }else {
        //cerr isnt working(not callable), may change
        throw std::out_of_range("Stack is empty");
    }
}
//Prints out the whole stack until we reach the end and puts a ' ' in between values.
std::string MyStack::print() const {
    std::stringstream ss;

    if (empty()) {
        return "";  // If empty, return an empty string
    } else {
        for (int i = 0; i <= currentIndex; ++i) {
            ss << stack[i] << " ";  // Add each element followed by a space
        }
    }

    return ss.str();
}

