#ifndef _POKEMON_H_
#define _POKEMON_H_

#include <iostream>
#include <string>
#include <vector>

#include "Moves.h"

class Pokemon {
  friend std::ostream &operator<<(std::ostream &os, const Pokemon &pokemon);

private:
  std::string name;
  std::string nickname;
  std::string primaryType;
  std::string secondaryType;
  int IDNumber;
  int HP;
  int level;
  int attack;
  int defense;
  int spAttack;
  int spDefense;
  int speed;
  int ExpNextLevel;
  int currentExp;
  std::vector<Moves> moves;

public:
  Pokemon(int IDNumber = 0, std::string name = "EmptyPokemon",
          std::string nickname = "EmptyPokemon",
          std::string primaryType = "EmptyType",
          std::string secondaryType = "EmptyType", int HP = 0, int level = 0,
          int attack = 0, int defense = 0, int spAttack = 0, int spDefense = 0,
          int speed = 0, int ExpNextLevel = 0,
          std::vector<Moves> moves = {Moves{}, Moves{}, Moves{},
                                      Moves{}}); // default

  std::string get_name() const;
  std::string get_nickname() const;
  std::string get_primaryType() const;
  std::string get_secondaryType() const;
  int get_IDNumber() const;
  int get_HP() const;
  int get_level() const;
  int get_attack() const;
  int get_defense() const;
  int get_spAttack() const;
  int get_spDefense() const;
  int get_speed() const;
  int get_ExpNextLevel() const;
  int get_currentExp() const;
  std::vector<Moves> get_moves() const; // return by reference?

  void set_name(std::string name);
  void set_nickname(std::string nickname);
  void set_primaryType(std::string type);
  void set_secondaryType(std::string type);
  void set_IDNumber(int IDNumber);
  void set_HP(int HP);
  void set_level(int level);
  void set_attack(int attack);
  void set_defense(int defense);
  void set_spAttack(int spAttack);
  void set_spDefense(int spDefense);
  void set_speed(int speed);
  void set_ExpNextLevel(int ExpNextLevel);
  void set_currentExp(int currentExp);

  bool learnMove(std::string name, std::string type, int power, int accuracy,
                 int critcalChance, int totalPP);
};

#endif