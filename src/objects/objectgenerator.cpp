#include "objectgenerator.h"

void objectGenerator::generate(player player)
{
    std::tuple<int, int> playerCoords = getPlayerCoord(player);
    generateTrees(playerCoords);

}

std::tuple<int, int> objectGenerator::getPlayerCoord(player player)
{
    std::tuple<int, int> playerCoords = player.getChunkCoordinate();
    return playerCoords;
}

void objectGenerator::generateTrees(std::tuple<int, int> coordinates)
{
    
}