#include <iostream>
#include "Display_Utils.h"

//displays a singular move object
void display(const Moves &move){
    std::cout << "\n ========Moves==========" << std::endl;
    std::cout << move << std::endl;
}

//displays move objects in a vector of move objects
void display(const std::vector<Moves> &moves){
    std::cout << "\n ========Moves==========" << std::endl;
    for(const Moves &move:moves){
        std::cout << move << std::endl;
    }
}

void display(const Pokemon &pokemon){
    std::cout << "\n ========Pokemon==========" << std::endl;
    std::cout << pokemon << std::endl;
}

void display(const std::vector<Pokemon> &pokemons){
    std::cout << "\n ========Pokemon==========" << std::endl;
    for(const Pokemon &pokemon:pokemons){
        std::cout << pokemon << std::endl;
    }
}