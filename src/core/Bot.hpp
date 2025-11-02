// Bot.hpp

#pragma once
#include "wobs/Position.hpp"
#include "wobs/Grid.hpp"
#include <vector>

struct BotStats {
    int armor = 20, battery = 100, speed = 40, kick = 20, headbutt = 10;
};

class Bot {
    int id;
    Position pos;
    BotStats stats;
    std::vector<int> priority;   // AI priority list (0=ball,1=goal,2=enemy,…)
public:
    Bot(int id, Position start);
    void tick(const Grid& g);    // AI + physics in one call
    const Position& position() const { return pos; }
};