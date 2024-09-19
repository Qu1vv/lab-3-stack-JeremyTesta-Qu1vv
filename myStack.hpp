//
// Created by jerem on 2024-09-17.
//
#include <string>
#ifndef MYSTACK_HPP
#define MYSTACK_HPP
constexpr int TEN = 10;
class MyStack {
private:
    int currentIndex;
    int stack[TEN];
public:
    //my constructor
    MyStack();

    //Member functions (commented in .cpp file)
    bool push(int add);
    bool full() const;
    bool empty() const;
    void pop();
    int top() const;

    std::string print() const;
};
#endif //MYSTACK_HPP
