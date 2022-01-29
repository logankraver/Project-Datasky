#ifndef OBJECTGENERATOR_H
#define OBJECTGENERATOR_H

#include <tuple>
#include <map>

#include "tree.h"

class objectGenerator {
    public:
        std::map<std::tuple<int, int, int, int>, tree> treeMap;

        objectGenerator() { };
        
        void generate(std::tuple<int, int> coordinate);

        void render();

    private:
        void generateTrees(std::tuple<int, int> coordinates);
};

#endif