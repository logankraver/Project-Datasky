#include "player.h"

#include <iostream>

player::player()
{
    playerPosX = 0;
    playerPosY = 0;

    float vertices[] = {
        //pos               //texture
        -0.025f, -0.05f, 0.0f, 0.125f * 1.25f, 0.000f, //bottom left
         0.025f, -0.05f, 0.0f, 0.125f * 1.75f, 0.000f, //bottom right
        -0.025f,  0.05f, 0.0f, 0.125f * 1.25f, 0.125f, //top left
         0.025f,  0.05f, 0.0f, 0.125f * 1.75f, 0.125f  //top right
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

void player::move(movementChoices choice, float velocity)
{
    if (choice == UP)
    {
        cameraPos = cameraPos + (glm::vec3(0.0f, 1.0f, 0.0f))*velocity;
        cameraTarget = cameraTarget + (glm::vec3(0.0f, 1.0f, 0.0f))*velocity;
        playerPosY = playerPosY + velocity;
    }
    if (choice == DOWN)
    {
        cameraPos = cameraPos + (glm::vec3(0.0f, -1.0f, 0.0f))*velocity;
        cameraTarget = cameraTarget + (glm::vec3(0.0f, -1.0f, 0.0f))*velocity;
        playerPosY = playerPosY - velocity;
    }
    if (choice == LEFT)
    {
        cameraPos = cameraPos + (glm::vec3(-1.0f, 0.0f, 0.0f))*velocity;
        cameraTarget = cameraTarget + (glm::vec3(-1.0f, 0.0f, 0.0f))*velocity;
        playerPosX = playerPosX - velocity;
    }
    if (choice == RIGHT)
    {
        cameraPos = cameraPos + (glm::vec3(1.0f, 0.0f, 0.0f))*velocity;
        cameraTarget = cameraTarget + (glm::vec3(1.0f, 0.0f, 0.0f))*velocity;
        playerPosX = playerPosX + velocity;
    }
    view = glm::lookAt(cameraPos, cameraTarget, cameraUp);
}   

void player::render(shader shader)
{
    //set view matrix
    shader.setMat4("view", view);
    
    //calculate model matrix
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(playerPosX, playerPosY, 0.0f));
    model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f,0.0f,1.0f));
    shader.setMat4("model", model);
    
    //draw sprite
    glBindVertexArray(vertexArray);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

std::tuple<int, int> player::getBlockCoordinate()
{
    int xBlock = int(playerPosX / 0.05f);
    int yBlock = int(playerPosY / 0.05f);
    std::tuple<int, int> blockCoordinate(xBlock, yBlock);
    return blockCoordinate;
}

std::tuple<int, int> player::getChunkCoordinate()
{
    std::tuple<int, int> blockCoordinate = getBlockCoordinate();
    int xChunk = int(std::get<0>(blockCoordinate) / 8.0f);
    int yChunk = int(std::get<1>(blockCoordinate) / 8.0f);
    std::tuple<int, int> chunkCoordinate(xChunk, yChunk);
    return chunkCoordinate;
}