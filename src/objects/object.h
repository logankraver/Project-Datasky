#ifndef OBJECT_H
#define OBJECT_H

class object{
    public:
        //object texture coordinates (8 floats to represent x,y for each corner)
        float texturecoords[8];

        //setter
        void setTexturecoords(float value[8]);

        //vertex + element vars
        unsigned int vertexArray;
        unsigned int vertexBuffer;
        unsigned int elementBuffer;

        //constructor
        object() { };

        //render
        void initializeRenderData();
        void render();
};

#endif