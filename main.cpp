#include <iostream>
#include <vector>
#include "Moves.h"
#include "Moves.cpp"
#include "Display_Utils.h"
#include "Display_Utils.cpp"

using namespace std;

int main(){
    Moves empty {};
    display(empty);

    vector<Moves> CharizardMoves;
    CharizardMoves.push_back(Moves{"Flamethrower", "Fire", 90, 100, 0, 15});
    CharizardMoves.push_back(Moves{"Fire Spin", "Fire", 35, 85, 0, 15});
    CharizardMoves.push_back(Moves{"Slash", "Normal", 70, 100, 0, 20});
    CharizardMoves.push_back(Moves{"Rage", "Normal", 20, 100, 0, 20});

    display(CharizardMoves);

    return 0;
}