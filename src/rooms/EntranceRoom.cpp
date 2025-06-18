#include "rooms/Room.h"
#include "walls/Wall.h"
#include "rooms/EntranceRoom.h"

EntranceRoom::EntranceRoom(std::shared_ptr<Wall> north,
                     std::shared_ptr<Wall> east,
                     std::shared_ptr<Wall> south,
                     std::shared_ptr<Wall> west)
    : Room(north, east, south, west) {}

std::string EntranceRoom::getType() const {
    return "Entrance Room";
}

std::unique_ptr<Room> EntranceRoom::cloneWithWalls(std::shared_ptr<Wall> north,
                                                 std::shared_ptr<Wall> east,
                                                 std::shared_ptr<Wall> south,
                                                 std::shared_ptr<Wall> west) const {
    return std::make_unique<EntranceRoom>(north, east, south, west);
}
