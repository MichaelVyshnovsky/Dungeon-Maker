#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <memory>
#include "Wall.h"

class Room {
public:
    Room(Wall* north, Wall* east, Wall* south, Wall* west);
    virtual ~Room();

    Wall* getWall(const std::string& direction) const;

    // New virtual method to identify room type
    virtual std::string getType() const;

protected:
    Wall* walls[4]; // Order: 0-North, 1-East, 2-South, 3-West
};

#endif // ROOM_H
