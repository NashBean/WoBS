// Physics.cpp

#include "wobs/Position.hpp"
#include <cmath>

struct Vec2 { float x, y; };

Vec2 gravity = {0, 0};               // zero-G
Vec2 thrust(const Bot& b, const Grid& g) {
    // Simple thrust toward highest-priority target
    // …implement A* or potential fields later
    return {0,0};
}

void integrate(Bot& b, float dt) {
    Vec2 vel = {0,0};                // start from rest each tick
    vel.x += thrust(b, /*grid*/).x * b.stats.speed * dt;
    vel.y += thrust(b, /*grid*/).y * b.stats.speed * dt;
    b.pos.x = std::round(b.pos.x + vel.x);
    b.pos.y = std::round(b.pos.y + vel.y);
}