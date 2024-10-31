#include <iostream>
#include <string>
#include "deckmgmt.h"
#include <vector>

class Player {
    public:
    int balance;
    int points;
    std::vector<card>hand;
    Player(int b) : balance(b), points(0) {}
    
};