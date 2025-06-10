#ifndef DUNGEON_H
#define DUNGEON_H

#include <vector>
#include <memory>
#include <utility>
#include "Room.h"

class Dungeon {
public:
    Dungeon(int width, int height);
    ~Dungeon() = default; // No need for manual cleanup

    void generate();
    void printDungeonMap() const;

private:
    int width;
    int height;

    std::vector<std::vector<std::shared_ptr<Room>>> grid;
    std::pair<int, int> entrancePos;
    std::pair<int, int> exitPos;

    void placeEntranceAndExit();
    void generatePath();
    bool isBorder(int x, int y) const;
};

#endif // DUNGEON_H
