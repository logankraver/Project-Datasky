#include "tile.h"

#include <glad/glad.h>

tile::tile(tiletype type)
{
    this->type = type;

    if (this->type == GRASS)
    {
        float vertices[] = {
            //pos               //texture
            -0.05f, -0.05f, 0.0f,   0.0f,   0.0f,
             0.05f, -0.05f, 0.0f, 0.125f,   0.0f,
            -0.05f,  0.05f, 0.0f,   0.0f, 0.125f,
             0.05f,  0.05f, 0.0f, 0.125f, 0.125f
        };

        unsigned int indices[] = {
            0, 1, 2,
            1, 2, 3
        };

        //create vertex and element buffer and vertex array
        glGenBuffers(1, &vertexBuffer);
        glGenBuffers(1, &elementBuffer);
        glGenVertexArrays(1, &vertexArray);

        //bind vertex buffer
        glBindVertexArray(vertexArray);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        //bind element buffer
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        //vertex attributes
        //-----------------
        //position
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5*sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        //texture coords
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5*sizeof(float), (void*)(3*sizeof(float)));
        glEnableVertexAttribArray(1);
    }
}

void tile::render()
{
    glBindVertexArray(vertexArray);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}