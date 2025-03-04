#ifndef _DISPLAY_UTILS_H_
#define _DISPLAY_UTILS_H_
#include <vector>
#include "Moves.h"
#include "Pokemon.h"

void display(const Moves &move);
void display(const std::vector<Moves> &moves);

void display(const Pokemon &pokemon);
void display(const std::vector<Pokemon> &pokemons);

#endif