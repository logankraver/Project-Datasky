#ifndef TREE_H
#define TREE_H

class tree {
    public:
        //vertex + element vars
        unsigned int vertexArray;
        unsigned int vertexBuffer;
        unsigned int elementBuffer;

        //constructor
        tree();

        //render
        void render();
};

#endif