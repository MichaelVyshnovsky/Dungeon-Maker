#include "rooms/Room.h"
#include "walls/Wall.h"
#include <stdexcept>

Room::Room(std::shared_ptr<Wall> north,
           std::shared_ptr<Wall> east,
           std::shared_ptr<Wall> south,
           std::shared_ptr<Wall> west) {
    walls[0] = north;
    walls[1] = east;
    walls[2] = south;
    walls[3] = west;
}

Room::~Room() {}

std::shared_ptr<Wall> Room::getWall(const std::string& direction) const {
    if (direction == "north") return walls[0];
    if (direction == "east")  return walls[1];
    if (direction == "south") return walls[2];
    if (direction == "west")  return walls[3];
    throw std::invalid_argument("Invalid direction");
}

std::string Room::getType() const {
    return "Generic Room";
}
