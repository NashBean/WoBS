#include "wobs/Bot.hpp"
#include "wobs/Grid.hpp"
#include "wobs/Ball.hpp"
#include <SDL2/SDL.h>
#include <algorithm>
#include <cmath>
#include <iostream>  // for debug

extern Ball* game_ball;

Bot::Bot(int id_, Position start) : id(id_), pos(start) {}

void Bot::tick(Grid& g, float dt, bool isPlayer) {
std::cout << "dt = " << dt << std::endl;
std::cout << "dt = " << dt << std::endl;
std::cout << "dt = " << dt << std::endl;
std::cout << "dt = " << dt << std::endl;
std::cout << "dt = " << dt << std::endl;
    if (isPlayer) {
        const Uint8* k = SDL_GetKeyboardState(nullptr);
        phys.thrust = k[SDL_SCANCODE_W] ? 1.0f : 0.0f;
        phys.turn = (k[SDL_SCANCODE_A] ? -1.0f : 0.0f) + (k[SDL_SCANCODE_D] ? 1.0f : 0.0f);
    } else if (game_ball) {
        Position future = game_ball->pos;
        future.x += static_cast<int>(std::round(game_ball->vx * 1.5f));  // longer prediction
        future.y += static_cast<int>(std::round(game_ball->vy * 1.5f));
        if (!g.inBounds(future)) future = game_ball->pos;

        Position target = future;  // default to ball for movement
        int bestScore = -1;

        // Priority scan
        for (int y = 0; y < g.h(); ++y)
        for (int x = 0; x < g.w(); ++x) {
            Position p(x, y);
            int cell = g.get(p);
            if (cell == 0) continue;
            auto it = std::find(priority.begin(), priority.end(), cell);
            if (it == priority.end()) continue;
            int prioBonus = 1000 * (priority.size() - (it - priority.begin()));
            int score = prioBonus / (1 + pos.manhattan(p));
            if (score > bestScore) { bestScore = score; target = p; }
        }

        float dx = target.x - pos.x;
        float dy = target.y - pos.y;
        float dist = std::hypot(dx, dy);

        if (dist > 1.0f) {
            float angle = std::atan2(dy, dx);
            float diff = angle - phys.rot;
            while (diff > 3.14159f) diff -= 6.28318f;
            while (diff < -3.14159f) diff += 6.28318f;
            phys.turn = (diff > 1.0f ? 1.0f : (diff < -1.0f ? -1.0f : diff));
            phys.thrust = 1.0f;
        } else {
            phys.thrust = 0.5f;  // gentle hover if close
            phys.turn = 0.0f;
        }
    } else {
        phys.thrust = 0.5f;  // idle movement if no ball
        phys.turn = 0.5f;    // slow spin for life
    }

    float fx = pos.x, fy = pos.y;
    phys.update(dt, fx, fy, phys.rot);
    pos.x = static_cast<int>(std::round(fx));
    pos.y = static_cast<int>(std::round(fy));
    pos.x = std::max(0, std::min(g.w()-1, pos.x));
    pos.y = std::max(0, std::min(g.h()-1, pos.y));

    if (game_ball && pos == game_ball->pos) {
        game_ball->kick(std::cos(phys.rot), std::sin(phys.rot), 160.0f);
    }

    // Debug log
    std::cout << "Bot " << id << ": thrust=" << phys.thrust << ", turn=" << phys.turn << ", pos=(" << pos.x << "," << pos.y << ")" << std::endl;
}
