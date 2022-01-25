#include "chunk.h"

#include <iostream>
#include <iterator>

chunk::chunk(biome chunkID)
{
    this->biomeID = chunkID;

    if (this->biomeID == PLAINS)
    {
        while (tilemap.size() < 64)
        {
            tilemap.emplace_back(tile(GRASS));
        }
    }

    
}


void chunk::render(shader shader, glm::mat4 offset)
{
    for (std::vector<tile>::iterator it = tilemap.begin(); it != tilemap.end(); ++it)
    {
        //find chunk index
        unsigned int index = it - tilemap.begin();
        
        //translation matrix
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.05*(index%8), 0.05*(index/8), 0.0f));
        model = offset * model;
        shader.setMat4("model", model);
        
        //render
        (*it).render();
    }
}