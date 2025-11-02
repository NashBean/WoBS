// src/include/wobs/Position.hpp
#pragma once
struct Position {
    int x, y;
    Position(int x = 0, int y = 0) : x(x), y(y) {}
    int manhattan(const Position& o) const { return abs(x-o.x) + abs(y-o.y); }
    bool operator==(const Position& o) const { return x==o.x && y==o.y; }
};