#ifndef CRACKEDWALL_H
#define CRACKEDWALL_H

#include "Wall.h"

class CrackedWall : public Wall {
public:
    CrackedWall(bool isBreakable);
    std::string getDescription() const override;
    bool isPassable() const override;

    void breakWall();

private:
    bool breakable;
    bool broken;
};

#endif // CRACKEDWALL_H
