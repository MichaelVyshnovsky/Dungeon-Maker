#ifndef EXITROOM_H
#define EXITROOM_H

#include "Room.h"
#include <walls/Wall.h>

class ExitRoom : public Room {
public:
    ExitRoom(std::shared_ptr<Wall> north,
              std::shared_ptr<Wall> east,
              std::shared_ptr<Wall> south,
              std::shared_ptr<Wall> west);
              
    std::string getType() const override;

    std::unique_ptr<Room> cloneWithWalls(std::shared_ptr<Wall> north,
                                     std::shared_ptr<Wall> east,
                                     std::shared_ptr<Wall> south,
                                     std::shared_ptr<Wall> west) const override;
};

#endif // EXITROOM_H
