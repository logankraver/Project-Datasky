#include "tree.h"

#include <glad/glad.h>

tree::tree()
{
    float texturecoords[8] = {
        0.250f, 0.000f, //bottom left
        0.375f, 0.000f, //bottom right
        0.250f, 0.125f, //top left
        0.375f, 0.125f  //top right
    };

    setTexturecoords(texturecoords);
    initializeRenderData();
}
