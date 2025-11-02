#pragma once
#include "wobs/Position.hpp"
#include "wobs/Physics.hpp"
#include <vector>

struct BotStats {
    int armor = 20, battery = 100, speed = 40, kick = 20, headbutt = 10;
};

class Bot {
    int id;
    Position pos;
    BotStats stats;
    std::vector<int> priority;
public:
    Physics phys;
public:
    Bot(int id_, Position start);
    void tick(class Grid& g, float dt, bool isPlayer = false);
    const Position& position() const { return pos; }
    int getId() const { return id; }
    void setPriority(const std::vector<int>& p) { priority = p; }
};
