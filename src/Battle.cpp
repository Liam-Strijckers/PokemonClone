#include "Battle.h"

void Battle::Attack(Pokemon &attackingPokemon, int moveIndex, Pokemon &defendingPokemon){
    //need to add way to decrement move PP from pokemon class, I think this is disconnected rn
    if(attackingPokemon.moves.at(moveIndex).GetCurrentPP() > 0){
        int damage = damageCalc (attackingPokemon, moveIndex, defendingPokemon);
        defendingPokemon.DecrementCurrentHP(damage);
        attackingPokemon.moves.at(moveIndex).DecrementCurrentPP();
    }
    //if it is zero, try again
    
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
    std::pair<MoveType,MoveType> typePair = {attackingType,defendingType};
    auto it = TypeEffectivenessLookUp.find(typePair);
    if(it != TypeEffectivenessLookUp.end()){
        return TypeEffectivenessLookUp.at(typePair);
    }else{//no element in hash, is 1
        return 1.0; //default value
    }
}

void Battle::swapAttackDefendPokemon(){
    //std::swap
    //need to make a move constructor to swap the pokemon
    Pokemon &temp = AttackingPokemon;
    AttackingPokemon = DefendingPokemon;
    DefendingPokemon = temp;
}