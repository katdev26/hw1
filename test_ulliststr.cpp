#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    ULListStr test;

    test.push_back("on");
    test.push_front("fight");

    std::cout << test.get(0) << std::endl; 
    std::cout << test.front() << std::endl; 
    std::cout << test.back() << std::endl;
    std::cout << test.size() << std::endl; 
    
    //test.pop_back();
    //std::cout << test.back() << std::endl;
    //std::cout << test.size() << std::endl; 


    test.pop_front();
    std::cout << test.front() << std::endl; 
    std::cout << test.size() << std::endl;
    std::cout <<test.empty() << std::endl; 

    test.pop_back();
    std::cout << test.size() << std::endl;
    std::cout <<test.empty() << std::endl; 

    int i = 0;
    while(i < 12){
        test.push_back("hi");
        i++;
    }

    std::cout << "New Size: " << test.size() << std::endl;
    std::cout << "Got: " << test.get(10) << std::endl;

    test.pop_back();
    test.pop_back();
    std::cout << "New Size: " << test.size() << std::endl;
    
    std::cout << "Testing test.back() once more: " << test.back() <<std::endl;
    return 0;


}
