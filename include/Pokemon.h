#ifndef _POKEMON_H_
#define _POKEMON_H_

#include <array>
#include <iostream>
#include <string>

#include "MoveInteraction.h"
#include "Moves.h"

struct PokemonData {
  std::string name{};
  std::string nickname{};
  enum MoveType primaryType{};
  enum MoveType secondaryType{};
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
  // Pokemon() = delete;
  Pokemon() = default;
  Pokemon(const PokemonData &pokemon_data) : data{pokemon_data} {};

  const std::array<Moves, NUM_MOVES> &GetMoves() const;
  int GetCurrentExp() const;
  int GetCurrentHP() const;
  bool GetFaintedStatus() const;
  void IncrementCurrentExp(int expGain);
  void DecrementCurrentHP(int hpDecrement);
  bool LearnMove(const MovesData &moves_data);
  int Attack();
  
  const PokemonData data{};

  bool operator==(const Pokemon &rhs) const;

private:
  friend std::ostream &operator<<(std::ostream &os, const Pokemon &pokemon);

  std::array<Moves, NUM_MOVES> m_moves{Moves{}, Moves{}, Moves{}, Moves{}};
  int m_currentExp{};
  int m_currentHP{};
  bool m_fainted = false;
};

#endif