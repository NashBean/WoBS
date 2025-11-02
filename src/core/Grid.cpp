#include "wobs/Grid.hpp"
#include <algorithm>

Grid::Grid(int w, int h) : width(w), height(h) {
    cells.assign(height, std::vector<int>(width, 0));
}

bool Grid::inBounds(const Position& p) const {
    return p.x >= 0 && p.y >= 0 && p.x < width && p.y < height;
}

int Grid::get(const Position& p) const {
    return inBounds(p) ? cells[p.y][p.x] : -1;
}

void Grid::set(const Position& p, int v) {
    if (inBounds(p)) cells[p.y][p.x] = v;
}

void Grid::clear() {
    for (auto& row : cells) std::fill(row.begin(), row.end(), 0);
}
