// Grid.hpp
#pragma once
#include <vector>
#include "wobs/Position.hpp"

class Grid {
    std::vector<std::vector<int>> cells;   // 0 = empty, 1 = wall, 2 = ball, 3+ = bot ID
    int w, h;
public:
    Grid(int width = 100, int height = 50);
    bool inBounds(const Position&) const;
    int  get(const Position&) const;
    void set(const Position&, int value);
    void clear();
};