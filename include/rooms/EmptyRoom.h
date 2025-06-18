#ifndef EMPTYROOM_H
#define EMPTYROOM_H

#include "rooms/Room.h"
#include <memory>

class EmptyRoom : public Room {
public:
    EmptyRoom(std::shared_ptr<Wall> north,
              std::shared_ptr<Wall> east,
              std::shared_ptr<Wall> south,
              std::shared_ptr<Wall> west);

    std::string getType() const override;

    std::unique_ptr<Room> cloneWithWalls(std::shared_ptr<Wall> north,
                                         std::shared_ptr<Wall> east,
                                         std::shared_ptr<Wall> south,
                                         std::shared_ptr<Wall> west) const override;
};

#endif // EMPTYROOM_H
