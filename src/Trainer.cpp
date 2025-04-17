#include "Trainer.h"

bool Trainer::AddPokemon(const PokemonData &PokemonData){
    for(int i = 0; i<NUM_PARTY_POKEMON;i++){
        if(party.at(i) == Pokemon{}){
            party.at(i) == Pokemon{PokemonData};
            return true;
        }
    }
    return false;
}

bool Trainer::SwapPrimPokemon(int indexNewPrim){
    if(party.at(indexNewPrim).GetFaintedStatus() || party.at(indexNewPrim) == Pokemon{}){
        return false;
    }
    pointPrimPokemon = &party.at(indexNewPrim);
    return true;
}

