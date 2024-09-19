#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "myStack.hpp"
//Jeremy Testa
//A01378143
TEST_CASE("A new stack is empty", "emptyStack")
{
    MyStack tester;

    REQUIRE(tester.empty() == true);
    REQUIRE(tester.full() == false);
}
TEST_CASE("Adding values and popping all making sure it's empty at end", "emptyStack") {
    MyStack tester;
    for(int i = 0; i < 4; i++) {
        tester.push(i);
    }
    for(int i = 0; i < 4; i++) {
        tester.pop();
    }
    REQUIRE(tester.empty() == true);
}
TEST_CASE("A new stack is full", "fullStack") {
    MyStack tester;
    for(int i = 0; i < 10; i++) {
        tester.push(i);
    }
    REQUIRE(tester.full() == true);
    REQUIRE(tester.empty() == false);
}
//Make sure you cant push to a full stack and top is still the same last value.
TEST_CASE("Pushing to a full stack", "fullStack") {
    MyStack tester;
    const int TWELVE = 12;
    const int NINE = 9;
    for(int i = 0; i < 10; i++) {
        tester.push(i);
    }
    tester.push(TWELVE);
    REQUIRE(tester.full() == true);
    REQUIRE(tester.top() == NINE);
}

//Make sure the top value is returned correctly
TEST_CASE("A stack's top value", "testTop") {
    const int FOUR = 4;
    MyStack tester;
    for(int i = 0; i < 5; i++) {
        tester.push(i);
    }
    REQUIRE(tester.top() == FOUR);
}
//Test top value after popping the starting top value
TEST_CASE("A stack's top value after pop", "testTop") {
    MyStack tester;
    const int THREE = 3;
    for(int i = 0; i < 5; i++) {
        tester.push(i);
    }
    tester.pop();
    REQUIRE(tester.top() == THREE);
}

TEST_CASE("Pushing a new value on stack, make sure top() is new value", "testTop") {
    MyStack tester;
    const int TEN = 10;
    for(int i = 0; i < 5; i++) {
        tester.push(i);
    }
    tester.push(TEN);
    REQUIRE(tester.top() == TEN);
}
TEST_CASE("Ensuring push returns correct value if a previous value was popped", "testPopPush") {
    MyStack tester;
    const int TEN = 10;
    const int THREE = 3;
    for(int i = 0; i < 5; i++) {
        tester.push(i);
    }
    tester.pop();
    tester.pop();
    tester.push(TEN);
    tester.push(THREE);
    REQUIRE(tester.top() == THREE);
    //std::cout << tester.print() << std::endl;
}
TEST_CASE("Make sure print method prints correctly and nicely and changes with pop and push", "testPrint") {
    MyStack tester;
    const int THREE = 3;
    for (int i = 0; i < 8; ++i) {
        tester.push(i);
    }

    // Pop two elements
    tester.pop();
    tester.pop();
    tester.push(THREE);

    // Expected output after the operations
    const std::string expectedOutput = "0 1 2 3 4 5 3 ";

    // Check if the printed string matches the expected output
    REQUIRE(tester.print() == expectedOutput);
}

