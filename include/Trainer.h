#ifndef _TRAINER_H_
#define _TRAINER_H_

#include <array>
#include <iostream>

#include "Pokemon.h"

static constexpr int NUM_PARTY_POKEMON{6};

struct TrainerData{
    std::string name{};
};

class Trainer{
public:
    Trainer() = default;
    Trainer(const TrainerData &trainerData): data{trainerData} {};
    bool AddPokemon(const PokemonData &PokemonData);
    bool SwapPrimPokemon(int indexNewPrim);
    std::array<Pokemon,NUM_PARTY_POKEMON> party {Pokemon{},Pokemon{},Pokemon{},Pokemon{},Pokemon{},Pokemon{}};
    Pokemon *pointPrimPokemon = &party.at(0);


    const TrainerData data{};
private:
    
    
};


#endif