#include "object.h"

#include <glad/glad.h>

void object::initializeRenderData()
{
    //render info
    float vertices[] = {
        //pos                 //texture
        -0.05f, -0.05f, 0.0f, texturecoords[0], texturecoords[1], //bottom left
         0.05f, -0.05f, 0.0f, texturecoords[2], texturecoords[3], //bottom right
        -0.05f,  0.05f, 0.0f, texturecoords[4], texturecoords[5], //top left
         0.05f,  0.05f, 0.0f, texturecoords[6], texturecoords[7]  //top right
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

void object::render()
{
    glBindVertexArray(vertexArray);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void object::setTexturecoords(float value[8])
{
    for (int i = 0; i != 8; i++)
    {
        texturecoords[i] = value[i];
    }
}