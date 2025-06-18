#include <walls/Wall.h>
#include "walls/AirWall.h"

AirWall::AirWall() {
    material = "none";
}

std::string AirWall::getDescription() const {
    return "An open space. Nothing blocks the way.";
}

bool AirWall::isPassable() const {
    return true;
}
