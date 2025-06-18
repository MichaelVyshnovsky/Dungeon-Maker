#ifndef ENTRANCEROOM_H
#define ENTRANCEROOM_H

#include "rooms/Room.h"
#include "walls/Wall.h"
#include <memory>

class EntranceRoom : public Room {
public:
    EntranceRoom(std::shared_ptr<Wall> north,
              std::shared_ptr<Wall> east,
              std::shared_ptr<Wall> south,
              std::shared_ptr<Wall> west);
              
    std::string getType() const override;

    std::unique_ptr<Room> cloneWithWalls(std::shared_ptr<Wall> north,
                                     std::shared_ptr<Wall> east,
                                     std::shared_ptr<Wall> south,
                                     std::shared_ptr<Wall> west) const override;
};

#endif // ENTRANCEROOM_H
