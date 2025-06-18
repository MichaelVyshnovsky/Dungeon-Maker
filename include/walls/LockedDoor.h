#ifndef LOCKEDDOOR_H
#define LOCKEDDOOR_H

#include <memory>
#include "walls/Wall.h"
#include "walls/Door.h"
#include "Door.h"

class LockedDoor : public Door {
public:
    LockedDoor(bool isOpen, bool isLocked);

    std::string getDescription() const override;
    bool isPassable() const override;

    void unlock();
    void lock();
    bool isLocked() const;

private:
    bool locked;
};

#endif // LOCKEDDOOR_H
