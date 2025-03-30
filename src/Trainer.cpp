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
    m_refPrimPokemon = m_party.at(indexNewPrim);
}

