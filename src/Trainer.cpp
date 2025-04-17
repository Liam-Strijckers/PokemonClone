#include "Trainer.h"

bool Trainer::AddPokemon(const PokemonData &PokemonData){
    for(int i = 0; i<NUM_PARTY_POKEMON;i++){
        if(m_party.at(i) == Pokemon{}){
            m_party.at(i) == Pokemon{PokemonData};
            return true;
        }
    }
    return false;
}

bool Trainer::SwapPrimPokemon(int indexNewPrim){
    if(m_party.at(indexNewPrim).GetFaintedStatus()){
        return false;
    }
    pointPrimPokemon = &m_party.at(indexNewPrim);
    return true;
}

