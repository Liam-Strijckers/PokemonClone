#ifndef _POKEMON_H_
#define _POKEMON_H_

#include <array>
#include <iostream>
#include <string>

#include "Moves.h"

struct PokemonData {
  std::string name{};
  std::string nickname{};
  std::string primaryType{};
  std::string secondaryType{};
  int idNumber{};
  int hp{};
  int level{};
  int attack{};
  int defense{};
  int spAttack{};
  int spDefense{};
  int speed{};
  int expNextLevel{};
};

class Pokemon {
public:
  Pokemon() = delete;
  Pokemon(const PokemonData &pokemon_data) : data{pokemon_data} {};

  const std::array<Moves, NUM_MOVES> &GetMoves() const;
  int GetCurrentExp() const;
  void IncrementCurrentExp(int expGain);
  bool LearnMove(const MovesData &moves_data);

  const PokemonData data{};

private:
  friend std::ostream &operator<<(std::ostream &os, const Pokemon &pokemon);

  std::array<Moves, NUM_MOVES> m_moves{Moves{}, Moves{}, Moves{}, Moves{}};
  int m_currentExp{};
};

#endif