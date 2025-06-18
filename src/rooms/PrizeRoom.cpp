#include "rooms/Room.h"
#include "walls/Wall.h"
#include "rooms/PrizeRoom.h"

PrizeRoom::PrizeRoom(std::shared_ptr<Wall> north,
                     std::shared_ptr<Wall> east,
                     std::shared_ptr<Wall> south,
                     std::shared_ptr<Wall> west)
    : Room(north, east, south, west) {}

std::string PrizeRoom::getType() const {
    return "Prize Room";
}

std::unique_ptr<Room> PrizeRoom::cloneWithWalls(std::shared_ptr<Wall> north,
                                                std::shared_ptr<Wall> east,
                                                std::shared_ptr<Wall> south,
                                                std::shared_ptr<Wall> west) const {
    return std::make_unique<PrizeRoom>(north, east, south, west);
}
