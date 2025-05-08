#ifndef _MOVE_H_
#define _MOVE_H_

#include <iostream>
#include <string>

#include "MoveInteraction.h"

static constexpr int NUM_MOVES{4};

struct MovesData {
  std::string name{};
  MoveType type{};
  int power{};
  int accuracy{};
  int critcalChance{};
  int totalPP{};
};

class Moves {

public:
  Moves() = default;
  Moves(const MovesData &moves_data)
      : data{moves_data}, m_currentPP{moves_data.totalPP} {};

  int GetCurrentPP() const;
  void DecrementCurrentPP();
  bool operator==(const Moves &rhs) const;

  MovesData data;

private:
  friend std::ostream &operator<<(std::ostream &os, const Moves &move);

  int m_currentPP{};
};

#endif