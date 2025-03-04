#include <iostream>
#include <vector>
#include "Moves.h"
#include "Moves.cpp"
#include "Display_Utils.h"
#include "Display_Utils.cpp"
#include "Pokemon.h"
#include "Pokemon.cpp"

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


    Pokemon Empty {};
    display(Empty);
    display(Empty.get_moves());
    Empty.learnMove("Flamethrower", "Fire", 90, 100, 0, 15);
    display(Empty.get_moves());

    Pokemon Charizard {6, "Charizard", "Charizard", "Fire", "Flying", 78, 52, 84, 78, 109, 85, 100, 1000, CharizardMoves};
    display(Charizard);
    display(Charizard.get_moves());
    cout << Charizard.learnMove("Flamethrower", "Fire", 90, 100, 0, 15);
    display(Charizard.get_moves());

    return 0;
}