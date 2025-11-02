#pragma once
#include "wobs/Position.hpp"
#include <cmath>

struct Ball {
    Position pos;      // grid cell
    float vx = 0, vy = 0;  // velocity (sub-cell)

    Ball(Position start) : pos(start) {}

    void tick(class Grid& g, float dt) {
        // Apply velocity
        pos.x += static_cast<int>(std::round(vx * dt));
        pos.y += static_cast<int>(std::round(vy * dt));

        // Wall bounce
        if (!g.inBounds(pos) || g.get(pos) == 1) {  // wall or out
            if (!g.inBounds(Position(pos.x-1, pos.y)) || g.get(Position(pos.x-1, pos.y)) == 1) vx = std::abs(vx);
            if (!g.inBounds(Position(pos.x+1, pos.y)) || g.get(Position(pos.x+1, pos.y)) == 1) vx = -std::abs(vx);
            if (!g.inBounds(Position(pos.x, pos.y-1)) || g.get(Position(pos.x, pos.y-1)) == 1) vy = std::abs(vy);
            if (!g.inBounds(Position(pos.x, pos.y+1)) || g.get(Position(pos.x, pos.y+1)) == 1) vy = -std::abs(vy);
            // Snap back into bounds
            pos.x = std::max(0, std::min(g.w()-1, pos.x));
            pos.y = std::max(0, std::min(g.h()-1, pos.y));
        }

        // Friction
        vx *= 0.95f;
        vy *= 0.95f;
        if (std::abs(vx) < 0.1f) vx = 0;
        if (std::abs(vy) < 0.1f) vy = 0;
    }

    void kick(float dirX, float dirY, float power = 80.0f) {
        vx += dirX * power;
        vy += dirY * power;
    }
};
