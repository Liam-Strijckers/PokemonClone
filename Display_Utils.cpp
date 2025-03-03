#include <iostream>
#include "Display_Utils.h"

//displays a singular move object
void display(const Moves &move){
    std::cout << "\n ========Moves==========" << std::endl;
    std::cout << move << std::endl;
}

//displays move objects in a vector of move objects
void display(std::vector<Moves> &moves){
    std::cout << "\n ========Moves==========" << std::endl;
    for(const auto &move:moves){
        std::cout << move << std::endl;
    }
}