#pragma once
#include <vector>
#include "wobs/Position.hpp"

class Grid {
    std::vector<std::vector<int>> cells;
    int width, height;
    Position ball_pos = Position(-1,-1);
public:
    Grid(int w = 100, int h = 50);
    bool inBounds(const Position& p) const;
    int  get(const Position& p) const;
    void set(const Position& p, int v);
    void clear();
    int  w() const { return width; }
    int  h() const { return height; }
    Position ballPos() const { return ball_pos; }
    void setBallPos(const Position& p) { ball_pos = p; }
};
