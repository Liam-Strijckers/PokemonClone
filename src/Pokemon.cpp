#include "Pokemon.h"

int Pokemon::GetCurrentExp() const { return m_currentExp; }
const std::array<Moves, NUM_MOVES> &Pokemon::GetMoves() const {
  return m_moves;
}
void Pokemon::IncrementCurrentExp(int expGain) { m_currentExp += expGain; }

bool Pokemon::LearnMove(const MovesData &moves_data) {
  for (int i = 0; i < NUM_MOVES; i++) {
    if (m_moves.at(i) == Moves{}) {
      m_moves.at(i) = Moves{moves_data};
      return true;
    }

    if (moves_data.name == m_moves.at(i).data.name) {
      return false;
    }
  }
  return false;
}

std::ostream &operator<<(std::ostream &os, const Pokemon &pokemon) {
  os << "Pokemon: " << pokemon.name << "\t\nNickname: " << pokemon.nickname
     << "\t\nID: " << pokemon.IDNumber
     << "\t\nPrimary Type: " << pokemon.primaryType
     << "\t\nSecondary Type: " << pokemon.secondaryType
     << "\t\nLevel: " << pokemon.level << "\t\nHP: " << pokemon.HP
     << "\t\nAttack: " << pokemon.attack << "\t\nDefense: " << pokemon.defense
     << "\t\nSpecial Attack: " << pokemon.spAttack
     << "\t\nSpecial Defense: " << pokemon.spDefense
     << "\t\nSpeed: " << pokemon.speed
     << "\t\nCurrent Experience: " << pokemon.currentExp
     << "\t\nExperience until Next Level: "
     << pokemon.ExpNextLevel - pokemon.currentExp;
  return os;
}