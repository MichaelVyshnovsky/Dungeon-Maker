#ifndef AIRWALL_H
#define AIRWALL_H

#include "Wall.h"

class AirWall : public Wall {
public:
    AirWall();
    std::string getDescription() const override;
    bool isPassable() const override;
};

#endif // AIRWALL_H
