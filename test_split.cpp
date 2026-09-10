/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include <iostream>
#include "split.h"

int main(int argc, char* argv[])
{
    Node* odds = nullptr;
    Node* evens = nullptr;
    //Node* input = nullptr; //test 1: empty list, results in seg fault
    //Node* input = new Node{3, new Node{6, nullptr}}; //test 2: general
    Node* input = new Node{1, new Node{9, nullptr}}; //test 3: odds
    //Node* input = new Node{2, new Node{8, nullptr}}; //test 4: evens

    split(input, odds, evens);

    //Testing values:
    std::cout << "Odd Node: " << odds->next->value << std::endl;
    //std::cout << "Even Node: " << evens->next->value << std::endl;
    //std::cout << "Input Check: " << input << std::endl;

    //Testing addresses:
    //std::cout << "Odd Node: " << odds << std::endl;
    std::cout << "Even Node: " << evens << std::endl;
    //std::cout << "Input Check: " << input << std::endl;


    return 0;
}
