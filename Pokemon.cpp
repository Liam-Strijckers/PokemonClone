
#include "pokemon.h"

using namespace std;


int Pokemon::GetCurrentExp() const {return m_currentExp;}
const std::array<Moves, NUM_MOVES> &Pokemon::GetMoves() const {
    return m_moves;
}

void Pokemon::IncrementCurrentExp(int expGain) { m_currentExp += expGain;}

bool Pokemon::LearnMove(const MovesData &moves_data){
    for(int i = 0; i< NUM_MOVES; i++){
        if(m_moves.at(i) == Moves{}){//need to implement overload operator?
            m_moves.at(i) = Moves{moves_data};//need to implement overload operator?
            return true;
        }
        if(moves_data.name == m_moves.at(i).data.name){
            return false;
        }
    }
    return true;
}

std::ostream &operator<<(std::ostream &os, const Pokemon &pokemon){
    os  << "Pokemon: " << pokemon.data.name 
        << "\t\nNickname: " << pokemon.data.nickname 
        << "\t\nID: " << pokemon.data.idNumber 
        << "\t\nPrimary Type: " << pokemon.data.primaryType
        << "\t\nSecondary Type: " << pokemon.data.secondaryType 
        << "\t\nLevel: " << pokemon.data.level << "\t\nHP: " << pokemon.data.hp 
        << "\t\nAttack: " << pokemon.data.attack 
        << "\t\nDefense: " << pokemon.data.defense 
        << "\t\nSpecial Attack: " << pokemon.data.spAttack 
        << "\t\nSpecial Defense: " << pokemon.data.spDefense 
        << "\t\nSpeed: " << pokemon.data.speed
        << "\t\nCurrent Experience: " << pokemon.GetCurrentExp() 
        << "\t\nExperience until Next Level: " << pokemon.data.ExpNextLevel - pokemon.GetCurrentExp();
    return os;
}