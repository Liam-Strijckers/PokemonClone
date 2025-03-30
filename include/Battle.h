#ifndef _BATTLE_H_
#define _BATTLE_H_

#include <string>

#include "MoveInteraction.h"
#include "Pokemon.h"


class Battle{
public:
    void Attack(Pokemon &attackingPokemon, int moveIndex, Pokemon &defendingPokemon);
private:
    int damageCalc(const Pokemon &attackingPokemon, int moveIndex, const Pokemon &defendingPokemon);
    double typeEffectivenssLookUp(const enum MoveType &attackingType, const enum MoveType &defendingType);
};
#endif