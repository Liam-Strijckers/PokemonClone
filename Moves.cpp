#include "Moves.h"

int Moves::GetCurrentPP() const {return m_currentPP;}

void Moves::DecrementCurrentPP() {m_currentPP--;}

std::ostream &operator<<(std::ostream &os, const Moves &move){
    os  << "\n\tMove: "<< move.data.name 
        << "\n\tName: " << move.data.name 
        << "\n\tType:" << move.data.type 
        << "\n\tPower: " << move.data.power 
        << "\n\tAccuracy: " << move.data.accuracy 
        << "\n\tcritcalChance: " << move.data.critcalChance 
        << "\n\tCurrent PP: " << move.GetCurrentPP() 
        << "\n\tTotal PP: " << move.data.totalPP;
    return os;
}