// Position.hpp

#pragma once
#include <cstdlib>               // <-- NEW
struct Position {
    int x = 0, y = 0;
    Position() = default;
    Position(int x_, int y_) : x(x_), y(y_) {}
    int manhattan(const Position& o) const { return std::abs(x-o.x) + std::abs(y-o.y); }
    bool operator==(const Position& o) const { return x==o.x && y==o.y; }
};