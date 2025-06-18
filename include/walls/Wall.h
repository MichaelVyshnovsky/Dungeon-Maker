#ifndef WALL_H
#define WALL_H

#include <string>

class Wall {
public:
    Wall();
    virtual ~Wall();

    virtual std::string getDescription() const;
    virtual bool isPassable() const;

    void setMaterial(const std::string& mat);
    std::string getMaterial() const;

protected:
    std::string material;
};

#endif // WALL_H
