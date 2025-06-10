#include "Room.h"
#include <stdexcept>

Room::Room(Wall* north, Wall* east, Wall* south, Wall* west) {
    walls[0] = north;
    walls[1] = east;
    walls[2] = south;
    walls[3] = west;
}

Room::~Room() {}

Wall* Room::getWall(const std::string& direction) const {
    if (direction == "north") return walls[0];
    if (direction == "east")  return walls[1];
    if (direction == "south") return walls[2];
    if (direction == "west")  return walls[3];
    throw std::invalid_argument("Invalid direction");
}

std::string Room::getType() const {
    return "Generic Room";
}
