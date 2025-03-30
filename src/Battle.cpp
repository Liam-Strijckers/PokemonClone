#include "Battle.h"

void Battle::Attack(Pokemon &attackingPokemon, int moveIndex, Pokemon &defendingPokemon){
    int damage = damageCalc (attackingPokemon, moveIndex, defendingPokemon);
    defendingPokemon.DecrementCurrentHP(damage);
    //need to add way to decrement move PP from pokemon class, I think this is disconnected rn
}

int Battle::damageCalc(const Pokemon &attackingPokemon, int moveIndex, const Pokemon &defendingPokemon){
    double adRatio = attackingPokemon.data.attack/defendingPokemon.data.defense;
    double topFraction  = ((2 * attackingPokemon.data.level * (1 + attackingPokemon.GetMoves().at(moveIndex).data.critcalChance))/5)+2;
    double fraction = ((topFraction * attackingPokemon.GetMoves().at(moveIndex).data.power * adRatio)/5)+2;
    double STAB = 1;
    if((attackingPokemon.GetMoves().at(moveIndex).data.type == attackingPokemon.data.primaryType) || (attackingPokemon.GetMoves().at(moveIndex).data.type == attackingPokemon.data.secondaryType)){
        STAB = 1.5;
    }
    double type1Effect = typeEffectivenssLookUp(attackingPokemon.data.primaryType, defendingPokemon.data.primaryType);
    double typ2Effect = typeEffectivenssLookUp(attackingPokemon.data.secondaryType, defendingPokemon.data.secondaryType);
    double damage = fraction * STAB * type1Effect * typ2Effect;
    return int (damage);
}

double Battle::typeEffectivenssLookUp(const enum MoveType &attackingType, const enum MoveType &defendingType){
    return TypeEffectivenessLookUp.at(attackingType).at(defendingType);
}