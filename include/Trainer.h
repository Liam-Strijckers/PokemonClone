#ifndef _TRAINER_H_
#define _TRAINER_H_

#include <array>
#include <iostream>

#include "Pokemon.h"

static constexpr int NUM_PARTY_POKEMON{6};

class Trainer{
public:
    bool AddPokemon(const PokemonData &PokemonData);
    bool SwapPrimPokemon(int indexNewPrim);
private:
    std::array<Pokemon,NUM_PARTY_POKEMON> m_party {};
    Pokemon *m_pointPrimPokemon = &m_party.at(0);
};


#endif