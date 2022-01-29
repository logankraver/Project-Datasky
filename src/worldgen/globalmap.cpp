#include "globalmap.h"

#include <iterator>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

//default values
const unsigned int initialChunks = 3;
const biome defaultBiome = PLAINS;

globalmap::globalmap() 
{
    generateInitialChunks();
}

void globalmap::render(shader shader, player playerchar)
{
    std::map<std::tuple <int, int>, chunk>::iterator it;
    std::tuple <int, int> playerCoord = playerchar.getChunkCoordinate();
    for (it = globe.begin(); it != globe.end(); it++)
    {
        //find chunk coordinate
        std::tuple<int, int> coordinate = it->first;
        //if (std::get<0>(playerCoord) - 3 <= std::get<0>(coordinate) <= std::get<0>(playerCoord) + 3 && std::get<1>(playerCoord) - 3 <= std::get<1>(coordinate) <= std::get<1>(playerCoord) + 3)
        if (std::get<0>(playerCoord) - 3 <= std::get<0>(coordinate) && std::get<0>(playerCoord) + 3 >= std::get<0>(coordinate) && std::get<1>(playerCoord) - 3 <= std::get<1>(coordinate) && std::get<1>(playerCoord) + 3 >= std::get<1>(coordinate))
        {
            //create translation matrix
            glm::vec3 translation = glm::vec3(0.4f*(std::get<0>(coordinate)), 0.4f*(std::get<1>(coordinate)), 0.0f);
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, translation);

            //render
            (it->second).render(shader, model);
        }
    }
    
}

void globalmap::passiveGeneration(player player)
{
    std::tuple <int, int> chunkCoordinate = player.getChunkCoordinate();
    
    std::map<std::tuple <int, int>, chunk>::iterator it;
    bool generateChunk[4] = {
        true, //pos X
        true, //neg X
        true, //pos Y
        true  //neg Y
    };

    for (it = globe.begin(); it != globe.end(); it++)
    {
        //pos X
        if (std::get<0>(chunkCoordinate) + 3 == std::get<0>(it->first) && std::get<1>(chunkCoordinate) == std::get<1>(it->first))
        {
            generateChunk[0] = false;
        }
        //neg X
        if (std::get<0>(chunkCoordinate) - 3 == std::get<0>(it->first) && std::get<1>(chunkCoordinate) == std::get<1>(it->first))
        {
            generateChunk[1] = false;
        }
        //pos Y
        if (std::get<0>(chunkCoordinate) == std::get<0>(it->first) && std::get<1>(chunkCoordinate) + 3 == std::get<1>(it->first))
        {
            generateChunk[2] = false;
        }
        //neg Y
        if (std::get<0>(chunkCoordinate) == std::get<0>(it->first) && std::get<1>(chunkCoordinate) - 3 == std::get<1>(it->first))
        {
            generateChunk[3] = false;
        }
    }

    if (generateChunk[0] == true)
    {
        generateChunks(EAST, chunkCoordinate);
    }
    if (generateChunk[1] == true)
    {
        generateChunks(WEST, chunkCoordinate);
    }
    if (generateChunk[2] == true)
    {
        generateChunks(NORTH, chunkCoordinate);
    }
    if (generateChunk[3] == true)
    {
        generateChunks(SOUTH, chunkCoordinate);
    }

}

void globalmap::generateInitialChunks()
{
    for (int x = -1 * initialChunks; x != initialChunks + 1; x++)
    {
        for (int y = -1 * initialChunks; y != initialChunks + 1; y++)
        {
            std::tuple<int, int> coordinate(x, y);
            globe.emplace(coordinate, chunk(defaultBiome));
        }
    }
}

void globalmap::generateChunks(directions d, std::tuple<int, int> coordinate)
{
    if (d == NORTH)
    {
        for (int i = 0; i != 3; i++)
        {
            for (int f = -3; f != 3; f++)
            {
                bool generate = true;
                std::tuple<int, int> newCoordinate(std::get<0>(coordinate) + f, std::get<1>(coordinate) + i);

                std::map<std::tuple <int, int>, chunk>::iterator it;
                for (it = globe.begin(); it != globe.end(); it++)
                {
                    if (std::get<0>(newCoordinate) == std::get<0>(it->first) && std::get<1>(newCoordinate) == std::get<1>(it->first))
                    {
                        generate = false;
                        break;
                    }
                }
                if (generate)
                {
                    globe.emplace(newCoordinate, chunk(defaultBiome));
                }
            }
        }
    }
    else if (d == SOUTH)
    {
        for (int i = -3; i != 0; i++)
        {
            for (int f = -3; f != 3; f++)
            {
                bool generate = true;
                std::tuple<int, int> newCoordinate(std::get<0>(coordinate) + f, std::get<1>(coordinate) + i);

                std::map<std::tuple <int, int>, chunk>::iterator it;
                for (it = globe.begin(); it != globe.end(); it++)
                {
                    if (std::get<0>(newCoordinate) == std::get<0>(it->first) && std::get<1>(newCoordinate) == std::get<1>(it->first))
                    {
                        generate = false;
                        break;
                    }
                }
                if (generate)
                {
                    globe.emplace(newCoordinate, chunk(defaultBiome));
                }
            }
        }
    }
    else if (d == WEST)
    {
        for (int f = -3; f != 0; f++)
        {
            for (int i = -3; i != 3; i++)
            {
                bool generate = true;
                std::tuple<int, int> newCoordinate(std::get<0>(coordinate) + f, std::get<1>(coordinate) + i);

                std::map<std::tuple <int, int>, chunk>::iterator it;
                for (it = globe.begin(); it != globe.end(); it++)
                {
                    if (std::get<0>(newCoordinate) == std::get<0>(it->first) && std::get<1>(newCoordinate) == std::get<1>(it->first))
                    {
                        generate = false;
                        break;
                    }
                }
                if (generate)
                {
                    globe.emplace(newCoordinate, chunk(defaultBiome));
                }
            }
        }
    }
    else if (d == EAST)
    {
        for (int f = 0; f != 3; f++)
        {
            for (int i = -3; i != 3; i++)
            {
                bool generate = true;
                std::tuple<int, int> newCoordinate(std::get<0>(coordinate) + f, std::get<1>(coordinate) + i);

                std::map<std::tuple <int, int>, chunk>::iterator it;
                for (it = globe.begin(); it != globe.end(); it++)
                {
                    if (std::get<0>(newCoordinate) == std::get<0>(it->first) && std::get<1>(newCoordinate) == std::get<1>(it->first))
                    {
                        generate = false;
                        break;
                    }
                }
                if (generate)
                {
                    globe.emplace(newCoordinate, chunk(defaultBiome));
                }
            }
        }
    }
}