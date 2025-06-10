#include "CombatRoom.h"

CombatRoom::CombatRoom(Wall* north, Wall* east, Wall* south, Wall* west)
    : Room(north, east, south, west) {}

std::string CombatRoom::getType() const {
    return "Combat Room";
}
