#include <iostream>
#include <vector>
#include "Moves.h"
#include "Display_Utils.h"
#include "Pokemon.h"

using namespace std;

int main(){
    Moves empty {};
    display(empty);

    // vector<Moves> CharizardMoves;
    // CharizardMoves.push_back(Moves{"Flamethrower", "Fire", 90, 100, 0, 15});
    // CharizardMoves.push_back(Moves{"Fire Spin", "Fire", 35, 85, 0, 15});
    // CharizardMoves.push_back(Moves{"Slash", "Normal", 70, 100, 0, 20});
    // CharizardMoves.push_back(Moves{"Rage", "Normal", 20, 100, 0, 20});
    // display(CharizardMoves);


    // Pokemon Empty {};
    // display(Empty);
    // display(Empty.GetMoves());
    // Empty.learnMove("Flamethrower", "Fire", 90, 100, 0, 15);
    // display(Empty.GetMoves());


    PokemonData CharizardData{"Charizard", "Charizard", "Fire", "Flying", 78, 52, 84, 78, 109, 85, 100, 1000,};


    // Pokemon Charizard {6, "Charizard", "Charizard", "Fire", "Flying", 78, 52, 84, 78, 109, 85, 100, 1000, CharizardMoves};
    Pokemon Charizard{CharizardData};
    display(Charizard);
    display(Charizard.GetMoves());
    cout << Charizard.GetMoves("Flamethrower", "Fire", 90, 100, 0, 15);
    display(Charizard.GetMoves());

    return 0;
}