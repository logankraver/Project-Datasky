#include "objectgenerator.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iterator>

#include <iostream>


void objectGenerator::generate(std::tuple<int, int> coordinate)
{
    generateTrees(coordinate);
}

void objectGenerator::generateTrees(std::tuple<int, int> coordinates)
{   
    int generatedTrees = 0;
    // 1/6 chance to generate a tree, max 6 trees generated
    for (int i = 0; i < 6; i++)
    {
        int r = rand() % 6 + 1;
        if (r == 6)
        {
            generatedTrees++;
        }
    }

    //generate each tree
    for (int i = 0; i != generatedTrees; i++)
    {
        int x = rand() % 16;
        int y = rand() % 16;
        std::tuple<int, int, int, int> newTreeCoord(std::get<0>(coordinates), std::get<1>(coordinates), x, y);
        treeMap.emplace(newTreeCoord, tree());
    }
}

void objectGenerator::render()
{
    
}