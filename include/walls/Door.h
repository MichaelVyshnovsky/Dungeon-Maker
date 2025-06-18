#ifndef DOOR_H
#define DOOR_H

#include "walls/Wall.h"

class Door : public Wall {
public:
    Door(bool isOpen);
    std::string getDescription() const override;
    bool isPassable() const override;

protected:
    bool open;
};

#endif // DOOR_H
