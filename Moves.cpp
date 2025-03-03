#include "Moves.h"

Moves::Moves(std::string name, std::string type, int power, int accuracy, int critcalChance, int totalPP)
    :name{name}, type{type}, power{power}, accuracy{accuracy}, critcalChance{critcalChance}, totalPP{totalPP} {
        currentPP = totalPP;
}

std::string Moves::get_name() const{//do this in the .h file?
    return name;
}
std::string Moves::get_type() const{
    return type;
}
int Moves::get_power() const{
    return power;
}
int Moves::get_accuracy() const{
    return accuracy;
}
int Moves::get_critcalChance() const{
    return critcalChance;
}
int Moves::get_currentPP() const{
    return currentPP;
}
int Moves::get_totalPP() const{
    return totalPP;
}

void Moves::set_name(std::string name){//do this in the .h file?
    this->name = name;
}
void Moves::set_type(std::string type){
    this->type = type;
}
void Moves::set_power(int power){
    this->power = power;
}
void Moves::set_accuracy(int accuracy){
    this->accuracy = accuracy;
}
void Moves::set_critcalChance(int critcalChance){
    this->critcalChance = critcalChance;
}
void Moves::set_currentPP(int currentPP){
    this->currentPP = currentPP;
}
void Moves::set_totalPP(int totalPP){
    this->totalPP = totalPP;
}



void Moves::decrementCurrentPP(){//do this in the .h file?
    this->currentPP--;
}

std::ostream &operator<<(std::ostream &os, const Moves &move){
    os << "Move: "<< move.name << "\n\tName: " << move.name << "\n\tType:" << move.type << "\n\tPower: " << move.power << "\n\tAccuracy: " << move.accuracy 
        << "\n\tcritcalChance: " << move.critcalChance << "\n\tCurrent PP: " << move.currentPP << "\n\tTotal PP: " << move.totalPP;
    return os;
}