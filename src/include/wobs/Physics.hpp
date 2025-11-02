#pragma once
#include <cmath>

struct Physics {
    float vx = 0, vy = 0;
    float rot = 0;        // radians, 0 = right
    float thrust = 0;     // 0-1
    float turn = 0;       // -1 to 1

    void update(float dt, float& x, float& y, float& r) {
        r += turn * 5.0f * dt;
        if (r > 6.28318f) r -= 6.28318f;
        if (r < 0) r += 6.28318f;

        vx += std::cos(r) * thrust * 60.0f * dt;
        vy += std::sin(r) * thrust * 60.0f * dt;

        x += vx * dt;
        y += vy * dt;

        vx *= 0.98f; vy *= 0.98f;
        if (std::abs(vx) < 0.01f) vx = 0;
        if (std::abs(vy) < 0.01f) vy = 0;
    }
};
