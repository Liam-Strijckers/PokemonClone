#ifndef _BATTLE_H_
#define _BATTLE_H_

#include <string>

#include "MoveInteraction.h"
#include "Moves.h"
#include "Pokemon.h"
#include "Trainer.h"


class Battle{
public:
    Battle() = delete;
    Battle(Trainer &UserTrainer, Trainer &CPUTrainer);

    void Attack(Pokemon &attackingPokemon, int moveIndex, Pokemon &defendingPokemon);
private:
    int damageCalc(const Pokemon &attackingPokemon, int moveIndex, const Pokemon &defendingPokemon);
    double typeEffectivenssLookUp(const enum MoveType &attackingType, const enum MoveType &defendingType);
    void swapAttackDefendPokemon();//need to change implemenmtation to use references
    void displayUserOptions();
    Trainer UserTrainer;
    Trainer CPUTrainer;
    Pokemon &AttackingPokemon {UserTrainer.GetPrimaryPokemon()};
    Pokemon &DefendingPokemon {CPUTrainer.GetPrimaryPokemon()};
};
#endif