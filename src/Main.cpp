#include <iostream>
#include <vector>

#include "DisplayUtils.h"
#include "Moves.h"
#include "Pokemon.h"

using namespace std;

int main() {
  Moves empty{};
  display(empty);

  const array<Moves, NUM_MOVES> CharizardMoves {
    MovesData{"Flamethrower", Fire, 90, 100, 0, 15},
    MovesData{"Fire Spin", Fire, 35, 85, 0, 15},
    MovesData{"Slash", Normal, 70, 100, 0, 20},
    MovesData{"Rage", Normal, 20, 100, 0, 20}
  };
  display(CharizardMoves);




  PokemonData CharizardData{"Charizard", "Charizard", Fire, Flying, 78, 52, 84, 78, 109, 85, 100, 100, 1000};
  Pokemon Charizard {CharizardData};
  MovesData Flamethrower {"Flamethrower", Fire, 90, 100, 0, 15};
  Charizard.LearnMove(Flamethrower);
  display(Charizard.GetMoves());
  // Pokemon Charizard{
  //     6,  "Charizard", "Charizard", "Fire", "Flying", 78,   52,
  //     84, 78,          109,         85,     100,      1000, CharizardMoves};

  // display(Charizard);
  // display(Charizard.get_moves());
  // cout << Charizard.learnMove("Flamethrower", "Fire", 90, 100, 0, 15);
  // display(Charizard.get_moves());

  return 0;
}