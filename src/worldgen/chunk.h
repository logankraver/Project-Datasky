#ifndef CHUNK_H
#define CHUNK_H

#include "../shaders/shader.h"
#include "tile.h"
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum biome {
    PLAINS
};

class chunk {
    public:
        //set of tiles 
        std::vector<tile> tilemap;

        //biome for the chunk
        enum biome biomeID;

        //constructor
        chunk(biome ID);

        //render tiles within chunk
        void render(shader shader, glm::mat4 offset);

};

#endif