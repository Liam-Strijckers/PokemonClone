#include "Moves.h"

int Moves::GetCurrentPP() const { return m_currentPP; }

void Moves::DecrementCurrentPP() { m_currentPP--; }

bool Moves::operator==(const Moves &rhs) const{
  if(
    (data.name == rhs.data.name) &&
    (data.type == rhs.data.type) &&
    (data.power == rhs.data.power) &&
    (data.accuracy == rhs.data.accuracy) &&
    (data.critcalChance == rhs.data.critcalChance) &&
    (data.totalPP == rhs.data.totalPP)
  ){
    return true;
}
return false;
}

std::ostream &operator<<(std::ostream &os, const Moves &move) {
  os << "\n\tMove: " << move.data.name                   //
     << "\n\tName: " << move.data.name                   //
     << "\n\tType:" << move.data.type                    //
     << "\n\tPower: " << move.data.power                 //
     << "\n\tAccuracy: " << move.data.accuracy           //
     << "\n\tcritcalChance: " << move.data.critcalChance //
     << "\n\tCurrent PP: " << move.GetCurrentPP()        //
     << "\n\tTotal PP: " << move.data.totalPP;           //
  return os;
}