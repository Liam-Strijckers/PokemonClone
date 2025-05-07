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



  //adding default copy constructor
  Pokemon(const Pokemon &other) = default;
  Pokemon &operator=(const Pokemon &other) = default;
  // adding default move constructor
  Pokemon(Pokemon &&other) = default;
  Pokemon &operator=(Pokemon &&other) = default;

  
  const std::array<Moves, NUM_MOVES> &GetMoves() const;
  Moves &GetMove(int index);//implement
  int GetCurrentExp() const;
  int GetCurrentHP() const;
  bool GetFaintedStatus() const;
  void IncrementCurrentExp(int expGain);
  void DecrementCurrentHP(int hpDecrement);
  bool LearnMove(const MovesData &moves_data);
  int Attack();
  
  const PokemonData data{};
  std::array<Moves, NUM_MOVES> moves{Moves{}, Moves{}, Moves{}, Moves{}};

  bool operator==(const Pokemon &rhs) const;


private:
  friend std::ostream &operator<<(std::ostream &os, const Pokemon &pokemon);

  

  int m_currentExp{};
  int m_currentHP{};
  bool m_fainted = false;
};

#endif