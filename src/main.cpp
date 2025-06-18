#include "Dungeon.h"
#include <iostream>

int main() {
    const int width = 10;
    const int height = 8;

    try {
        Dungeon dungeon(width, height);
        std::cout << "Generated Dungeon Map:\n";
        dungeon.printDungeonMap();
    } catch (const std::exception& e) {
        std::cerr << "Error creating dungeon: " << e.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
