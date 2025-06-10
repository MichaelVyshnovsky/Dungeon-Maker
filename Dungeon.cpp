#include "Dungeon.h"
#include "EntranceRoom.h"
#include "ExitRoom.h"
#include "PuzzleRoom.h"
#include <iostream>
#include <random>
#include <ctime>

Dungeon::Dungeon(int w, int h) : width(w), height(h) {
    grid.resize(height, std::vector<std::shared_ptr<Room>>(width, nullptr));
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    generate();
}

bool Dungeon::isBorder(int x, int y) const {
    return x == 0 || y == 0 || x == width - 1 || y == height - 1;
}

void Dungeon::placeEntranceAndExit() {
    do {
        entrancePos = {rand() % width, rand() % height};
    } while (!isBorder(entrancePos.first, entrancePos.second));

    do {
        exitPos = {rand() % width, rand() % height};
    } while (!isBorder(exitPos.first, exitPos.second) || entrancePos == exitPos);

    grid[entrancePos.second][entrancePos.first] = std::make_shared<EntranceRoom>(nullptr, nullptr, nullptr, nullptr);
    grid[exitPos.second][exitPos.first] = std::make_shared<ExitRoom>(nullptr, nullptr, nullptr, nullptr);
}

void Dungeon::generatePath() {
    int x = entrancePos.first;
    int y = entrancePos.second;
    int targetX = exitPos.first;
    int targetY = exitPos.second;

    while (x != targetX || y != targetY) {
        if (!grid[y][x]) {
            grid[y][x] = std::make_shared<PuzzleRoom>(nullptr, nullptr, nullptr, nullptr);
        }

        int dx = targetX - x;
        int dy = targetY - y;

        if ((std::abs(dx) > std::abs(dy) && dx != 0) || dy == 0) {
            x += (dx > 0) ? 1 : -1;
        } else {
            y += (dy > 0) ? 1 : -1;
        }
    }

    if (!grid[y][x]) {
        grid[y][x] = std::make_shared<PuzzleRoom>(nullptr, nullptr, nullptr, nullptr);
    }
}

void Dungeon::generate() {
    placeEntranceAndExit();
    generatePath();
}

void Dungeon::printDungeonMap() const {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (entrancePos == std::make_pair(x, y)) {
                std::cout << "E ";
            } else if (exitPos == std::make_pair(x, y)) {
                std::cout << "X ";
            } else if (grid[y][x]) {
                std::cout << ". ";
            } else {
                std::cout << "# ";
            }
        }
        std::cout << "\n";
    }
}
