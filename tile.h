#ifndef TILE_H
#define TILE_H

enum tiletype {
    GRASS
};

class tile {
    public:
        //tile type
        enum tiletype type;

        //vertex + element vars
        unsigned int vertexArray;
        unsigned int vertexBuffer;
        unsigned int elementBuffer;

        //constructor
        tile(tiletype type);

        //render the tile
        void render();
};

#endif