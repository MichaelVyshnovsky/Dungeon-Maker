#ifndef PRIZEROOM_H
#define PRIZEROOM_H

#include "rooms/Room.h"
#include "walls/Wall.h"
#include <memory>

class PrizeRoom : public Room {
public:
    PrizeRoom(std::shared_ptr<Wall> north,
              std::shared_ptr<Wall> east,
              std::shared_ptr<Wall> south,
              std::shared_ptr<Wall> west);

    std::string getType() const override;

    std::unique_ptr<Room> cloneWithWalls(std::shared_ptr<Wall> north,
                                         std::shared_ptr<Wall> east,
                                         std::shared_ptr<Wall> south,
                                         std::shared_ptr<Wall> west) const override;
};

#endif // PRIZEROOM_H
