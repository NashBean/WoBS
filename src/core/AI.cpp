// AI.cpp

int Bot::evaluateTarget(const Position& target, const Grid& g) const {
    int score = 1000 / (1 + pos.manhattan(target));   // closer = better
    // priority list modifies score
    for (size_t i=0; i<priority.size(); ++i) {
        if (/*target type matches priority[i]*/) score += 100 * (priority.size()-i);
    }
    return score;
}