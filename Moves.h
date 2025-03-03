#ifndef _MOVE_H_
#define _MOVE_H_
#include <iostream>
#include <string>

class Moves{
    friend std::ostream &operator<<(std::ostream &os, const Moves &move);
private:
    std::string name;
    std::string type;
    int power;
    int accuracy;
    int critcalChance;
    int currentPP;
    int totalPP;
public:
    Moves(std::string name = "EmptyMove", std::string type = "Not a Type", int power = 0, int accuracy = 0, int critcalChance = 0, int totalPP = 0); //default

    std::string get_name() const;
    std::string get_type() const;
    int get_power() const;
    int get_accuracy() const;
    int get_critcalChance() const;
    int get_currentPP() const;
    int get_totalPP() const;

    void set_name(std::string name);
    void set_type(std::string type);
    void set_power(int power);
    void set_accuracy(int accuracy);
    void set_critcalChance(int critcalChance);
    void set_currentPP(int currentPP);
    void set_totalPP(int totalPP);

    void decrementCurrentPP();


};
#endif