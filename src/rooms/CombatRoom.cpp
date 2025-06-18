#include "rooms/Room.h"
#include "walls/Wall.h"
#include "rooms/CombatRoom.h"

CombatRoom::CombatRoom(std::shared_ptr<Wall> north,
                     std::shared_ptr<Wall> east,
                     std::shared_ptr<Wall> south,
                     std::shared_ptr<Wall> west)
    : Room(north, east, south, west) {}

std::string CombatRoom::getType() const {
    return "Combat Room";
}

std::unique_ptr<Room> CombatRoom::cloneWithWalls(std::shared_ptr<Wall> north,
                                                 std::shared_ptr<Wall> east,
                                                 std::shared_ptr<Wall> south,
                                                 std::shared_ptr<Wall> west) const {
    return std::make_unique<CombatRoom>(north, east, south, west);
}
