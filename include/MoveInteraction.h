#ifndef _MOVEINTERACTION_H_
#define _MOVEINTERACTION_H_

#include <array>
#include <vector>
#include <iostream>

static constexpr int NUM_TYPES{15};

enum MoveType {
    Normal,
    Fire,
    Water,
    Electric,
    Grass,
    Ice,
    Fighting,
    Poison,
    Ground,
    Flying,
    Psychic,
    Bug,
    Rock,
    Ghost,
    Dragon
  };

std::array<std::array<double,NUM_TYPES>,NUM_TYPES> TypeEffectivenessLookUp;
/*
Below is the code for setting the Type Effectiveness Look Up Table
according to this table https://img.pokemondb.net/images/typechart-gen1.png
https://godbolt.org/z/srssvE783

std::array<std::array<double,NUM_TYPES>,NUM_TYPES> TypeEffectivenessLookUp;
    for (auto & row : TypeEffectivenessLookUp){
        std::fill_n(row.begin(), row.size(), 1.0);
    }
    TypeEffectivenessLookUp.at(Normal).at(Rock) = 0.5;
    TypeEffectivenessLookUp.at(Normal).at(Ghost) = 0;
    TypeEffectivenessLookUp.at(Fire).at(Fire) = 0.5;
    TypeEffectivenessLookUp.at(Fire).at(Water) = 0.5;
    TypeEffectivenessLookUp.at(Fire).at(Grass) = 2.0;
    TypeEffectivenessLookUp.at(Fire).at(Ice) = 2.0;
    TypeEffectivenessLookUp.at(Fire).at(Bug) = 2.0;
    TypeEffectivenessLookUp.at(Fire).at(Rock) = 0.5;
    TypeEffectivenessLookUp.at(Fire).at(Dragon) = 0.5;
    TypeEffectivenessLookUp.at(Water).at(Fire) = 2.0;
    TypeEffectivenessLookUp.at(Water).at(Water) = 0.5;
    TypeEffectivenessLookUp.at(Water).at(Grass) = 0.5;
    TypeEffectivenessLookUp.at(Water).at(Ground) = 2.0;
    TypeEffectivenessLookUp.at(Water).at(Rock) = 2.0;
    TypeEffectivenessLookUp.at(Water).at(Dragon) = 0.5;
    TypeEffectivenessLookUp.at(Electric).at(Water) = 2.0;
    TypeEffectivenessLookUp.at(Electric).at(Electric) = 0.5;
    TypeEffectivenessLookUp.at(Electric).at(Grass) = 0.5;
    TypeEffectivenessLookUp.at(Electric).at(Ground) = 0.0;
    TypeEffectivenessLookUp.at(Electric).at(Flying) = 2.0;
    TypeEffectivenessLookUp.at(Electric).at(Dragon) = 0.5;
    TypeEffectivenessLookUp.at(Grass).at(Fire) = 0.5;
    TypeEffectivenessLookUp.at(Grass).at(Water) = 2.0;
    TypeEffectivenessLookUp.at(Grass).at(Grass) = 0.5;
    TypeEffectivenessLookUp.at(Grass).at(Poison) = 0.5;
    TypeEffectivenessLookUp.at(Grass).at(Ground) = 2.0;
    TypeEffectivenessLookUp.at(Grass).at(Flying) = 0.5;
    TypeEffectivenessLookUp.at(Grass).at(Bug) = 0.5;
    TypeEffectivenessLookUp.at(Grass).at(Rock) = 2.0;
    TypeEffectivenessLookUp.at(Grass).at(Dragon) = 0.5;
    TypeEffectivenessLookUp.at(Ice).at(Water) = 0.5;
    TypeEffectivenessLookUp.at(Ice).at(Grass) = 2.0;
    TypeEffectivenessLookUp.at(Ice).at(Ice) = 0.5;
    TypeEffectivenessLookUp.at(Ice).at(Ground) = 2.0;
    TypeEffectivenessLookUp.at(Ice).at(Flying) = 2.0;
    TypeEffectivenessLookUp.at(Ice).at(Dragon) = 2.0;
    TypeEffectivenessLookUp.at(Fighting).at(Normal) = 2.0;
    TypeEffectivenessLookUp.at(Fighting).at(Ice) = 2.0;
    TypeEffectivenessLookUp.at(Fighting).at(Poison) = 0.5;
    TypeEffectivenessLookUp.at(Fighting).at(Flying) = 0.5;
    TypeEffectivenessLookUp.at(Fighting).at(Psychic) = 0.5;
    TypeEffectivenessLookUp.at(Fighting).at(Bug) = 0.5;
    TypeEffectivenessLookUp.at(Fighting).at(Rock) = 2.0;
    TypeEffectivenessLookUp.at(Fighting).at(Ghost) = 0;
    TypeEffectivenessLookUp.at(Poison).at(Grass) = 2.0;
    TypeEffectivenessLookUp.at(Poison).at(Poison) = 0.5;
    TypeEffectivenessLookUp.at(Poison).at(Ground) = 0.5;
    TypeEffectivenessLookUp.at(Poison).at(Bug) = 2.0;
    TypeEffectivenessLookUp.at(Poison).at(Rock) = 0.5;
    TypeEffectivenessLookUp.at(Poison).at(Ghost) = 0.5;
    TypeEffectivenessLookUp.at(Ground).at(Fire) = 2.0;
    TypeEffectivenessLookUp.at(Ground).at(Electric) = 2.0;
    TypeEffectivenessLookUp.at(Ground).at(Grass) = 0.5;
    TypeEffectivenessLookUp.at(Ground).at(Poison) = 2.0;
    TypeEffectivenessLookUp.at(Ground).at(Flying) = 0;
    TypeEffectivenessLookUp.at(Ground).at(Bug) = 0.5;
    TypeEffectivenessLookUp.at(Ground).at(Rock) = 2.0;
    TypeEffectivenessLookUp.at(Flying).at(Electric) = 0.5;
    TypeEffectivenessLookUp.at(Flying).at(Grass) = 2.0;
    TypeEffectivenessLookUp.at(Flying).at(Fighting) = 2.0;
    TypeEffectivenessLookUp.at(Flying).at(Bug) = 2.0;
    TypeEffectivenessLookUp.at(Flying).at(Rock) = 0.5;
    TypeEffectivenessLookUp.at(Psychic).at(Fighting) = 2.0;
    TypeEffectivenessLookUp.at(Psychic).at(Poison) = 2.0;
    TypeEffectivenessLookUp.at(Psychic).at(Psychic) = 0.5;
    TypeEffectivenessLookUp.at(Bug).at(Fire) = 0.5;
    TypeEffectivenessLookUp.at(Bug).at(Grass) = 2.0;
    TypeEffectivenessLookUp.at(Bug).at(Fighting) = 0.5;
    TypeEffectivenessLookUp.at(Bug).at(Poison) = 2.0;
    TypeEffectivenessLookUp.at(Bug).at(Flying) = 0.5;
    TypeEffectivenessLookUp.at(Bug).at(Psychic) = 2.0;
    TypeEffectivenessLookUp.at(Bug).at(Ghost) = 0.5;
    TypeEffectivenessLookUp.at(Rock).at(Fire) = 2.0;
    TypeEffectivenessLookUp.at(Rock).at(Ice) = 2.0;
    TypeEffectivenessLookUp.at(Rock).at(Fighting) = 0.5;
    TypeEffectivenessLookUp.at(Rock).at(Ground) = 0.5;
    TypeEffectivenessLookUp.at(Rock).at(Flying) = 2.0;
    TypeEffectivenessLookUp.at(Rock).at(Bug) = 2.0;
    TypeEffectivenessLookUp.at(Ghost).at(Normal) = 0;
    TypeEffectivenessLookUp.at(Ghost).at(Psychic) = 0;
    TypeEffectivenessLookUp.at(Ghost).at(Ghost) = 2.0;
    TypeEffectivenessLookUp.at(Dragon).at(Dragon) = 2.0;


*/
#endif