#include "Pokemon.h"

int Pokemon::GetCurrentExp() const { return m_currentExp; }
int Pokemon::GetCurrentHP() const {return m_currentHP;}
const std::array<Moves, NUM_MOVES> &Pokemon::GetMoves() const {
  return m_moves;
}
void Pokemon::IncrementCurrentExp(int expGain) { m_currentExp += expGain; }
int Attack(){
  return 0;
}
void Pokemon::DecrementCurrentHP(int hpDecrement){ 
  if(hpDecrement > m_currentHP){
    m_currentHP = 0;
    m_fainted = true;
  }else{
    m_currentHP -= hpDecrement;
  }
}

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

bool Pokemon::operator==(const Pokemon &rhs) const{
  if(data.name == rhs.data.name){
    return true;
  }
  return false;
}

std::ostream &operator<<(std::ostream &os, const Pokemon &pokemon){
  os  << "Pokemon: " << pokemon.data.name 
      << "\t\nNickname: " << pokemon.data.nickname 
      << "\t\nID: " << pokemon.data.idNumber 
      << "\t\nPrimary Type: " << pokemon.data.primaryType
      << "\t\nSecondary Type: " << pokemon.data.secondaryType 
      << "\t\nLevel: " << pokemon.data.level 
      << "\t\nHP: " << pokemon.data.hp 
      << "\t\nCurrent HP: " << pokemon.GetCurrentHP()
      << "\t\nAttack: " << pokemon.data.attack 
      << "\t\nDefense: " << pokemon.data.defense 
      << "\t\nSpecial Attack: " << pokemon.data.spAttack 
      << "\t\nSpecial Defense: " << pokemon.data.spDefense 
      << "\t\nSpeed: " << pokemon.data.speed
      << "\t\nCurrent Experience: " << pokemon.GetCurrentExp() 
      << "\t\nExperience until Next Level: " << pokemon.data.expNextLevel - pokemon.GetCurrentExp();
  return os;
}