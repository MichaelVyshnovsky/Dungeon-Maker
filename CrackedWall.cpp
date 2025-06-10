#include "CrackedWall.h"

CrackedWall::CrackedWall(bool isBreakable)
    : breakable(isBreakable), broken(false) {
    material = "old bricks";
}

std::string CrackedWall::getDescription() const {
    if (broken)
        return "A broken wall with a passage.";
    else if (breakable)
        return "A cracked wall that looks breakable.";
    else
        return "A cracked wall, but it's too sturdy.";
}

bool CrackedWall::isPassable() const {
    return broken;
}

void CrackedWall::breakWall() {
    if (breakable)
        broken = true;
}
