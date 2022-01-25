#ifndef OBJECTGENERATOR_H
#define OBJECTGENERATOR_H

#include <tuple>
#include <map>

#include "player.h"
#include "tree.h"

class objectGenerator {
    public:
        std::map< std::tuple<int, int, int, int>, tree> treeMap;

        objectGenerator() { };
        
        void generate(player player);

        void render();

    private:
        std::tuple<int, int> getPlayerCoord(player player); 

        void generateTrees(std::tuple<int, int> coordinates);
};

#endif