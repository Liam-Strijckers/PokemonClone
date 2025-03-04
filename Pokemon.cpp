#include <algorithm>
#include <vector>
#include "Pokemon.h"

using namespace std;


Pokemon::Pokemon(int IDNumber, std::string name, std::string nickname, std::string primaryType, std::string secondaryType, int HP, int level,
    int attack, int defense, int spAttack, int spDefense, int speed, int ExpNextLevel, std::vector<Moves> moves)
    : IDNumber{IDNumber}, name{name}, nickname{nickname}, primaryType{primaryType}, secondaryType{secondaryType}, HP{HP}, level{level}, attack{attack},
        defense{defense}, spAttack{spAttack}, spDefense{spDefense}, speed{speed}, ExpNextLevel{ExpNextLevel}, moves{moves} {
            currentExp = 0;
        }

std::string Pokemon::get_name() const{
    return name;
}
std::string Pokemon::get_nickname() const{
    return nickname;
}
std::string Pokemon::get_primaryType() const{
    return primaryType;
}
std::string Pokemon::get_secondaryType() const{
    return secondaryType;
}
int Pokemon::get_IDNumber() const{
    return IDNumber;
}
int Pokemon::get_HP() const{
    return HP;
}
int Pokemon::get_level() const{
    return level;
}
int Pokemon::get_attack() const{
    return attack;
}
int Pokemon::get_defense() const{
    return defense;
}
int Pokemon::get_spAttack() const{
    return spAttack;
}
int Pokemon::get_spDefense() const{
    return spDefense;
}
int Pokemon::get_speed() const{
    return speed;
}
int Pokemon::get_ExpNextLevel() const{
    return ExpNextLevel;
}
int Pokemon::get_currentExp() const{
    return currentExp;
}
std::vector<Moves> Pokemon::get_moves() const{
    return moves;
}

void Pokemon::set_name(std::string name){
    this->name = name;
}
void Pokemon::set_nickname(std::string nickname){
    this->nickname = nickname;
}
void Pokemon::set_primaryType(std::string type){
    this->primaryType = primaryType;
}
void Pokemon::set_secondaryType(std::string type){
    this->secondaryType = secondaryType;
}
void Pokemon::set_IDNumber(int IDNumber){
    this->IDNumber = IDNumber;
}
void Pokemon::set_HP(int HP){
    this->HP = HP;
}
void Pokemon::set_level(int level){
    this->level = level;
}
void Pokemon::set_attack(int attack){
    this->attack = attack;
}
void Pokemon::set_defense(int defense){
    this->defense = defense;
}
void Pokemon::set_spAttack(int spAttack){
    this->spAttack = spAttack;
}
void Pokemon::set_spDefense(int spDefense){
    this->spDefense = spDefense;
}
void Pokemon::set_speed(int speed){
    this->speed = speed;
}
void Pokemon::set_ExpNextLevel(int ExpNextLevel){
    this->ExpNextLevel = ExpNextLevel;
}
void Pokemon::set_currentExp(int currentExp){
    this->currentExp = currentExp;
}

bool Pokemon::learnMove(std::string name, std::string type, int power, int accuracy, int critcalChance, int totalPP){
    int i {0}; //not a fan, talk to zach about have a built in way to replace only the first instance of "EmptyMove"
    for(const Moves &move:moves){
        if(move.get_name() == "EmptyMove"){
            moves.at(i) = Moves{name, type, power, accuracy, critcalChance, totalPP};
            return true;
        }
        if(name == move.get_name()){
            return false;
        }
        i++;
    }
    moves.push_back(Moves{name, type, power, accuracy, critcalChance, totalPP});
    return true;
}

std::ostream &operator<<(std::ostream &os, const Pokemon &pokemon){
    os << "Pokemon: " << pokemon.name << "\t\nNickname: " << pokemon.nickname << "\t\nID: " << pokemon.IDNumber << "\t\nPrimary Type: " << pokemon.primaryType
        << "\t\nSecondary Type: " << pokemon.secondaryType << "\t\nLevel: " << pokemon.level << "\t\nHP: " << pokemon.HP << "\t\nAttack: " << pokemon.attack 
        << "\t\nDefense: " << pokemon.defense << "\t\nSpecial Attack: " << pokemon.spAttack << "\t\nSpecial Defense: " << pokemon.spDefense << "\t\nSpeed: " << pokemon.speed
        << "\t\nCurrent Experience: " << pokemon.currentExp << "\t\nExperience until Next Level: " << pokemon.ExpNextLevel - pokemon.currentExp;
    return os;
}