#ifndef _MOVEINTERACTION_H_
#define _MOVEINTERACTION_H_

#include <array>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <functional> // For std::hash


static constexpr int NUM_TYPES{15};

enum class MoveType {
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



namespace std {
    template <>
    struct hash<std::pair<MoveType, MoveType>> {
        size_t operator()(const std::pair<MoveType, MoveType>& pair) const {
            // Combine the hashes of the two MoveType elements
            size_t hash1 = std::hash<MoveType>{}(pair.first);
            size_t hash2 = std::hash<MoveType>{}(pair.second);
            return hash1 ^ (hash2 << 1); // XOR and shift to combine hashes
        }
    };
}

// std::array<std::array<double,NUM_TYPES>,NUM_TYPES> TypeEffectivenessLookUp;
std::unordered_map<std::pair<MoveType,MoveType>, double> TypeEffectivenessLookUp {
    {{MoveType::Normal, MoveType::Rock}, 0.5},
    {{MoveType::Normal, MoveType::Ghost}, 0.0},
    {{MoveType::Fire, MoveType::Fire}, 0.5},
    {{MoveType::Fire, MoveType::Water}, 0.5},
    {{MoveType::Fire, MoveType::Grass}, 2.0},
    {{MoveType::Fire, MoveType::Ice}, 2.0},
    {{MoveType::Fire, MoveType::Bug}, 2.0},
    {{MoveType::Fire, MoveType::Rock}, 0.5},
    {{MoveType::Fire, MoveType::Dragon}, 0.5},
    {{MoveType::Water, MoveType::Fire}, 2.0},
    {{MoveType::Water, MoveType::Water}, 0.5},
    {{MoveType::Water, MoveType::Grass}, 0.5},
    {{MoveType::Water, MoveType::Ground}, 2.0},
    {{MoveType::Water, MoveType::Rock}, 2.0},
    {{MoveType::Water, MoveType::Dragon}, 0.5},
    {{MoveType::Electric, MoveType::Water}, 2.0},
    {{MoveType::Electric, MoveType::Electric}, 0.5},
    {{MoveType::Electric, MoveType::Grass}, 0.5},
    {{MoveType::Electric, MoveType::Ground}, 0.0},
    {{MoveType::Electric, MoveType::Flying}, 2.0},
    {{MoveType::Electric, MoveType::Dragon}, 0.5},
    {{MoveType::Grass, MoveType::Fire}, 0.5},
    {{MoveType::Grass, MoveType::Water}, 2.0},
    {{MoveType::Grass, MoveType::Grass}, 0.5},
    {{MoveType::Grass, MoveType::Poison}, 0.5},
    {{MoveType::Grass, MoveType::Ground}, 2.0},
    {{MoveType::Grass, MoveType::Flying}, 0.5},
    {{MoveType::Grass, MoveType::Bug}, 0.5},
    {{MoveType::Grass, MoveType::Rock}, 2.0},
    {{MoveType::Grass, MoveType::Dragon}, 0.5},
    {{MoveType::Ice, MoveType::Water}, 0.5},
    {{MoveType::Ice, MoveType::Grass}, 2.0},
    {{MoveType::Ice, MoveType::Ice}, 0.5},
    {{MoveType::Ice, MoveType::Ground}, 2.0},
    {{MoveType::Ice, MoveType::Flying}, 2.0},
    {{MoveType::Ice, MoveType::Dragon}, 2.0},
    {{MoveType::Fighting, MoveType::Normal}, 2.0},
    {{MoveType::Fighting, MoveType::Ice}, 2.0},
    {{MoveType::Fighting, MoveType::Poison}, 0.5},
    {{MoveType::Fighting, MoveType::Flying}, 0.5},
    {{MoveType::Fighting, MoveType::Psychic}, 0.5},
    {{MoveType::Fighting, MoveType::Bug}, 0.5},
    {{MoveType::Fighting, MoveType::Rock}, 2.0},
    {{MoveType::Fighting, MoveType::Ghost}, 0.0},
    {{MoveType::Poison, MoveType::Grass}, 2.0},
    {{MoveType::Poison, MoveType::Poison}, 0.5},
    {{MoveType::Poison, MoveType::Ground}, 0.5},
    {{MoveType::Poison, MoveType::Bug}, 2.0},
    {{MoveType::Poison, MoveType::Rock}, 0.5},
    {{MoveType::Poison, MoveType::Ghost}, 0.5},
    {{MoveType::Ground, MoveType::Fire}, 2.0},
    {{MoveType::Ground, MoveType::Electric}, 2.0},
    {{MoveType::Ground, MoveType::Grass}, 0.5},
    {{MoveType::Ground, MoveType::Poison}, 2.0},
    {{MoveType::Ground, MoveType::Flying}, 0.0},
    {{MoveType::Ground, MoveType::Bug}, 0.5},
    {{MoveType::Ground, MoveType::Rock}, 2.0},
    {{MoveType::Flying, MoveType::Electric}, 0.5},
    {{MoveType::Flying, MoveType::Grass}, 2.0},
    {{MoveType::Flying, MoveType::Fighting}, 2.0},
    {{MoveType::Flying, MoveType::Bug}, 2.0},
    {{MoveType::Flying, MoveType::Rock}, 0.5},
    {{MoveType::Psychic, MoveType::Fighting}, 2.0},
    {{MoveType::Psychic, MoveType::Poison}, 2.0},
    {{MoveType::Psychic, MoveType::Psychic}, 0.5},
    {{MoveType::Bug, MoveType::Fire}, 0.5},
    {{MoveType::Bug, MoveType::Grass}, 2.0},
    {{MoveType::Bug, MoveType::Fighting}, 0.5},
    {{MoveType::Bug, MoveType::Poison}, 2.0},
    {{MoveType::Bug, MoveType::Flying}, 0.5},
    {{MoveType::Bug, MoveType::Psychic}, 2.0},
    {{MoveType::Bug, MoveType::Ghost}, 0.5},
    {{MoveType::Rock, MoveType::Fire}, 2.0},
    {{MoveType::Rock, MoveType::Ice}, 2.0},
    {{MoveType::Rock, MoveType::Fighting}, 0.5},
    {{MoveType::Rock, MoveType::Ground}, 0.5},
    {{MoveType::Rock, MoveType::Flying}, 2.0},
    {{MoveType::Rock, MoveType::Bug}, 2.0},
    {{MoveType::Ghost, MoveType::Normal}, 0.0},
    {{MoveType::Ghost, MoveType::Psychic}, 0.0},
    {{MoveType::Ghost, MoveType::Ghost}, 2.0},
    {{MoveType::Dragon, MoveType::Dragon}, 2.0}
};
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