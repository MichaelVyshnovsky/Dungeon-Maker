#ifndef ROOM_H
#define ROOM_H

#include <string>
#include "rooms/Room.h"
#include "walls/Wall.h"
#include <memory>

class Room {
public:
    Room(std::shared_ptr<Wall> north,
         std::shared_ptr<Wall> east,
         std::shared_ptr<Wall> south,
         std::shared_ptr<Wall> west);
    virtual ~Room();

    std::shared_ptr<Wall> getWall(const std::string& direction) const;
    virtual std::string getType() const;

    virtual std::unique_ptr<Room> cloneWithWalls(std::shared_ptr<Wall> north,
                                  std::shared_ptr<Wall> east,
                                  std::shared_ptr<Wall> south,
                                  std::shared_ptr<Wall> west) const = 0;

protected:
    std::shared_ptr<Wall> walls[4]; // 0-North, 1-East, 2-South, 3-West
};

#endif // ROOM_H
