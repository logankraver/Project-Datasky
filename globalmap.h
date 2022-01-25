#ifndef GLOBALMAP_H
#define GLOBALMAP_H

#include <map>
#include <tuple>

#include "shader.h"
#include "chunk.h"
#include "player.h"

enum directions{
    NORTH,
    SOUTH,
    WEST,
    EAST
};

class globalmap {
    public:
        //map data structure to hold the coordinate for each chunk
        std::map<std::tuple <int, int>, chunk> globe;

        //constructor
        globalmap();

        //render
        void render(shader shader, player playerchar);

        void passiveGeneration(player player);

    private:
        //helper functions
        void generateInitialChunks();

        void generateChunks(directions d, std::tuple<int, int> coordinate);
};

#endif